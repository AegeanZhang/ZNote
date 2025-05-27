#include "tab_widget.h"

ZTabWidget::ZTabWidget(QWidget* parent)
    : QTabWidget(parent)
{
    setTabsClosable(true); // 允许关闭标签页
    //connect(this, &QTabWidget::tabCloseRequested, this, &ZTabWidget::closeTab);
}

ZTabWidget::~ZTabWidget()
{

}