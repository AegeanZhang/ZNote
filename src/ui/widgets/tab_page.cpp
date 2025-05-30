#include "tab_page.h"

ZTabPage::ZTabPage(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::ZTabPage)
{
    ui->setupUi(this);
}