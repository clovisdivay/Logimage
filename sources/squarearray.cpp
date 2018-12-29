#include "squarearray.h"
#include "colorframe.h"

#include <vector>

SquareArray::SquareArray(QObject *parent)
    : QObject(parent),
      m_arrayStatus(Pending)
{

}

void SquareArray::addSquare(ColorFrame *square)
{
    m_array.push_back(square);
    connect(square, SIGNAL(checkStateChanged()), this, SLOT(onSquareCheckStateChanged()));
}

void SquareArray::setHeader(QList<int> header)
{
    m_header = header;
}

ArrayStatus SquareArray::getArrayStatus()
{
    return m_arrayStatus;
}

const QList<ColorFrame *> &SquareArray::getSquares()
{
    return m_array;
}

void SquareArray::onSquareCheckStateChanged()
{
    checkArrayStatus();
}

void SquareArray::checkArrayStatus()
{
    int totalHeader = 0;
    foreach (int block, m_header) {
        totalHeader += block;
    }

    QList<int> blocks;

    int blockSize = 0;
    int nFilledSquares = 0;
    foreach (ColorFrame *square, m_array)
    {
        if (square->checkState() == Filled)
        {
            blockSize++;
            nFilledSquares++;
            if (nFilledSquares > totalHeader)
            {
                m_arrayStatus = Problem;
                return;
            }
        }
        else if (blockSize !=0)
        {
            blocks.push_back(blockSize);
            blockSize = 0;
        }
    }

    if (nFilledSquares == totalHeader) {
        m_arrayStatus = OK;
        emit arrayStatusOK();
    }
    else
        m_arrayStatus = Pending;
}
