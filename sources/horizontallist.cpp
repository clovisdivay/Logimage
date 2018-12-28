#include "horizontallist.h"

#include <QLabel>
#include <QString>
#include <QHBoxLayout>

HorizontalList::HorizontalList(QWidget *parent) :
    QWidget(parent),
    NumberList()
{
    m_layout = new QHBoxLayout();
    setLayout(m_layout);
}

HorizontalList::~HorizontalList()
{
}

void HorizontalList::setList(QList<int> list)
{
    NumberList::setList(list);
    displayList();
}

void HorizontalList::displayList()
{
    m_layout->addSpacerItem(new QSpacerItem(1, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
    foreach (int n, m_list) {
        QLabel *label = new QLabel(QString::number(n));
        QFont font("Arial", 12, QFont::Bold);
        label->setFont(font);
        m_layout->addWidget(label);
    }
}
