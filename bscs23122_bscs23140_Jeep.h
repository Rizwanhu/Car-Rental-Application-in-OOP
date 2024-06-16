#pragma once
#include "bscs23122_bscs23140_Car.h"
#include <fstream>
#include <sstream>
#include <iostream>

class Jeep : virtual public Car
{
protected:
    bool off_road_capability;
    string terrain_type;

public:
    Jeep(string Color = "", string Num_plate = "", string Veh_name = "",
        int Model = 0, int Milage = 0, int No_of_seats = 0, bool Driver = 0, double Rent = 0.0, bool Rent_status = 0,
        string car_type = "", string gear_type = "", bool Off_road_capability = 0, string Terrain_type = "");

    // Setters
    void setOff_road_capability(bool f);
    void setTerrain_type(string t);

    // Getters
    bool getOff_road_capability();
    string getTerrain_type();

    void print() override;

    virtual ~Jeep();
};

void expand_jeep_arr(Jeep**& ptr, int& size);

void deallocate_jeep_double_arr(Jeep**& U, int size);

void read_jeep(Jeep**& Cc, int& size);

void write_jeep(Jeep**& Cc, int& size);

inline void copy(string& str1, string str2);