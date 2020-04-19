#include <iostream>
#include <stdio.h>
#include "HeavyVehicle.h"
#include "ElectricVehicle.h"

using namespace std;

int main()
{
    cout << " ***New gas vehicle*** " << endl;
    GasVehicle* bmw = new GasVehicle{ "Sport", "BMW", "M3 GTR", "white", 2012, 120300, 80 };  // regular car
    bmw->VehiclePrint();

    cout << " *** New electric vehicle *** " << endl;
    ElectricVehicle* tesla = new ElectricVehicle{ "Sport", "Tesla", "Roadster", "red", 2021, 1243, 85 };
    tesla->VehiclePrint();

    cout << " ***New heavy vehicle*** " << endl;
    HeavyVehicle* man = new HeavyVehicle{"truck", "MAN", "TGX XXL", "black", 2005, 25000, 200, 40000, 16, 15};
    man->VehiclePrint();

    cout << "Color bmw: " << bmw->GetColor() << endl;
    cout << "Color tesla: " << tesla->GetColor() << endl;
    cout << "Color man: " << man->GetColor() << endl;
    cout << "Wheels count: " << man->GetWheels() << endl;
    //cout << "Wheels count: " << bmw->GetWheels() << endl; // Tato tøída nemá kola

    delete bmw;
    delete tesla;
    delete man;


	return 0;
}


 