#include "logigrid.h"
#include "gridheader.h"
#include "squarearray.h"

#include <QDebug>
#include <QApplication>
#include <QMessageBox>

LogiGrid::LogiGrid(QWidget *parent) :
    QWidget(parent),
    m_lastCheckState(Empty),
    isGameFinished(false)
{
    m_grid = new QGridLayout();
    m_grid->setMargin(5);
//    m_grid->setContentsMargins(0,0,0,0);
    m_grid->setHorizontalSpacing(0);
    m_grid->setVerticalSpacing(0);
    m_grid->setSpacing(0);
    m_grid->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(m_grid);
}

LogiGrid::~LogiGrid()
{
}

void LogiGrid::createGrid(int columns, int rows)
{
    // Initial shift: Column 0 is for the horizontal headers
    int shift = 1;
    for( int i=0; i<columns; i++)
    {
        GridHeader * vHeader = new GridHeader(VerticalHeader);
        m_grid->addWidget(vHeader, 0, i+shift, 1, 1, Qt::AlignHCenter);
        m_vList.push_back(vHeader);

        // Draw a line every 5 column
        if ((i+1)%5 == 0)
        {
            shift++;
            QFrame* vLine = new QFrame();
            vLine->setFrameShape(QFrame::VLine);
            vLine->setFrameShadow(QFrame::Raised);
            m_grid->addWidget(vLine, 0, i+shift, 0, 1, Qt::AlignRight);
        }
    }

    // Initial shift: Row 0 is for the vertical headers
    shift = 1;
    for( int i=0; i<rows; i++)
    {
        // Header
        GridHeader * hHeader = new GridHeader(HorizontalHeader);
        m_grid->addWidget(hHeader, i+shift, 0);
        m_hList.push_back(hHeader);

        // Row
        SquareArray *row = new SquareArray();
        connect(row, SIGNAL(arrayStatusOK()), this, SLOT(onSquareArrayOK()));
        m_rows.push_back(row);

        // Initial shift
        int j_shift = 1;
        for (int j=0; j<columns; j++)
        {
            // Column
            SquareArray *column;
            if (i == 0)
            {
                column = new SquareArray();
                connect(column, SIGNAL(arrayStatusOK()), this, SLOT(onSquareArrayOK()));
                m_columns.push_back(column);
            }
            else
            {
                column = m_columns[j];
            }

            ColorFrame * square = new ColorFrame();
            m_grid->addWidget(square,i+shift, j+j_shift);

            row->addSquare(square);
            column->addSquare(square);

            // Skip the Vertical line
            if ((j+1)%5 == 0)
            {
                j_shift++;
            }
        }
        // Draw a line every 5 row
        if ((i+1)%5 == 0)
        {
            shift++;
            QFrame* hLine = new QFrame();
            hLine->setFrameShape(QFrame::HLine);
            hLine->setFrameShadow(QFrame::Raised);
            m_grid->addWidget(hLine, i+shift, 0, 1, 0, Qt::AlignVCenter);
        }
    }
}

void LogiGrid::setColumnHeader(int index, QList<int> list)
{
    m_vList[index]->setList(list);
    m_columns[index]->setHeader(list);
}

void LogiGrid::setRowHeader(int index, QList<int> list)
{
    m_hList[index]->setList(list);
    m_rows[index]->setHeader(list);
}

void LogiGrid::onSquareArrayOK()
{
    if (!isGameFinished) {
        bool finished = true;
        foreach (SquareArray * column, m_columns) {
            finished = column->getArrayStatus() == OK;
            if (finished == false)
                return;
        }
        foreach (SquareArray * row, m_rows) {
            finished = row->getArrayStatus() == OK;
            if (finished == false)
                return;
        }
        isGameFinished = true;
        gameFinished();
    }
}

void LogiGrid::gameFinished()
{

    QMessageBox::information(this, "Game finished", "Congratulations, you won!");

    QList<QWidget*> lines;
    for( int row = 1; row < m_grid->rowCount(); row++)
    {
        lines << m_grid->itemAtPosition(row, 0)->widget();
        m_grid->removeItem(m_grid->itemAtPosition(row, 0));
    }
    for( int column= 1; column < m_grid->columnCount(); column++)
    {
        lines << m_grid->itemAtPosition(0, column)->widget();
        m_grid->removeItem(m_grid->itemAtPosition(0, column));
    }
    qDeleteAll(lines);

    foreach (SquareArray * column, m_columns) {
        foreach (ColorFrame * square, column->getSquares()) {
            square->setFrameShape(QFrame::NoFrame);
            if (square->checkState() == Crossed) {
                square->setCheckState(Empty);
            }
        }
    }
}

void LogiGrid::mousePressEvent(QMouseEvent *me)
{
    if(isGameFinished) {
        me->ignore();
        return;
    }

    if (me->button() == Qt::LeftButton)
    {
        ColorFrame * square = dynamic_cast<ColorFrame*>(childAt(me->pos()));
        if (square)
        {
            m_lastCheckState = square->checkState();
            switch (m_lastCheckState) {
            case Empty: {
                square->setCheckState(Filled);
                break;
            }
            case Filled: {
                square->setCheckState(Crossed);
                break;
            }
            case Crossed: {
                square->setCheckState(Empty);
                break;
            }
            default:
                break;
            }
            m_lastCheckState = square->checkState();
        }
    }
}

void LogiGrid::mouseMoveEvent(QMouseEvent *me)
{
    if(isGameFinished) {
        me->ignore();
        return;
    }

    if(QApplication::mouseButtons() == Qt::LeftButton)
    {
        ColorFrame * square = dynamic_cast<ColorFrame*>(childAt(me->pos()));
        if (square && square->checkState() != m_lastCheckState)
        {
            square->setCheckState(m_lastCheckState);
        }
    }
}
