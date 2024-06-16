#include "bscs23122_bscs23140_WeddingCar.h"

Wedding_Car::Wedding_Car(string Color, string Num_plate, string Veh_name,
    int Model, int Milage, int No_of_seats, bool Driver, double Rent, bool Rent_status,
    string Car_type, string Gear_type, bool Decor)
    : Car(Color, Num_plate, Veh_name, Model, Milage, No_of_seats, Driver, Rent, Rent_status, Car_type, Gear_type),
    decor(Decor) {}

void Wedding_Car::setDecor(bool d) {
    decor = d;
}

bool Wedding_Car::getDecor() {
    return decor;
}

void Wedding_Car::print() {
    Car::print();
    cout << "Decor : " << (decor ? "Yes" : "No") << endl;
}

Wedding_Car::~Wedding_Car() {}

void deallocate_wedding_car_double_arr(Wedding_Car**& Wc, int size) {
    for (int i = 0; i < size; i++) {
        delete Wc[i];
    }
    delete[] Wc;
    Wc = nullptr;
}

void expand_wedding_car_arr(Wedding_Car**& ptr, int& size) {
    Wedding_Car** temp = new Wedding_Car * [size + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
    size++;
}

void copy(string& str1, string str2) {
    for (int i = 0; i < (int)str2.length(); i++) {
        str1 += str2[i];
    }
}

void read_wedding_car(Wedding_Car**& Wc, int& size) {
    fstream read;
    read.open("Wedding_Car.txt", ios::in);
    if (read.is_open()) {
        while (!read.eof()) {
            string Color = "", Num_plate = "", Veh_name = "";
            int Model = 0, Milage = 0, No_of_seats = 0;
            bool Driver = 0;
            double Rent = 0.0;
            bool Rent_status = 0;
            string Car_type = "", Gear_type = "";
            bool Decor = 0;

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
                Decor = stoi(temp_str);
            }

            expand_wedding_car_arr(Wc, size);
            Wc[size - 1] = new Wedding_Car(Color, Num_plate, Veh_name, Model, Milage, No_of_seats, Driver, Rent, Rent_status, Car_type, Gear_type, Decor);
        }
        read.close();
    }
    else {
        cout << "Error Opening File.\n\n";
    }
}

void write_wedding_car(Wedding_Car**& Wc, int& size) {
    remove("Wedding_Car.txt");
    fstream write;
    write.open("Wedding_Car.txt", ios::out);

    if (write.is_open()) {
        for (int i = 0; i < size; i++) {
            write << Wc[i]->getColor() << ", ";
            write << Wc[i]->getNumPlate() << ", ";
            write << Wc[i]->getVehName() << ", ";
            write << Wc[i]->getModel() << ", ";
            write << Wc[i]->getMilage() << ", ";
            write << Wc[i]->getNoOfSeats() << ", ";
            write << Wc[i]->getDriver() << ", ";
            write << static_cast<long int>(Wc[i]->getRent()) << ", ";
            write << Wc[i]->getRent_status() << ", ";
            write << Wc[i]->getCar_type() << ", ";
            write << Wc[i]->getGear_type() << ", ";
            write << Wc[i]->getDecor();
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