#include "logigrid.h"
#include "ui_logigrid.h"

LogiGrid::LogiGrid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogiGrid)
{
    ui->setupUi(this);
    m_grid = new QGridLayout();
    m_grid->setMargin(10);
    //m_grid->setContentsMargins(0,0,0,0);
    m_grid->setHorizontalSpacing(0);
    m_grid->setVerticalSpacing(0);
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
        VerticalList * vList = new VerticalList();
        m_grid->addWidget(vList, 0, i+shift, 1, 1, Qt::AlignHCenter);
        m_vList.push_back(vList);
        if ((i+1)%5 == 0)
        {
            shift++;
            QFrame* line = new QFrame();
            line->setGeometry(0,0,2,300);
            line->setFrameShape(QFrame::VLine);
            line->setFrameShadow(QFrame::Sunken);
            m_grid->addWidget(line, 0, i+shift, 1, 1, Qt::AlignHCenter);
        }
    }
    shift = 1;
    for( int i=0; i<rows; i++) {
        HorizontalList * hList = new HorizontalList();
        m_grid->addWidget(hList, i+shift, 0);
        m_hList.push_back(hList);
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
            QFrame* hline = new QFrame();
            hline->setGeometry(0,0,2,300);
            hline->setFrameShape(QFrame::HLine);
            hline->setFrameShadow(QFrame::Sunken);
            m_grid->addWidget(hline, i+shift, 0);
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
