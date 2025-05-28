#ifndef TAB_PAGE_H
#define TAB_PAGE_H

#include "ui_tab_page.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
    class ZTabPage;
}
QT_END_NAMESPACE

class ZTabPage : public QWidget
{
    Q_OBJECT
public:
    explicit ZTabPage(QWidget* parent = nullptr)
        : QWidget(parent)
        , ui(new Ui::ZTabPage)
    {
        ui->setupUi(this);
    }
    ~ZTabPage() override = default;

private:
    Ui::ZTabPage* ui;
};

#endif // TAB_PAGE_H