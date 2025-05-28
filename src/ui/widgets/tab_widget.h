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
    void addTabWidget(QWidget* widget, const QString& label);
    // 获取指定索引的标签页小部件
    QWidget* getTabWidget(int index) const;
    // 获取所有标签页小部件
    QVector<QWidget*> getAllTabWidgets() const;

private slots:
    void closeTab(int index);

private:
    QVector<QWidget*> m_tabWidgets; // 存储所有的标签页小部件
};


#endif // TAB_WIGET_H