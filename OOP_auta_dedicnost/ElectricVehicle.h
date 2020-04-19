#include <iostream>
#include "Vehicle.h"

using namespace std;

class ElectricVehicle : public Vehicle
{
private:
    int energystorage;
public:
    ElectricVehicle(string type, string brand, string model, string color, int year, int kilometres, int energystorage);
    ~ElectricVehicle();
    void VehiclePrint();
};
