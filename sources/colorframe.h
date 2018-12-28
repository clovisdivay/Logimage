#ifndef COLORFRAME_H
#define COLORFRAME_H

#include <QWidget>
#include <QFrame>

namespace Ui {
class ColorFrame;
}

enum CheckState { Filled, Crossed, Empty };

class ColorFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ColorFrame(QWidget *parent = 0);
    ~ColorFrame();

signals:
    void myMousePressedSignal();

private slots:
    void onMousePressed();

protected:
    void mousePressEvent(QMouseEvent *me) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    Ui::ColorFrame *ui;

    CheckState m_checkState;
};

#endif // COLORFRAME_H
