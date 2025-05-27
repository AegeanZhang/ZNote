#include "main_window.h"
#include "./ui_main_window.h"

#include "../../config/app_settings.h"
#include "../style_manager.h"
#include "../widgets/tool_button.h"
#include "../dialogs/about_dialog.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QFontDialog>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    readSettings();

    setupMainWindow();
    setConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupMainWindow()
{
    // 应用全局样式
    StyleManager::loadGlobalStyle(this, ":/ZNote/styles/style.qss");

    // 设置窗口标题
    setWindowTitle("ZNote");
    setWindowIcon(QIcon(":/ZNote/icons/main_icon.png"));

    // 添加已有的 QAction 到工具栏
    ZToolButton* openButton = new ZToolButton(this);
    //openButton->setText("自定义");
    openButton->setIcon(QIcon(":/ZNote/icons/toolbar_setting.png"));
    ui->toolBar->addWidget(openButton);     // 打开文件
    ui->toolBar->addSeparator();   

    setupWorkArea();
}

void MainWindow::setupWorkArea()
{
    // 在这里添加工作区初始化相关代码
    ui->splitter->setStretchFactor(1, 6); // 设置左侧编辑器占据剩余空间


    /*QFont font("微软雅黑", 12); // 或 QFont("Lucida Console", 10);
    ui->plainTextEdit->setFont(font);*/

    //QFont font("Microsoft YaHei", 12);
    /*QFont font = AppSettings::editorFont();
    font.setStyleStrategy(QFont::PreferAntialias);
    ui->plainTextEdit->setFont(font);
    //ui->plainTextEdit->setAcceptRichText(false);
    //ui->plainTextEdit->setStyleSheet("QplainTextEdit { line-height: 1.5; }");
    ui->plainTextEdit->setStyleSheet("QplainTextEdit { line-height: 5; }");*/
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

void MainWindow::setConnections()
{
    connect(ui->action_N, &QAction::triggered, this, &MainWindow::newFile);
    connect(ui->action_O, &QAction::triggered, this, &MainWindow::OpenFile);
    connect(ui->action_X, &QAction::triggered, this, &MainWindow::Exit);
    connect(ui->action_F_2, &QAction::triggered, this, &MainWindow::selectFont);

    connect(ui->action_A_3, &QAction::triggered, this, &MainWindow::aboutDialog);
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

    /*QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法打开文件");
        return;
    }

    ui->plainTextEdit->clear(); // 清空文本编辑器

    // 使用 QFile 直接读取文件内容，避免 QTextStream 的编码问题
    QByteArray fileData = file.readAll();
    QString content = QString::fromUtf8(fileData); // 使用 UTF-8 编码读取文件内容
    ui->plainTextEdit->setPlainText(content);
    file.close();
    */
    //写入lastOpenPath
    AppSettings::setLastOpenPath(QFileInfo(fileName).absolutePath());

}

void MainWindow::newFile()
{
    // 创建一个标签页
    ui->tabWidget->addTabWidget(new QWidget(), "新建文件");
}

void MainWindow::Exit()
{
    close();
}

void MainWindow::selectFont()
{
    /*bool ok;
    QFont currentFont = ui->plainTextEdit->font();  // 获取当前使用的字体
    QFont font = QFontDialog::getFont(&ok, currentFont, this);
    if (ok) {
        // 用户选择了字体并点击了"确定"
        ui->plainTextEdit->setFont(font);

        // 保存字体设置
        AppSettings::setEditorFont(font);
    }
    */
}

void MainWindow::on_action_O_triggered()
{
    qDebug() << "Open File Triggered, on automatic connection.";
}

void MainWindow::aboutDialog()
{
    ZAboutDialog* aboutDialog = new ZAboutDialog(this);
    aboutDialog->setVersion("1.0.0");

    // 显示对话框
    aboutDialog->exec();
}