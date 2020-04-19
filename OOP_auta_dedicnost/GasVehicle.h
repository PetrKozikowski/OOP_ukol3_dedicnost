#pragma once
#include <iostream>
#include "Vehicle.h"

class GasVehicle : public Vehicle
{
private:
    int fueltank;
public:
    GasVehicle(string type, string brand, string model, string color, int year, int kilometres, int fueltank);
    ~GasVehicle();
    void VehiclePrint();
};