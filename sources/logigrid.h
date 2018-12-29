#ifndef LOGIGRID_H
#define LOGIGRID_H

#include <QWidget>
#include <QList>
#include <QGridLayout>

#include "gridheader.h"
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

protected:
    void mousePressEvent(QMouseEvent *me) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *me) Q_DECL_OVERRIDE;

private:
    Ui::LogiGrid *ui;
    QGridLayout * m_grid;

    QList<GridHeader*> m_vList;
    QList<GridHeader*> m_hList;

    QList<ColorFrame*> m_squares;

    CheckState m_lastCheckState;
};

#endif // LOGIGRID_H
