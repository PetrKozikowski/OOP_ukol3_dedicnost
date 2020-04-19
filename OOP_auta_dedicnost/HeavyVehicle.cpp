#include <iostream>
#include "HeavyVehicle.h"

using namespace std;

HeavyVehicle::HeavyVehicle(string type, string brand, string model, string color, int year, int kilometres, int fueltank, int maxweight, int wheels, double length) : GasVehicle(type, brand, model, color, year, kilometres, fueltank)
{
    this->maxweight = maxweight;
    this->wheels = wheels;
    this->length = length;
}

HeavyVehicle::~HeavyVehicle()
{

}

void HeavyVehicle::VehiclePrint()
{
    GasVehicle::VehiclePrint();
    cout << "Maximum weight: " << this->maxweight << endl;
    cout << "Wheels count: " << this->wheels << endl;
    cout << "Length: " << this->length << endl;

}

int HeavyVehicle::GetWheels()
{
    return wheels;
}