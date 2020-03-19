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
    label = new QLabel();
    label->setAutoFillBackground(true);
    QPalette pal = label->palette();
    pal.setColor(QPalette::Window, QColor(Qt::black));
    pal.setColor(QPalette::WindowText, Qt::white);

    label->setPalette(pal);
    label->setStyleSheet("font-weight: bold; color: white");
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(label);
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
    label->setText(label->text()+"\n\n"+QString::fromStdString(vehiculo.to_string()));
    count++;
    ui->numvehiculos->setText(QString::fromStdString((to_string(count))));




}
