#pragma once
#include <iostream>
#include "Vehicle.h"
#include "GasVehicle.h"

class HeavyVehicle : public GasVehicle
{
private:
    int maxweight;
    int wheels;
    double length;
public:
    HeavyVehicle(string type, string brand, string model, string color, int year, int kilometres, int fueltank, int maxweight, int wheels, double length);
    ~HeavyVehicle();
    void VehiclePrint();
    int GetWheels();
};


