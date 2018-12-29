#include "gridheader.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

GridHeader::GridHeader(HeaderMode mode, QWidget *parent) : QWidget(parent)
{
    if (mode == VerticalHeader)
        m_layout = new QVBoxLayout();
    else if (mode == HorizontalHeader)
        m_layout = new QHBoxLayout();

    m_layout->setMargin(0);
    setLayout(m_layout);
}

void GridHeader::addNumber(int number)
{
    m_list << number;
}

void GridHeader::setList(QList<int> list)
{
    m_list = list;
    displayList();
}

const QList<int> &GridHeader::getList() const
{
    return m_list;
}

void GridHeader::clearList()
{
    m_list.clear();
}

void GridHeader::displayList()
{
    m_layout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Expanding));

    foreach (int n, m_list) {
        QLabel *label = new QLabel(QString::number(n));
        QFont font("Arial", 10, QFont::Bold);
        label->setFont(font);
        m_layout->addWidget(label);
    }

    if (m_headerMode== HorizontalHeader)
        m_layout->addSpacerItem(new QSpacerItem(5, 1, QSizePolicy::Fixed, QSizePolicy::Fixed));
}
