#ifndef GRIDHEADER_H
#define GRIDHEADER_H

#include <QWidget>
#include <QList>

enum HeaderMode {VerticalHeader, HorizontalHeader};

class QBoxLayout;

class GridHeader : public QWidget
{
    Q_OBJECT
public:
    explicit GridHeader(HeaderMode mode, QWidget *parent = nullptr);
    void addNumber(int number);
    void setList(QList<int> list);
    const QList<int> &getList() const;
    void clearList();

private:
    void displayList();
    HeaderMode m_headerMode;
    QBoxLayout *m_layout;
    QList<int> m_list;

signals:

public slots:
};

#endif // GRIDHEADER_H
