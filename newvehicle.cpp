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

    string wheelnumsWithOtherChars = ui->wheelnum_select->currentText().toUtf8().constData();
    if(
            (!ui->name_input->isModified()) ||
            (wheelnumsWithOtherChars == "")  ||
            ((string) ui->color_select->currentText().toUtf8().constData() == "") ||
            (ui->motor_button_yes->isChecked()? false: !ui->motor_button_no->isChecked()) ||
            (ui->wings_button_yes->isChecked()? false: !ui->wings_button_no->isChecked()) ||
            (ui->reactors_button_yes->isChecked()? false: !ui->reactors_button_no->isChecked()) ||
            (ui->tren_button_yes->isChecked()? false: !ui->tren_button_no->isChecked()) ||
            (ui->locom_button_yes->isChecked()? false: !ui->locom_button_no->isChecked()) ||
            ((string) ui->extra_select->currentText().toUtf8().constData() == "")||
            (ui->fuel_check->isChecked()?((string) ui->fuel_select->currentText().toUtf8().constData() == ""):false)||
            ((string)ui->matricula_label->text().toUtf8().constData() == "")
        )
    {

    QMessageBox messageBox;
    messageBox.critical(this,"Error","Introduce los datos correctamente!");
    messageBox.setFixedSize(500,200);

    }
    else
    {

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
    if(vehiculo.getTipo() == "ERROR")
    {
        QMessageBox messageBox;
        messageBox.critical(this,"Error","Tipo de vehiculo no reconocido.");
        messageBox.setFixedSize(500,200);
    }else
    {
    MainWindow *padre =(MainWindow*)parent;
    padre->MainWindow::addVehicle(vehiculo);
    this->close();
    }
    }
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
