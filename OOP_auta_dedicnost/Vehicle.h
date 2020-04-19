#pragma once
#include <iostream>

using namespace std;


class Vehicle

{
private:
    string type;
    string brand;
    string model;
    string color;
    int year;
    int kilometres;
public:
    Vehicle(string type, string brand, string model, string color, int year, int kilometres);
    ~Vehicle();
    void VehiclePrint();
    string GetColor();
};