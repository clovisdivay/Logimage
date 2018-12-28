#ifndef VERTICALLIST_H
#define VERTICALLIST_H

#include <QVBoxLayout>
#include <QWidget>

#include "numberlist.h"

class VerticalList : public QWidget, public NumberList
{
    Q_OBJECT

public:
    explicit VerticalList(QWidget *parent = 0);
    ~VerticalList();

    void setList(QList<int> list);
    void addNumber(int number);

private:
    void displayList();
    QVBoxLayout *m_layout;
};

#endif // VERTICALLIST_H
