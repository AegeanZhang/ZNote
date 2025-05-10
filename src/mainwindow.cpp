#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "config/app_settings.h"

#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect(ui->action_N, &QAction::triggered, this, &MainWindow::OpenFile);
    connect(ui->action_O, &QAction::triggered, this, &MainWindow::OpenFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenFile()
{
    qDebug() << "OpenFile Dialog";

    QString lastOpenPath = AppSettings::lastOpenPath();

    QString fileName = QFileDialog::getOpenFileName(
        this,                         // 父窗口
        "选择文件",                    // 对话框标题
        lastOpenPath,                          // 起始目录（""表示当前目录）
        "文本文件 (*.txt);;所有文件 (*.*)"  // 文件过滤器
        );

    if (!fileName.isEmpty()) {
        qDebug() << "选择的文件是:" << fileName;
    }
}
