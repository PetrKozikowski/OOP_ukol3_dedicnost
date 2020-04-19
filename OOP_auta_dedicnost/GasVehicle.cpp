#include <iostream>
#include "GasVehicle.h"

using namespace std;

GasVehicle::GasVehicle(string type, string brand, string model, string color, int year, int kilometres, int fueltank) : Vehicle(type, brand, model, color, year, kilometres)
{
    this->fueltank = fueltank;
    cout << "Fuel tank: " << this->fueltank << endl;

}

GasVehicle::~GasVehicle()
{

}

void GasVehicle::VehiclePrint()
{
    Vehicle::VehiclePrint();
    cout << "Fuel tank: " << this->fueltank << endl;
}
