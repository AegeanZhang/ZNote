#include "about_dialog.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

ZAboutDialog::ZAboutDialog(QWidget* parent) 
{
    // 大小不可调整
    setFixedSize(400, 300);

    // 设置窗口标题
    setWindowTitle(tr("关于 \"ZNote\""));
    // 禁用icon
    setWindowFlags(Qt::Dialog | Qt::WindowTitleHint 
            | Qt::WindowCloseButtonHint | Qt::CustomizeWindowHint);
    setWindowIcon(QIcon());

    /*
     * ---------------------------------
     * |         icon ZNote            |
     * |                               |
     * |           分隔线               |
     * |                               |
     * |          Znote简介             |
     * |                               |
     * |                       确定按钮  |
     * ---------------------------------
     */
    QLayout* layout = new QVBoxLayout(this);
    layout->setContentsMargins(10, 10, 10, 10);
    setLayout(layout);

    // 增加一个Label
    QLabel* label = new QLabel(this);
    label->setText(tr("ZNote 是一个简单的文本编辑器，支持多种语言的语法高亮显示。"));

    layout->addWidget(label);

    // 添加一个确定按钮
    QPushButton* btn = new QPushButton(tr("确定"), this);
    btn->setFixedSize(80, 30);

    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->addStretch();      // 弹性空间，将按钮推到最右侧
    btnLayout->addWidget(btn);

    layout->addItem(btnLayout);   // 将按钮布局添加到主垂直布局

    connect(btn, &QPushButton::clicked, this, &ZAboutDialog::btnOkClicked);
}

ZAboutDialog::~ZAboutDialog() 
{

}

void ZAboutDialog::setVersion(const QString& version)
{
}

void ZAboutDialog::setAuthor(const QString& author)
{
}

void ZAboutDialog::setLicense(const QString& license)
{
}

void ZAboutDialog::setDescription(const QString& description)
{
}

void ZAboutDialog::setLogo(const QString& logoPath)
{
}

void ZAboutDialog::setIcon(const QString& iconPath)
{
}

void ZAboutDialog::setWebsite(const QString& website)
{
}

void ZAboutDialog::setEmail(const QString& email)
{
}

void ZAboutDialog::setGithub(const QString& github)
{
}

void ZAboutDialog::btnOkClicked()
{
    close();
}