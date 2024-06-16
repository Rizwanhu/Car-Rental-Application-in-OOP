#pragma once
#include "bscs23122_bscs23140_Vehicle.h"

class Car : public Vehicle 
{
protected:
    string car_type;
    string gear_type; // Auto or Manual

public:
    Car(string Color = "", string Num_plate = "", string Veh_name = "",
        int Model = 0, int Milage = 0, int No_of_seats = 0, bool Driver = 0, double Rent = 0, bool Rent_status = 0,
        string Car_type = "", string Gear_type = "");

    // Setters
    void setColor(string cl);
    void setNumPlate(string np);
    void setVehName(string vn);
    void setModel(int m);
    void setMilage(int sm);
    void setNoOfSeats(int n);
    void setDriver(bool b);
    void setRent(double r);
    void setCar_type(string t);
    void setGear_type(string t);
    void setRent_status(bool i);

    // Getters
    string getColor();
    string getNumPlate();
    string getVehName();
    int getModel();
    int getMilage();
    int getNoOfSeats();
    bool getDriver();
    double getRent();
    string getCar_type();
    string getGear_type();
    bool getRent_status();

    void print() override;

    virtual ~Car();
};

void deallocate_car_double_arr(Car** C, int size);
