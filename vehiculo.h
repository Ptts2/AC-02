#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

using namespace std;

class Vehiculo
{
public:
    Vehiculo();
    Vehiculo(string nombre, int wheelNum, bool motor, int motorPow, bool fuel, string fuelType, string color, bool wings, bool reactors, bool undercarriage, bool locomotive, bool wagons, int wagonNum, int extra, string matricula);
    void setTipo();
    string getTipo();
    string to_string();
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
    int wagonNum;
    int extra; //1 rueda 2 kit
    string matricula;

};

#endif // VEHICULO_H
