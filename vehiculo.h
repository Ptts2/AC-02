#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

using namespace std;

class Vehiculo
{
public:
    Vehiculo();
    Vehiculo(string nombre, int wheelNum, bool motor, int motorPow, bool fuel, string fuelType, string color, bool wings, bool reactors, bool undercarriage, bool locomotive, bool wagons, int extra, string matricula);
    void setTipo();
    ~Vehiculo();

private:
    string tipo;
    string nombre;
    int wheelNum;
    bool motor;
    int motorPow;
    bool fuel;
    string fuelType;
    string color;
    bool wings;
    bool reactors;
    bool undercarriage;
    bool locomotive;
    bool wagons;
    int extra; //0 rueda 1 kit
    string matricula;

};

#endif // VEHICULO_H
