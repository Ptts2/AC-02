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

    ui->scrollArea->setWidget(ui->verticalLayout->widget());
    QLabel *label = new QLabel(QString::fromStdString(vehiculo.to_string()));
    label->setFixedSize(1000,50);
    label->setAutoFillBackground(true);
    QPalette pal = label->palette();
    pal.setColor(QPalette::Window, QColor(Qt::yellow));
    label->setPalette(pal);
    ui->verticalLayout->addWidget(label);


}
