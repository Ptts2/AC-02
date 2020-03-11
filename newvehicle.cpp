#include "newvehicle.h"
#include "ui_newvehicle.h"

newvehicle::newvehicle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newvehicle)
{
    ui->setupUi(this);
    ui->label_9->hide();
    ui->Combocombustible->hide();
    ui->potencia->hide();
    ui->potenciabar->hide();
    ui->potencianum->hide();
    ui->numvagones->hide();
    ui->numvagonesbar->hide();
    ui->numvagonesnum->hide();
}

newvehicle::~newvehicle()
{
    delete ui;
}

void newvehicle::on_pushButton_2_pressed()
{
    this->close();
}

void newvehicle::on_pushButton_pressed()
{

}

