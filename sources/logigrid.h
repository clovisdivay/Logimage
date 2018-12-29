#ifndef LOGIGRID_H
#define LOGIGRID_H

#include <QWidget>
#include <QList>
#include <QGridLayout>

#include "colorframe.h"

class GridHeader;
class SquareArray;

class LogiGrid : public QWidget
{
    Q_OBJECT

public:
    explicit LogiGrid(QWidget *parent = 0);
    ~LogiGrid();
    void createGrid(int columns, int rows);
    void setColumnHeader(int index, QList<int> list);
    void setRowHeader(int index, QList<int> list);

private slots:
    void onSquareArrayOK();

protected:
    void mousePressEvent(QMouseEvent *me) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *me) Q_DECL_OVERRIDE;

private:
    void gameFinished();
    bool isGameFinished;
    QGridLayout * m_grid;

    QList<GridHeader*> m_vList;
    QList<GridHeader*> m_hList;

    QList<SquareArray*> m_columns;
    QList<SquareArray*> m_rows;

    CheckState m_lastCheckState;
};

#endif // LOGIGRID_H
