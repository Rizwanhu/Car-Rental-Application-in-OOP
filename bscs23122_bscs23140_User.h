#pragma once
#include "bscs23122_bscs23140_Person.h"
#include "bscs23122_bscs23140_Car.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "bscs23122_bscs23140_Jeep.h"
#include "bscs23122_bscs23140_Truck.h"

using namespace std;

class User : public Person {
    Jeep* jeep;
    Car* car;
    Truck* truck;
    int num_of_days;
    string car_category;
public:
    User(string User_id = "", string Password = "", Car* C = nullptr, int Num_of_days = 0, string Car_category = "");
    void setCar(Car* C);
    void setNum_of_days(int a);
    void setCar_category(string s);
    void setVehicle_num_plate(string a);
    Car* getCar();
    int getNum_of_days();
    string getCar_category();
    string getVehicle_num_plate();
    void print();
    virtual ~User();
};

void deallocate_user_double_arr(User**& U, int size);
void expand_user_arr(User**& U, int& size);
void read_user_file(User**& U, int& size);
void write_user_file(User**& U, int& size);
