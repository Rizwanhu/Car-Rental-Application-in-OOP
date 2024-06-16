#pragma once
#include "bscs23122_bscs23140_Car.h"
#include <fstream>
#include <sstream>
#include <iostream>

class Casual_Car : public Car
{
protected:
    string condition;
    bool ac_status;

public:
    Casual_Car(string Color = "", string Num_plate = "", string Veh_name = "",
        int Model = 0, int Milage = 0, int No_of_seats = 0, bool Driver = 0, double Rent = 0.0, bool Rent_status = 0,
        string Car_type = "", string Gear_type = "", string Condition = "", bool Ac_status = 0);

    // Setters
    void setCondition(string c);
    void setAc_status(bool a);

    // Getters
    string getCondition();
    bool getAc_status();

    void print() override;

    virtual ~Casual_Car();
};

void deallocate_casual_car_double_arr(Casual_Car**& Cc, int size);

void expand_casual_car_arr(Casual_Car**& ptr, int& size);

void read_casual_car(Casual_Car**& Cc, int& size);

void write_casual_car(Casual_Car**& Cc, int& size);

inline void copy(string& str1, string str2);