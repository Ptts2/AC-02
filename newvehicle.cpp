#include "newvehicle.h"
#include "vehiculo.h"
#include "ui_newvehicle.h"
#include "mainwindow.h"
#include <QFont>
#include <QMessageBox>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <regex>


using namespace std;

newvehicle::newvehicle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newvehicle)
{
  ui->setupUi(this);

    this->parent = parent;
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

    /*
    QMessageBox messageBox;
    messageBox.critical(this,"Error","An error has occured !");
    messageBox.setFixedSize(500,200);
    */

    string wheelnumsWithOtherChars = ui->wheelnum_select->currentText().toUtf8().constData();
    string wheelNums = regex_replace(wheelnumsWithOtherChars, std::regex(R"([\D])"), "");
    Vehiculo vehiculo( ui->name_input->text().toUtf8().constData(),
                       stoi(wheelNums),
                       ui->motor_button_yes->isChecked(),
                       ui->motor_button_yes->isChecked()? ui->pow_slider->value():0,
                       ui->fuel_check->isChecked(),
                       ui->fuel_check->isChecked()? ui->fuel_select->currentText().toUtf8().constData():"NO_FUEL",
                       ui->color_select->currentText().toUtf8().constData(),
                       ui->wings_button_yes->isChecked(),
                       ui->reactors_button_yes->isChecked(),
                       ui->tren_button_yes->isChecked(),
                       ui->locom_button_yes->isChecked(),
                       ui->wagon_check->isChecked(),
                       ui->wagon_check->isChecked() ? ui->wagon_num_slider->value():0,
                       ui->extra_select->currentIndex(),
                       ui->matricula_label->text().toUtf8().constData()
                       );
    MainWindow *padre =(MainWindow*)parent;
    padre->MainWindow::addVehicle(vehiculo);

    this->close();
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
