#pragma once
#include <string>
using namespace std;

class Vehicle {
protected:
    string color;
    string num_plate;
    string veh_name;
    int model;
    int milage;
    int no_of_seats;
    bool driver;
    double rent;
    bool rent_status;

public:
    Vehicle(string Color = "", string Num_plate = "", string Veh_name = "",
        int Model = 0, int Milage = 0, int No_of_seats = 0, bool Driver = 0, double Rent = 0.0, bool Rent_status = 0);

    virtual void print() = 0;

    virtual ~Vehicle();
};