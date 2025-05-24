#ifndef TOOLBAR_BUTTON_H
#define TOOLBAR_BUTTON_H

#include <QToolButton>

class ZToolButton : public QToolButton
{
    Q_OBJECT
public:
    explicit ZToolButton(QWidget* parent = nullptr);

    // 可扩展：添加自定义属性或方法
    void setHighlight(bool highlight);
};

#endif // TOOLBAR_BUTTON_H