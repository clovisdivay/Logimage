#include "colorframe.h"

#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QApplication>

ColorFrame::ColorFrame(QWidget *parent) :
    QFrame(parent)
{
    setFrameShape(QFrame::Panel);
    setFrameShadow(QFrame::Sunken);
    setLineWidth(1);
    setMinimumSize(24,24);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    setCheckState(Empty);
}

ColorFrame::~ColorFrame()
{
}

CheckState ColorFrame::checkState()
{
    return m_checkState;
}

void ColorFrame::setCheckState(CheckState state)
{
    switch (state) {
    case Filled: {
        setStyleSheet("background-color: rgb(0,0,0);");
        m_checkState = Filled;
        break;
    }
    case Crossed: {
        setStyleSheet("background-color: white; background-image: url(:/images/cross-24px.svg);");
        m_checkState = Crossed;
        break;
    }
    case Empty: {
        setStyleSheet("background-color: white;");
        m_checkState = Empty;
        break;
    }
    default:
        break;
    }

    emit checkStateChanged();
}


