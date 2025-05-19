#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "config/app_settings.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    

    readSettings();

    //connect(ui->action_N, &QAction::triggered, this, &MainWindow::OpenFile);
    connect(ui->action_O, &QAction::triggered, this, &MainWindow::OpenFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "Close Event";
    writeSettings();

    QMainWindow::closeEvent(event);
}

void MainWindow::readSettings()
{
    // 使用 AppSettings 中定义的 settings() 方法获取 QSettings 实例
    QSettings& settings = AppSettings::settings();

    // 读取保存的几何信息（位置和大小）
    const QByteArray geometry = settings.value("geometry").toByteArray();

    // 如果有保存的几何信息，则恢复它
    if (!geometry.isEmpty()) {
        restoreGeometry(geometry);
    }
    else {
        // 如果没有保存的几何信息，设置默认大小
        resize(800, 600);
    }

    // 读取保存的窗口状态（最大化、正常等）
    const QByteArray windowState = settings.value("windowState").toByteArray();
    if (!windowState.isEmpty()) {
        restoreState(windowState);
    }
}

void MainWindow::writeSettings()
{
    // 使用 AppSettings 中定义的 settings() 方法获取 QSettings 实例
    QSettings& settings = AppSettings::settings();

    // 保存窗口的几何信息（位置和大小）
    settings.setValue("geometry", saveGeometry());

    // 保存窗口的状态（最大化、正常等）
    settings.setValue("windowState", saveState());
}

void MainWindow::OpenFile()
{
    qDebug() << "OpenFile Dialog";

    QString lastOpenPath = AppSettings::lastOpenPath();

    QString fileName = QFileDialog::getOpenFileName(
        this,                         // 父窗口
        "选择文件",                    // 对话框标题
        lastOpenPath,                 // 起始目录（""表示当前目录）
        "文本文件 (*.txt);;所有文件 (*.*)"  // 文件过滤器
        );

    if (fileName.isEmpty()) {
        qDebug() << "没有选择文件";
        return;
    }

    qDebug() << "选择的文件是:" << fileName;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法打开文件");
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();
    ui->textEdit->setPlainText(content);
    file.close();

    //写入lastOpenPath
    AppSettings::setLastOpenPath(QFileInfo(fileName).absolutePath());

}
