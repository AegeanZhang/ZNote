#ifndef TAB_PAGE_H
#define TAB_PAGE_H

#include <QWidget>

class ZTabPage : public QWidget
{
    Q_OBJECT
public:
    explicit ZTabPage(QWidget* parent = nullptr)
        : QWidget(parent)
    {

    }
    ~ZTabPage() override = default;
};

#endif // TAB_PAGE_H