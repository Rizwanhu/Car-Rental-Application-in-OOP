#pragma once

#include "bscs23122_bscs23140_Car.h"
#include <fstream>
#include <sstream>
#include <iostream>

class Truck : public Car {
protected:
    int cargo_cap;
    int towing_cap;
    int wheeler;

public:
    Truck(string Color = "", string Num_plate = "", string Veh_name = "",
        int Model = 0, int Milage = 0, int No_of_seats = 0, bool Driver = 0, double Rent = 0.0, bool Rent_status = 0,
        string Car_type = "", string Gear_type = "", int Cargo_cap = 0, int Towing_cap = 0, int Wheeler = 0);

    // Setters
    void setColor(string cl);
    void setNumPlate(string np);
    void setVehName(string vn);
    void setModel(int m);
    void setMilage(int sm);
    void setNoOfSeats(int n);
    void setDriver(bool b);
    void setRent(double r);
    void setCargo_cap(int c);
    void setTowing_cap(int c);
    void setWheeler(int w);
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
    bool getRent_status();
    int getCargo_cap();
    int getTowing_cap();
    int getWheeler();

    void print() override;

    virtual ~Truck();
};

void expand_truck(Truck**& T, int& size);

void deallocate_double_truck_arr(Truck**& T, int size);

void read_truck(Truck**& T, int& size);

void write_truck(Truck**& T, int& size);

inline void copy(string& str1, string str2);