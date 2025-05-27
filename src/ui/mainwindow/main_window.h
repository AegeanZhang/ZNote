#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Qmenu>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    // setup the main window
    void setupMainWindow();
    void setupWorkArea(); 
    void closeEvent(QCloseEvent *event) override;

private:
    void readSettings();
    void writeSettings();

    void setConnections();

private slots:
    void OpenFile();
    void newFile();
    void Exit();
    void selectFont();
    void aboutDialog();

    // 自动连接的槽函数, 测试用的后面删除
    void on_action_O_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
