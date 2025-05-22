#ifndef APP_SETTINGS_H
#define APP_SETTINGS_H

#include <QSettings>
#include <QDir>
#include <QFont>

class AppSettings{
public:
    // 获取最近打开路径
    static inline QString lastOpenPath() {
        return settings().value("lastOpenPath", QDir::homePath()).toString();
    }

    static inline void setLastOpenPath(const QString& path) {
        settings().setValue("lastOpenPath", path);
    }

    // 获取编辑器字体
    static inline QFont editorFont() {
        QFont defaultFont("Microsoft YaHei", 12);
        defaultFont.setStyleStrategy(QFont::PreferAntialias);

        if (settings().contains("editorFont")) {
            QFont font;
            font.fromString(settings().value("editorFont").toString());
            return font;
        }
        return defaultFont;
    }

    // 设置编辑器字体
    static inline void setEditorFont(const QFont& font) {
        settings().setValue("editorFont", font.toString());
    }

public:
    // 内部获取唯一 QSettings 实例（惰性初始化）
    static inline QSettings& settings() {
        static QSettings s("TingYu", "ZNote");
        return s;
    }
};

#endif // APP_SETTINGS_H
