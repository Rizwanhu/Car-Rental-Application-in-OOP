#include "bscs23122_bscs23140_Vehicle.h"

Vehicle::Vehicle(string Color, string Num_plate, string Veh_name,
    int Model, int Milage, int No_of_seats, bool Driver, double Rent, bool Rent_status)
    : color(Color), num_plate(Num_plate), veh_name(Veh_name),
    model(Model), milage(Milage), no_of_seats(No_of_seats), driver(Driver), rent(Rent), rent_status(Rent_status) {}

Vehicle::~Vehicle() {}