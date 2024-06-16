#pragma once
#include "bscs23122_bscs23140_Car.h"
#include <fstream>
#include <sstream>
#include <iostream>

class Wedding_Car : public Car {
protected:
    bool decor;

public:
    Wedding_Car(string Color = "", string Num_plate = "", string Veh_name = "",
        int Model = 0, int Milage = 0, int No_of_seats = 0, bool Driver = 0, double Rent = 0.0, bool Rent_status = 0,
        string Car_type = "", string Gear_type = "", bool Decor = 0);

    // Setters
    void setDecor(bool d);

    // Getters
    bool getDecor();

    void print() override;

    virtual ~Wedding_Car();
};

void deallocate_wedding_car_double_arr(Wedding_Car**& Wc, int size);

void expand_wedding_car_arr(Wedding_Car**& ptr, int& size);

void read_wedding_car(Wedding_Car**& Wc, int& size);

void write_wedding_car(Wedding_Car**& Wc, int& size);

inline void copy(string& str1, string str2);