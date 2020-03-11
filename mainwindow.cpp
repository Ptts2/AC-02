#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newvehicle.h"
#include <QFont>

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

void MainWindow::on_newvehicle_button_pressed()
{
    newvehicle ventananewvehicle;
    ventananewvehicle.setModal(true);
    ventananewvehicle.exec();
}

void MainWindow::on_exit_button_pressed()
{
    exit(0);
}
