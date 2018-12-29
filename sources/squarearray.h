#ifndef SQUAREARRAY_H
#define SQUAREARRAY_H

#include <QList>
#include <QObject>

enum ArrayStatus { Pending, OK, Problem };

class ColorFrame;

class SquareArray : public QObject
{
    Q_OBJECT

public:
    SquareArray(QObject * parent = 0);

    void addSquare(ColorFrame * square);
    void setHeader(QList<int> header);
    ArrayStatus getArrayStatus();
    void fillArray();

    const QList<ColorFrame*> &getSquares();

signals:
    void arrayStatusOK();

private slots:
    void onSquareCheckStateChanged();

private:
    void checkArrayStatus();
    QList<int> m_header;
    QList<ColorFrame*> m_array;

    ArrayStatus m_arrayStatus;
};

#endif // SQUAREARRAY_H
