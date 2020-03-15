#include "vehiculo.h"
#include <string>

using namespace std;
Vehiculo::Vehiculo(){}
Vehiculo::~Vehiculo(){}
Vehiculo::Vehiculo(string nombre, int wheelNum, bool motor, int motorPow, bool fuel, string fuelType, string color, bool wings, bool reactors, bool undercarriage, bool locomotive, bool wagons, int wagonNum, int extra, string matricula)
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
    this->wagonNum = wagonNum;
    this->extra = extra;
    this->matricula = matricula;
    this->tipo = "ERROR";
    this->setTipo();

}

void Vehiculo::setTipo()
{

    if(motor == false)
    {
        if(wheelNum == 2 && fuel== false && wings == false && reactors ==false && undercarriage==false && locomotive == false && wagons == false && extra == 2)
        {
            this->tipo = "BICICLETA";
        }
        else if(wheelNum == 3 && fuel== false && wings == false && reactors ==false && undercarriage==false && locomotive == false && wagons == false && extra == 2)
        {
            this->tipo = "TRICICLO";
        }
    }
    else
    {
        if(wheelNum == 2 && (motorPow >= 80 && motorPow <= 450) && fuel == true && fuelType != "QUEROSENO" && wings == false && reactors ==false && undercarriage==false && locomotive == false && wagons == false && extra == 2)
        {
            this->tipo = "MOTOCICLETA";
        }
        else if(wheelNum == 4 && (motorPow >= 80 && motorPow <= 250) && fuel == true && fuelType != "QUEROSENO" && wings == false && reactors ==false && undercarriage==false && locomotive == false && wagons == false && extra == 1)
        {
            this->tipo = "COCHE";
        }
        else if(wheelNum == 4 && (motorPow > 250 && motorPow <= 450) && fuel == true && (fuelType == "ELECTRICO" || fuelType =="GASOLINA") && wings == false && reactors ==false && undercarriage==false && locomotive == false && wagons == false && extra == 2)
        {
            this->tipo = "COCHE DEPORTIVO";
        }
        else if(wheelNum == 6 && motorPow == 450 && fuel == true && fuelType == "QUEROSENO" && color == "BLANCO" && wings == true && reactors == true && undercarriage==true && locomotive == false && wagons == false && extra == 1)
        {
            this->tipo = "AVION";
        }
        else if(wheelNum == 40 && motorPow == 450 && fuel == true && (fuelType == "DIESEL" || fuelType == "ELECTRICO") && color == "NEGRO" && wings == false && reactors == false && undercarriage==false && locomotive == true && wagons == true && (wagonNum >=5 || wagonNum <=20) && extra == 1)
        {
            this->tipo = "TREN";
        }

    }

}

string Vehiculo::getTipo()
{
    return this->tipo;
}

string Vehiculo::to_string()
{
    return ("  NOMBRE: "+this->nombre+
            " \tTIPO: "+this->tipo+
            " \tMATRICULA: "+this->matricula+
            "\n  COLOR: "+this->color+""+(this->fuelType != "NO_FUEL"? " \tCOMBUSTIBLE: "+this->fuelType : " \tCOMBUSTIBLE: SIN COMBUSTIBLE")+
            " \tREPUESTO: "+(this->extra == 1? "RUEDA DE RECAMBIO":"KIT DE REPARACION")+
            (this->tipo == "TREN" ? " \tVAGONES: "+std::to_string(wagonNum) : " \tSIN VAGONES")+
            "  \n  MOTOR: "+(this->motor? "YES WITH POWER OF "+std::to_string(this->motorPow):"NO")+
            " \tNº Ruedas: "+std::to_string(this->wheelNum)+
            " \tALAS: "+(this->wings? "YES":"NO")+
            " \tREACTORES: "+(this->reactors? "YES":"NO")+
            " \tTREN DE ATERRIZAJE: "+(this->undercarriage? "YES":"NO")+
            " \n  LOCOMOTORA: "+(this->locomotive? "YES":"NO")
            );
}

