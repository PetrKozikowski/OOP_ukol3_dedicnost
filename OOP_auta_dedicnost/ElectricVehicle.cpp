#include <iostream>
#include "ElectricVehicle.h"

using namespace std;

ElectricVehicle::ElectricVehicle(string type, string brand, string model, string color, int year, int kilometres, int energystorage) : Vehicle(type, brand, model, color, year, kilometres)
{
    this->energystorage = energystorage;
    cout << "Energy storage: " << this->energystorage << endl;
}

ElectricVehicle::~ElectricVehicle()
{

}

void ElectricVehicle::VehiclePrint()
{
    Vehicle::VehiclePrint();
    cout << "Energy storage: " << this->energystorage << endl;
}
