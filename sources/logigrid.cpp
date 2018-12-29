#include "logigrid.h"
#include "ui_logigrid.h"

#include <QDebug>
#include <QApplication>

LogiGrid::LogiGrid(QWidget *parent) :
    QWidget(parent),
    m_lastCheckState(Empty),
    ui(new Ui::LogiGrid)
{
    ui->setupUi(this);
    m_grid = new QGridLayout();
    m_grid->setMargin(5);
    m_grid->setHorizontalSpacing(0);
    m_grid->setVerticalSpacing(0);
    m_grid->setSpacing(0);
    setLayout(m_grid);
}

LogiGrid::~LogiGrid()
{
    delete ui;
}

void LogiGrid::createGrid(int columns, int rows)
{
    int shift = 1;

    for( int i=0; i<columns; i++) {
        GridHeader * vHeader = new GridHeader(VerticalHeader);
        m_grid->addWidget(vHeader, 0, i+shift, 1, 1, Qt::AlignHCenter);
        m_vList.push_back(vHeader);
        if ((i+1)%5 == 0)
        {
            shift++;
            QFrame* vLine = new QFrame();
            vLine->setFrameShape(QFrame::VLine);
            vLine->setFrameShadow(QFrame::Raised);
            m_grid->addWidget(vLine, 0, i+shift, 0, 1, Qt::AlignRight);
        }
    }
    shift = 1;
    for( int i=0; i<rows; i++) {
        GridHeader * hHeader = new GridHeader(HorizontalHeader);
        m_grid->addWidget(hHeader, i+shift, 0);
        m_hList.push_back(hHeader);
        int j_shift = 1;
        for (int j=0; j<columns; j++) {
            ColorFrame * square = new ColorFrame();
            m_grid->addWidget(square,i+shift, j+j_shift);
            m_squares.push_back(square);
            if ((j+1)%5 == 0)
            {
                j_shift++;
            }
        }
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
}

void LogiGrid::setRowHeader(int index, QList<int> list)
{
    m_hList[index]->setList(list);
}

void LogiGrid::mousePressEvent(QMouseEvent *me)
{
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
    if(QApplication::mouseButtons() == Qt::LeftButton)
    {
        ColorFrame * square = dynamic_cast<ColorFrame*>(childAt(me->pos()));
        if (square && square->checkState() != m_lastCheckState)
        {
            square->setCheckState(m_lastCheckState);
        }
    }
}
