#ifndef STYLEMANAGER_H
#define STYLEMANAGER_H

#include <QWidget>
#include <QString>

class StyleManager
{
public:
    // 全局加载 QSS
    static void loadGlobalStyle(QWidget* root, const QString& qssPath);

    // 应用于简洁输入框
    static void applyMinimalInputStyle(QWidget* widget);

    // 添加其他样式配置接口...
};

#endif // STYLEMANAGER_H#pragma once
