#ifndef HORIZONTALLIST_H
#define HORIZONTALLIST_H

#include <QWidget>

#include "numberlist.h"
class QHBoxLayout;
class HorizontalList : public QWidget, public NumberList
{
    Q_OBJECT

public:
    explicit HorizontalList(QWidget *parent = 0);

    ~HorizontalList();

    void setList(QList<int> list);
    void addNumber(int number);

private:
    void displayList();
    QHBoxLayout *m_layout;
};

#endif // HORIZONTALLIST_H
