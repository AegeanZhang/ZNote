#ifndef APP_SETTINGS_H
#define APP_SETTINGS_H

#include <QSettings>
#include <QDir>

class AppSettings{
public:
    // 获取最近打开路径
    static inline QString lastOpenPath() {
        return settings().value("lastOpenPath", QDir::homePath()).toString();
    }

public:
    // 内部获取唯一 QSettings 实例（惰性初始化）
    static inline QSettings& settings() {
        static QSettings s("TingYu", "ZNote");
        return s;
    }
};

#endif // APP_SETTINGS_H
