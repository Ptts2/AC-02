#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newvehicle.h"
#include <QFont>
#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->count = 0;
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newvehicle_button_pressed()
{
    newvehicle ventananewvehicle(this);
    ventananewvehicle.setModal(true);
    ventananewvehicle.exec();
}

void MainWindow::on_exit_button_pressed()
{
    exit(0);
}

void MainWindow::addVehicle(Vehiculo vehiculo)
{

    coches.push_back(vehiculo);
    QLabel *label = new QLabel(QString::fromStdString(vehiculo.to_string()));
    label->setFixedSize(1000,50);
    label->setAutoFillBackground(true);
    QPalette pal = label->palette();
    pal.setColor(QPalette::Window, QColor(Qt::yellow));
    label->setPalette(pal);
    ui->verticalLayout->addWidget(label);
    count++;
    ui->numvehiculos->setText(QString::fromStdString((to_string(count))));




}
