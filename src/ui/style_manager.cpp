#include "style_manager.h"
#include <QFile>
#include <QDebug>

void StyleManager::loadGlobalStyle(QWidget* root, const QString& qssPath)
{
    QFile file(qssPath);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qWarning() << "Failed to load style:" << qssPath;
        return;
    }
    QString style = file.readAll();
    root->setStyleSheet(style);
}

void StyleManager::applyMinimalInputStyle(QWidget* widget)
{
    widget->setProperty("flat", true); // 可配合 QSS 控制
    widget->setStyleSheet("border: none; background: transparent;");
}