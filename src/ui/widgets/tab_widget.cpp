#include "tab_widget.h"
#include "tab_page.h"

#include <QMessageBox>
#include <QFileInfo>
#include <QStringDecoder>

#include <unicode/ucsdet.h> // ICU 检测头文件

ZTabWidget::ZTabWidget(QWidget* parent)
    : QTabWidget(parent)
{
    setTabsClosable(true); // 允许关闭标签页
    connect(this, &QTabWidget::tabCloseRequested, this, &ZTabWidget::closeTab);
}

ZTabWidget::~ZTabWidget()
{

}

void ZTabWidget::addTabWidget(QWidget* widget, const QString& label)
{
    this->addTab(widget, label);
    setCurrentWidget(widget); // 设置当前标签页为新添加的标签页
}

void ZTabWidget::addTabWidget(QWidget* widget, QFile& file)
{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法打开文件");
        return;
    }

    // 读取全部数据
    QByteArray fileData = file.readAll();

    // 使用 ICU 检测编码
    UErrorCode status = U_ZERO_ERROR;
    UCharsetDetector* csd = ucsdet_open(&status);
    ucsdet_setText(csd, fileData.constData(), fileData.size(), &status);
    const UCharsetMatch* match = ucsdet_detect(csd, &status);

    QString encoding = "UTF-8"; // 默认编码
    if (U_SUCCESS(status) && match) {
        encoding = QString::fromUtf8(ucsdet_getName(match, &status));
    }
    ucsdet_close(csd);

    // 根据检测到的编码转换内容
    QString content;
    if (encoding.compare("UTF-8", Qt::CaseInsensitive) == 0) {
        content = QString::fromUtf8(fileData);
    }
    else if (encoding.compare("GB18030", Qt::CaseInsensitive) == 0 ||
        encoding.compare("GBK", Qt::CaseInsensitive) == 0 ||
        encoding.compare("GB2312", Qt::CaseInsensitive) == 0) {
        content = QString::fromLocal8Bit(fileData);
    }
    else {
        // Qt6: 使用 QStringDecoder
        QStringDecoder decoder(encoding.toUtf8());
        content = decoder(fileData);
    }

    ZTabPage *tabPage = (ZTabPage*)widget;

    this->addTabWidget(tabPage, QFileInfo(file).fileName()); // 添加新标签页

    tabPage->textEditor()->clear(); // 清空文本编辑器
    tabPage->textEditor()->setPlainText(content);
    file.close();
}

void ZTabWidget::closeTab(int index)
{
    QWidget* widget = this->widget(index);
    if (widget) {
        removeTab(index);
        widget->deleteLater(); // 安全释放内存
    }
}