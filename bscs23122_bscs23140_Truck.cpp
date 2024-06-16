#include "bscs23122_bscs23140_Truck.h"

Truck::Truck(string Color, string Num_plate, string Veh_name,
    int Model, int Milage, int No_of_seats, bool Driver, double Rent, bool Rent_status,
    string Car_type, string Gear_type, int Cargo_cap, int Towing_cap, int Wheeler)
    : Car(Color, Num_plate, Veh_name, Model, Milage, No_of_seats, Driver, Rent, Rent_status, Car_type, Gear_type),
    cargo_cap(Cargo_cap), towing_cap(Towing_cap), wheeler(Wheeler) {}

void Truck::setColor(string cl) {
    color = cl;
}

void Truck::setNumPlate(string np) {
    num_plate = np;
}

void Truck::setVehName(string vn) {
    veh_name = vn;
}

void Truck::setModel(int m) {
    model = m;
}

void Truck::setMilage(int sm) {
    milage = sm;
}

void Truck::setNoOfSeats(int n) {
    no_of_seats = n;
}

void Truck::setDriver(bool b) {
    driver = b;
}

void Truck::setRent(double r) {
    rent = r;
}

void Truck::setCargo_cap(int c) {
    cargo_cap = c;
}

void Truck::setTowing_cap(int c) {
    towing_cap = c;
}

void Truck::setWheeler(int w) {
    wheeler = w;
}

void Truck::setRent_status(bool i) {
    rent_status = i;
}

string Truck::getColor() {
    return color;
}

string Truck::getNumPlate() {
    return num_plate;
}

string Truck::getVehName() {
    return veh_name;
}

int Truck::getModel() {
    return model;
}

int Truck::getMilage() {
    return milage;
}

int Truck::getNoOfSeats() {
    return no_of_seats;
}

bool Truck::getDriver() {
    return driver;
}

double Truck::getRent() {
    return rent;
}

bool Truck::getRent_status() {
    return rent_status;
}

int Truck::getCargo_cap() {
    return cargo_cap;
}

int Truck::getTowing_cap() {
    return towing_cap;
}

int Truck::getWheeler() {
    return wheeler;
}

void Truck::print() 
{
    Car::print();
    cout << "Cargo Capacity : " << cargo_cap << " kg" << endl;
    cout << "Towing Capacity : " << towing_cap << " kg" << endl;
    cout << "No. of Wheels : " << wheeler << endl;
}

Truck::~Truck() {}

void expand_truck(Truck**& T, int& size) {
    Truck** temp = new Truck * [size + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = T[i];
    }
    delete[] T;
    T = temp;
    size++;
}

void deallocate_double_truck_arr(Truck**& T, int size) {
    for (int i = 0; i < size; i++) {
        delete T[i];
    }
    delete[] T;
    T = nullptr;
}

void copy(string& str1, string str2) {
    for (int i = 0; i < (int)str2.length(); i++) {
        str1 += str2[i];
    }
}

void read_truck(Truck**& T, int& size) {
    fstream read;
    read.open("Truck.txt", ios::in);
    if (read.is_open()) {
        while (!read.eof()) {
            string Color = "", Num_plate = "", Veh_name = "";
            int Model = 0, Milage = 0, No_of_seats = 0;
            bool Driver = 0;
            double Rent = 0.0;
            bool Rent_status = 0;
            int Cargo_cap = 0;
            int Towing_cap = 0;
            int Wheeler = 0;
            string Gear_type = "", Car_type = "";

            string str = "";
            string temp_str = "";
            getline(read, str);

            if (str.empty()) continue;

            stringstream ss(str);

            getline(ss, temp_str, ',');
            Color = temp_str;
            getline(ss, temp_str, ',');
            copy(Num_plate, temp_str);
            getline(ss, temp_str, ',');
            copy(Veh_name, temp_str);

            getline(ss, temp_str, ',');
            if (!temp_str.empty()) {
                Model = stoi(temp_str);
            }
            getline(ss, temp_str, ',');
            if (!temp_str.empty()) {
                Milage = stoi(temp_str);
            }
            getline(ss, temp_str, ',');
            if (!temp_str.empty()) {
                No_of_seats = stoi(temp_str);
            }
            getline(ss, temp_str, ',');
            if (!temp_str.empty()) {
                Driver = stoi(temp_str);
            }
            getline(ss, temp_str, ',');
            if (!temp_str.empty()) {
                Rent = stod(temp_str);
            }
            getline(ss, temp_str, ',');
            if (!temp_str.empty()) {
                Rent_status = stoi(temp_str);
            }

            getline(ss, temp_str, ',');
            copy(Car_type, temp_str);
            getline(ss, temp_str, ',');
            copy(Gear_type, temp_str);

            getline(ss, temp_str, ',');
            if (!temp_str.empty()) {
                Cargo_cap = stoi(temp_str);
            }
            getline(ss, temp_str, ',');
            if (!temp_str.empty()) {
                Towing_cap = stoi(temp_str);
            }
            getline(ss, temp_str, ',');
            if (!temp_str.empty()) {
                Wheeler = stoi(temp_str);
            }

            expand_truck(T, size);
            T[size - 1] = new Truck(Color, Num_plate, Veh_name, Model, Milage, No_of_seats, Driver, Rent, Rent_status, Car_type, Gear_type, Cargo_cap, Towing_cap, Wheeler);
        }
        read.close();
    }
    else {
        cout << "Error Opening File.\n\n";
    }
}

void write_truck(Truck**& T, int& size) {
    remove("Truck.txt");
    fstream write;
    write.open("Truck.txt", ios::out);

    if (write.is_open()) {
        for (int i = 0; i < size; i++) {
            write << T[i]->getColor() << ", ";
            write << T[i]->getNumPlate() << ", ";
            write << T[i]->getVehName() << ", ";
            write << T[i]->getModel() << ", ";
            write << T[i]->getMilage() << ", ";
            write << T[i]->getNoOfSeats() << ", ";
            write << T[i]->getDriver() << ", ";
            long int temp = static_cast<long int>(T[i]->getRent());
            write << temp << ", ";
            write << T[i]->getRent_status() << ", ";
            write << T[i]->getCar_type() << ", ";
            write << T[i]->getGear_type() << ", ";
            write << T[i]->getCargo_cap() << ", ";
            write << T[i]->getTowing_cap() << ", ";
            write << T[i]->getWheeler();
            if (i != size - 1) {
                write << endl;
            }
        }
        write.close();
    }
    else {
        cout << "Error while opening file.\n\n";
    }
}
