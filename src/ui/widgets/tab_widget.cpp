#include "tab_widget.h"

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

void ZTabWidget::closeTab(int index)
{
    QWidget* widget = this->widget(index);
    if (widget) {
        removeTab(index);
        widget->deleteLater(); // 安全释放内存
    }
}