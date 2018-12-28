#include "colorframe.h"
#include "ui_colorframe.h"

#include <QMouseEvent>
#include <QPainter>

ColorFrame::ColorFrame(QWidget *parent) :
    QFrame(parent),
    m_checkState(Empty),
    ui(new Ui::ColorFrame)
{
    ui->setupUi(this);
    ui->frame->setStyleSheet("background-color: rgb(255,255,255);");

    connect(this, SIGNAL(myMousePressedSignal()), this, SLOT(onMousePressed()));
}

ColorFrame::~ColorFrame()
{
    delete ui;
}

void ColorFrame::onMousePressed()
{
    switch (m_checkState) {
    case Empty: {
        ui->frame->setStyleSheet("background-color: rgb(0,0,0);");
        m_checkState = Filled;
        break;
    }
    case Filled: {
        ui->frame->setStyleSheet("background-color: rgb(200,200,200);");
        m_checkState = Crossed;
        break;
    }
    case Crossed: {
        ui->frame->setStyleSheet("background-color: rgb(255,255,255);");
        m_checkState = Empty;
        break;
    }
    default:
        break;
    }
}

void ColorFrame::mousePressEvent(QMouseEvent *me)
{
    if (me->button() == Qt::LeftButton)
    {
        emit(myMousePressedSignal());
        // here you shoud remember click event...
        me->accept();
        return;
    }

    QFrame::mousePressEvent(me);
}

void ColorFrame::paintEvent(QPaintEvent *event)
{
    /*if (m_checkState == Crossed)
    {
        QPainter painter(ui->frame);
        painter.setPen(Qt::black);
        painter.drawLine(0, 0, 100, 100);
    }*/
    QFrame::paintEvent(event);
}
