#ifndef ZTEXTEDITOR_H
#define ZTEXTEDITOR_H

#include <QPlainTextEdit>

class ZTextEditor  : public QPlainTextEdit
{
    Q_OBJECT

public:
    ZTextEditor(QWidget *parent);
    ~ZTextEditor();
};

#endif // ZTEXTEDITOR_H