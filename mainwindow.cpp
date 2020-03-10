#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newvehicle.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_verticalScrollBar_sliderMoved(int position)
{

}

void MainWindow::on_pushButton_pressed()
{
    newvehicle ventananewvehicle;
    ventananewvehicle.setModal(true);
    ventananewvehicle.exec();
}

void MainWindow::on_pushButton_2_pressed()
{
    exit(0);
}
