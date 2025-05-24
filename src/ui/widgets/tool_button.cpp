#include "tool_button.h"

ZToolButton::ZToolButton(QWidget* parent)
    : QToolButton(parent)
{
    // 设置默认样式
    //setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    setToolButtonStyle(Qt::ToolButtonIconOnly);
    setMinimumSize(40, 40);
}

void ZToolButton::setHighlight(bool highlight)
{
    if (highlight) {
        setStyleSheet("background: #ffe082;");
    }
    else {
        setStyleSheet("");
    }
}