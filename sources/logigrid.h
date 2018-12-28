#ifndef LOGIGRID_H
#define LOGIGRID_H

#include <QWidget>
#include <QList>
#include <QGridLayout>

#include "verticallist.h"
#include "horizontallist.h"
#include "colorframe.h"

namespace Ui {
class LogiGrid;
}

class LogiGrid : public QWidget
{
    Q_OBJECT

public:
    explicit LogiGrid(QWidget *parent = 0);
    ~LogiGrid();
    void createGrid(int columns, int rows);
    void setColumnHeader(int index, QList<int> list);
    void setRowHeader(int index, QList<int> list);

private:
    Ui::LogiGrid *ui;
    QGridLayout * m_grid;

    QList<VerticalList*> m_vList;
    QList<HorizontalList*> m_hList;

    QList<ColorFrame*> m_squares;
};

#endif // LOGIGRID_H
