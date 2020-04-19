#include <iostream>
#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(string type, string brand, string model, string color, int year, int kilometres)
{
    this->type = type;
    this->brand = brand;
    this->model = model;
    this->color = color;
    this->year = year;
    this->kilometres = kilometres;
    cout << "Type: " << this->type << endl;
    cout << "Brand: " << this->brand << endl;
    cout << "Model: " << this->model << endl;
    cout << "Color: " << this->color << endl;
    cout << "Year: " << this->year << endl;
    cout << "Kilometres: " << this->kilometres << endl;
}

Vehicle::~Vehicle()
{

}

void Vehicle::VehiclePrint()
{
    cout << "Type: " << this->type << endl;
    cout << "Brand: " << this->brand << endl;
    cout << "Model: " << this->model << endl;
    cout << "Color: " << this->color << endl;
    cout << "Year: " << this->year << endl;
    cout << "Kilometres: " << this->kilometres << endl;
}

string Vehicle::GetColor()
{
    return color;
}
