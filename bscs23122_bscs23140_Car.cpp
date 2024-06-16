#include "bscs23122_bscs23140_Car.h"
#include <iostream>
using namespace std;

Car::Car(string Color, string Num_plate, string Veh_name,
    int Model, int Milage, int No_of_seats, bool Driver, double Rent, bool Rent_status,
    string Car_type, string Gear_type)
    : Vehicle(Color, Num_plate, Veh_name, Model, Milage, No_of_seats, Driver, Rent, Rent_status),
    car_type(Car_type), gear_type(Gear_type) {}

void Car::setColor(string cl) 
{
    color = cl;
}
void Car::setNumPlate(string np) 
{
    num_plate = np;
}
void Car::setVehName(string vn)
{
    veh_name = vn;
}
void Car::setModel(int m)
{
    model = m;
}
void Car::setMilage(int sm)
{
    milage = sm;
}
void Car::setNoOfSeats(int n)
{
    no_of_seats = n;
}
void Car::setDriver(bool b)
{
    driver = b;
}
void Car::setRent(double r)
{
    rent = r;
}
void Car::setCar_type(string t)
{
    car_type = t;
}
void Car::setGear_type(string t) 
{
    gear_type = t;
}
void Car::setRent_status(bool i)
{
    rent_status = i;
}

string Car::getColor()
{
    return color;
}
string Car::getNumPlate()
{
    return num_plate;
}
string Car::getVehName() 
{
    return veh_name;
}
int Car::getModel()
{
    return model;
}
int Car::getMilage()
{
    return milage;
}
int Car::getNoOfSeats()
{
    return no_of_seats;
}
bool Car::getDriver()
{
    return driver;
}
double Car::getRent()
{
    return rent;
}
string Car::getCar_type()  
{
    return car_type;       
}                          

string Car::getGear_type() 
{
    return gear_type;      
}                          

bool Car::getRent_status() 
{
    return rent_status;
}

void Car::print() 
{
    cout << "-------------------" << veh_name << "----------------------" << endl;
    cout << "RENT : Rs." << rent << endl;
    cout << "No. Plate : " << num_plate << endl;
    cout << "Model : " << model << endl;
    cout << "Milage : " << milage << " km/liter" << endl;
    cout << "No. of Seats : " << no_of_seats << endl;
    cout << "Car Type : " << car_type << endl;
    cout << "Gear Type : " << gear_type << endl;
}

Car::~Car() {}

void deallocate_car_double_arr(Car** C, int size) 
{
    for (int i = 0; i < size; i++)
    {
        delete[] C[i];
    }
    delete[] C;
    C = nullptr;
}
