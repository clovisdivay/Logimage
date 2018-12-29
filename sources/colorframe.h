#ifndef COLORFRAME_H
#define COLORFRAME_H

#include <QWidget>
#include <QFrame>

enum CheckState {Empty, Filled, Crossed};

class ColorFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ColorFrame(QWidget *parent = 0);
    ~ColorFrame();
    CheckState checkState();
    void setCheckState(CheckState state);

signals:
    void checkStateChanged();

private:
    CheckState m_checkState;
};

#endif // COLORFRAME_H
