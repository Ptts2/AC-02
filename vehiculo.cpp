#include "vehiculo.h"

Vehiculo::Vehiculo(){}
Vehiculo::~Vehiculo(){}
Vehiculo::Vehiculo(string nombre, int wheelNum, bool motor, int motorPow, bool fuel, string fuelType, string color, bool wings, bool reactors, bool undercarriage, bool locomotive, bool wagons, int extra, string matricula)
{
    this->nombre = nombre;
    this->wheelNum = wheelNum;
    this->motor = motor;
    this->motorPow = motorPow;
    this->fuel = fuel;
    this->fuelType = fuelType;
    this->color = color;
    this->wings = wings;
    this->reactors = reactors;
    this->undercarriage = undercarriage;
    this->locomotive = locomotive;
    this->wagons = wagons;
    this->extra = extra;
    this->matricula = matricula;
    this->tipo = "ERROR";
    this->setTipo();

}

void Vehiculo::setTipo()
{

    if(motor == false)
    {
        if(wheelNum == 2 && fuel== false && wings == false && reactors ==false && undercarriage==false && locomotive == false && wagons == false && extra == 1)
        {
            this->tipo = "BICICLETA";
        }
        else if(wheelNum == 3 && fuel== false && wings == false && reactors ==false && undercarriage==false && locomotive == false && wagons == false && extra == 1)
        {
            this->tipo = "TRICICLO";
        }
    }
    else
    {
        if(wheelNum == 2 && (motorPow >= 80 && motorPow <= 450) && fuel == true && fuelType != "QUEROSENO" && wings == false && reactors ==false && undercarriage==false && locomotive == false && wagons == false && extra == 0)
        {
            this->tipo = "MOTOCICLETA";
        }
        else if(wheelNum == 4 && (motorPow >= 80 && motorPow <= 250) && fuel == true && fuelType != "QUEROSENO" && wings == false && reactors ==false && undercarriage==false && locomotive == false && wagons == false && extra == 0)
        {
            this->tipo = "COCHE";
        }
        else if(wheelNum == 4 && (motorPow > 250 && motorPow <= 450) && fuel == true && fuelType != "QUEROSENO" && wings == false && reactors ==false && undercarriage==false && locomotive == false && wagons == false && extra == 1)
        {
            this->tipo = "COCHE DEPORTIVO";
        }
        else if(wheelNum == 6 && motorPow == 450 && fuel == true && fuelType == "QUEROSENO" && color == "BLANCO" && wings == true && reactors == true && undercarriage==true && locomotive == false && wagons == false && extra == 0)
        {
            this->tipo = "AVION";
        }
        else if(wheelNum == 4 && motorPow == 450 && fuel == true && (fuelType == "DIESEL" || fuelType == "ELECTRICO") && color == "BLANCO" && wings == true && reactors == true && undercarriage==true && locomotive == false && wagons == false && extra == 0)
        {
            this->tipo = "TREN";
        }

    }

}

