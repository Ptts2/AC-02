#include "newvehicle.h"
#include "ui_newvehicle.h"
#include <QFont>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

newvehicle::newvehicle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newvehicle)
{
  ui->setupUi(this);

    ui->fueltype_label->hide();
    ui->fuel_select->hide();
    ui->pow_label->hide();
    ui->pow_slider->hide();
    ui->pow_num_slider_label->hide();
    ui->wagon_num_label->hide();
    ui->wagon_num_slider->hide();
    ui->wagon_num_slider_label->hide();

}

newvehicle::~newvehicle()
{
    delete ui;
}

void newvehicle::on_CANCEL_pressed()
{
    this->close();
}

void newvehicle::on_CREATE_pressed()
{

}


void newvehicle::on_matricula_button_pressed()
{
    const string letrasPosibles = "BCDFGHIJKLMNPQRSTVWXYZ";
    srand(time(NULL));
    int num = rand() % 10000;

    stringstream numStringStream;
    numStringStream << setfill('0') << setw(4) << num;
    string numString = numStringStream.str();

    string letras;
    string matricula ="";
    int rand1= rand() % 22;
    int rand2= rand() % 22;
    int rand3= rand() % 22;

    letras = letrasPosibles[rand1];
    letras += letrasPosibles[rand2];
    letras += letrasPosibles[rand3];

    matricula = numString+" "+letras;
    ui->matricula_label->setText(QString::fromStdString(matricula));

}
