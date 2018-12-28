#include "verticallist.h"

VerticalList::VerticalList(QWidget *parent) :
    QWidget(parent),
    NumberList()
{
    m_layout = new QVBoxLayout();
    setLayout(m_layout);
}

VerticalList::~VerticalList()
{
}

void VerticalList::setList(QList<int> list)
{
    NumberList::setList(list);
    displayList();
}

void VerticalList::displayList()
{
    m_layout->addSpacerItem(new QSpacerItem(0,1, QSizePolicy::Minimum, QSizePolicy::Expanding));
    foreach (int n, m_list) {
        QLabel *label = new QLabel(QString::number(n));
        QFont font("Arial", 12, QFont::Bold);
        label->setFont(font);
        m_layout->addWidget(label);
    }
}
