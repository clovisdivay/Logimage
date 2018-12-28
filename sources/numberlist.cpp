#include "numberlist.h"

NumberList::NumberList()
{

}

void NumberList::addNumber(int number)
{
    m_list << number;
}

void NumberList::setList(QList<int> list)
{
    m_list = list;
}

const QList<int> &NumberList::getList() const
{
    return m_list;
}

void NumberList::clearList()
{
    m_list.clear();
}
