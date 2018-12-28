#ifndef NUMBERLIST_H
#define NUMBERLIST_H


#include <QLabel>
#include <QList>
#include <QStringList>

class NumberList
{
public:
    NumberList();
    void addNumber(int number);
    void setList(QList<int> list);
    const QList<int> &getList() const;
    void clearList();

protected:
    QList<int> m_list;
};

#endif // NUMBERLIST_H
