#ifndef TAB_WIGET_H
#define TAB_WIGET_H

#include <QTabWidget>

class ZTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit ZTabWidget(QWidget* parent = nullptr);
    ~ZTabWidget();

public:
    // 添加一个新的标签页
    void addTabWidget(QWidget* widget, const QString& label)
    {
        m_tabWidgets.append(widget);
        this->addTab(widget, label);
        setCurrentWidget(widget); // 设置当前标签页为新添加的标签页
        //connect(m_tabWidgets.indexOf(widget), &QTabWidget::tabCloseRequested, this, &ZTabWidget::closeTab);
    }
    // 获取指定索引的标签页小部件
    QWidget* getTabWidget(int index) const
    {
        if (index >= 0 && index < m_tabWidgets.size()) {
            return m_tabWidgets.at(index);
        }
        return nullptr;
    }
    // 获取所有标签页小部件
    QVector<QWidget*> getAllTabWidgets() const
    {
        return m_tabWidgets;
    }

private slots:
    void closeTab(int index)
    {
        QWidget* widget = getTabWidget(index);
        if (widget) {
            m_tabWidgets.remove(index);
            removeTab(index);
            widget->deleteLater();
        }
    }

private:
    QVector<QWidget*> m_tabWidgets; // 存储所有的标签页小部件
};


#endif // TAB_WIGET_H