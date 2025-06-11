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
    explicit ZTabPage(QWidget* parent = nullptr);
    ~ZTabPage() override = default;

public:
    QPlainTextEdit* textEditor() const {
        return ui->plainTextEdit;
    }

    void openFile(const QFile& file) {

    }

private:
    Ui::ZTabPage* ui;
};

#endif // TAB_PAGE_H