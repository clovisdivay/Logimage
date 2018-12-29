#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Clogimage");
    buildClef();
//    buildHeart();
//    ui->gridWidget->createGrid(6,6);
//    ui->gridWidget->setColumnHeader(0,QList<int>() << 2);
//    ui->gridWidget->setColumnHeader(1,QList<int>() << 2);
//    ui->gridWidget->setColumnHeader(2,QList<int>() << 6);
//    ui->gridWidget->setColumnHeader(3,QList<int>() << 6);
//    ui->gridWidget->setColumnHeader(4,QList<int>() << 2);
//    ui->gridWidget->setColumnHeader(5,QList<int>() << 2);

//    ui->gridWidget->setRowHeader(0,QList<int>() << 2);
//    ui->gridWidget->setRowHeader(1,QList<int>() << 2);
//    ui->gridWidget->setRowHeader(2,QList<int>() << 6);
//    ui->gridWidget->setRowHeader(3,QList<int>() << 6);
//    ui->gridWidget->setRowHeader(4,QList<int>() << 2);
//    ui->gridWidget->setRowHeader(5,QList<int>() << 2);
    layout()->setSizeConstraint(QLayout::SetFixedSize);
    ui->statusBar->setSizeGripEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buildClef()
{
    ui->gridWidget->createGrid(9,20);
    ui->gridWidget->setColumnHeader(0,QList<int>() << 5);
    ui->gridWidget->setColumnHeader(1,QList<int>() << 7);
    ui->gridWidget->setColumnHeader(2,QList<int>() << 2 << 2);
    ui->gridWidget->setColumnHeader(3,QList<int>() << 1 << 2 << 1 << 1);
    ui->gridWidget->setColumnHeader(4,QList<int>() << 20);
    ui->gridWidget->setColumnHeader(5,QList<int>() << 3 << 1 << 1 << 1);
    ui->gridWidget->setColumnHeader(6,QList<int>() << 5 << 2 << 2);
    ui->gridWidget->setColumnHeader(7,QList<int>() << 5);
    ui->gridWidget->setColumnHeader(8,QList<int>() << 3);

    ui->gridWidget->setRowHeader(0,QList<int>() << 1);
    ui->gridWidget->setRowHeader(1,QList<int>() << 2);
    ui->gridWidget->setRowHeader(2,QList<int>() << 3);
    ui->gridWidget->setRowHeader(3,QList<int>() << 3);
    ui->gridWidget->setRowHeader(4,QList<int>() << 1 << 1);
    ui->gridWidget->setRowHeader(5,QList<int>() << 1 << 1);
    ui->gridWidget->setRowHeader(6,QList<int>() << 1 << 1);
    ui->gridWidget->setRowHeader(7,QList<int>() << 2);
    ui->gridWidget->setRowHeader(8,QList<int>() << 3);
    ui->gridWidget->setRowHeader(9,QList<int>() << 2 << 1);
    ui->gridWidget->setRowHeader(10,QList<int>() << 2 << 3);
    ui->gridWidget->setRowHeader(11,QList<int>() << 2 << 2 << 2);
    ui->gridWidget->setRowHeader(12,QList<int>() << 2 << 2 << 2);
    ui->gridWidget->setRowHeader(13,QList<int>() << 2 << 1 << 2);
    ui->gridWidget->setRowHeader(14,QList<int>() << 2 << 1 << 2);
    ui->gridWidget->setRowHeader(15,QList<int>() << 2 << 1 << 2);
    ui->gridWidget->setRowHeader(16,QList<int>() << 5);
    ui->gridWidget->setRowHeader(17,QList<int>() << 1);
    ui->gridWidget->setRowHeader(18,QList<int>() << 1);
    ui->gridWidget->setRowHeader(19,QList<int>() << 2);
}

void MainWindow::buildHeart()
{
    ui->gridWidget->createGrid(13,12);
    ui->gridWidget->setColumnHeader(0,QList<int>() << 4);
    ui->gridWidget->setColumnHeader(1,QList<int>() << 6);
    ui->gridWidget->setColumnHeader(2,QList<int>() << 8);
    ui->gridWidget->setColumnHeader(3,QList<int>() << 9);
    ui->gridWidget->setColumnHeader(4,QList<int>() << 10);
    ui->gridWidget->setColumnHeader(5,QList<int>() << 10);
    ui->gridWidget->setColumnHeader(6,QList<int>() << 10);
    ui->gridWidget->setColumnHeader(7,QList<int>() << 10);
    ui->gridWidget->setColumnHeader(8,QList<int>() << 10);
    ui->gridWidget->setColumnHeader(9,QList<int>() << 9);
    ui->gridWidget->setColumnHeader(10,QList<int>() << 8);
    ui->gridWidget->setColumnHeader(11,QList<int>() << 6);
    ui->gridWidget->setColumnHeader(12,QList<int>() << 4);

    ui->gridWidget->setRowHeader(0,QList<int>() << 3 << 3);
    ui->gridWidget->setRowHeader(1,QList<int>() << 5 << 5);
    ui->gridWidget->setRowHeader(2,QList<int>() << 13);
    ui->gridWidget->setRowHeader(3,QList<int>() << 13);
    ui->gridWidget->setRowHeader(4,QList<int>() << 13);
    ui->gridWidget->setRowHeader(5,QList<int>() << 13);
    ui->gridWidget->setRowHeader(6,QList<int>() << 11);
    ui->gridWidget->setRowHeader(7,QList<int>() << 9);
    ui->gridWidget->setRowHeader(8,QList<int>() << 7);
    ui->gridWidget->setRowHeader(9,QList<int>() << 5);
    ui->gridWidget->setRowHeader(10,QList<int>() << 3);
    ui->gridWidget->setRowHeader(11,QList<int>() << 1);
}
