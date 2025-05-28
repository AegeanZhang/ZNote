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

void ZTabWidget::addTabWidget(QWidget* widget, const QString& label)
{
    m_tabWidgets.append(widget);
    this->addTab(widget, label);
    setCurrentWidget(widget); // 设置当前标签页为新添加的标签页
    //connect(m_tabWidgets.indexOf(widget), &QTabWidget::tabCloseRequested, this, &ZTabWidget::closeTab);
}
// 获取指定索引的标签页小部件
QWidget* ZTabWidget::getTabWidget(int index) const
{
    if (index >= 0 && index < m_tabWidgets.size()) {
        return m_tabWidgets.at(index);
    }
    return nullptr;
}
// 获取所有标签页小部件
QVector<QWidget*> ZTabWidget::getAllTabWidgets() const
{
    return m_tabWidgets;
}

void ZTabWidget::closeTab(int index)
{
    QWidget* widget = getTabWidget(index);
    if (widget) {
        m_tabWidgets.remove(index);
        removeTab(index);
        widget->deleteLater();
    }
}