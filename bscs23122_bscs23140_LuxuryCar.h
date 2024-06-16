#pragma once
#include "bscs23122_bscs23140_Car.h"
#include <fstream>
#include <sstream>
#include <iostream>

class Luxury_Car : public Car 
{
protected:
    bool sun_roof;

public:
    Luxury_Car(string Color = "", string Num_plate = "", string Veh_name = "",
        int Model = 0, int Milage = 0, int No_of_seats = 0, bool Driver = 0, double Rent = 0, bool Rent_status = 0,
        string Car_type = "", string Gear_type = "", bool Sun_roof = 0);

    // Setters
    void setSun_roof(bool t);

    // Getters
    bool getSun_roof();

    void print() override;

    virtual ~Luxury_Car();
};

void deallocate_luxury_car_double_arr(Luxury_Car**& Lu, int size);

void expand_luxury_car_arr(Luxury_Car**& ptr, int& size);

inline void copy(string& str1, string str2);

void read_luxury_car(Luxury_Car**& Lc, int& size);

void write_luxury_car(Luxury_Car**& Lc, int& size);