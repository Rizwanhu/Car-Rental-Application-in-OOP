#include "bscs23122_bscs23140_User.h"

User::User(string User_id, string Password, Car* C, int Num_of_days, string Car_category)
    : Person(User_id, Password), car(C), num_of_days(Num_of_days), car_category(Car_category) {
    if (C != nullptr) {
        car = new Car(C->getColor(), C->getNumPlate(), C->getVehName(), C->getModel(),
            C->getMilage(), C->getNoOfSeats(), C->getDriver(), C->getRent(),
            C->getRent_status(), C->getCar_type(), C->getGear_type());
    }
    else {
        car = new Car;
    }
}

void User::setCar(Car* C) {
    if (car != nullptr)
        delete car;

    car = new Car(C->getColor(), C->getNumPlate(), C->getVehName(), C->getModel(),
        C->getMilage(), C->getNoOfSeats(), C->getDriver(), C->getRent(),
        C->getRent_status(), C->getCar_type(), C->getGear_type());
}

void User::setNum_of_days(int a) {
    num_of_days = a;
}

void User::setCar_category(string s) {
    car_category = s;
}

void User::setVehicle_num_plate(string a) {
    car->setNumPlate(a);
}

Car* User::getCar() {
    return car;
}

int User::getNum_of_days() {
    return num_of_days;
}

string User::getCar_category() {
    return car_category;
}

string User::getVehicle_num_plate() {
    return car->getNumPlate();
}

void User::print() {
    cout << "User Id : *" << user_id << "*" << endl;
    cout << "Password : " << password << endl;
    if (num_of_days != 0) {
        cout << "Car Category : " << car_category << endl;
        cout << "Car Name : " << car->getVehName() << endl;
        cout << "RENT : Rs." << car->getRent() << endl;
        cout << "No. Plate : " << car->getNumPlate() << endl;
        cout << "Model : " << car->getModel() << endl;
        cout << "Milage : " << car->getMilage() << " km/liter" << endl;
        cout << "No. of Seats : " << car->getNoOfSeats() << endl;
        cout << "Car Type : " << car->getCar_type() << endl;
        cout << "Gear Type : " << car->getGear_type() << endl;
        cout << "Renting for  : " << num_of_days << " days" << endl;
    }
}

User::~User() {
    delete car;
    car = nullptr;
}

void deallocate_user_double_arr(User**& U, int size) {
    for (int i = 0; i < size; i++)
        delete[] U[i];
    delete[] U;
    U = nullptr;
}

void expand_user_arr(User**& U, int& size) {
    User** temp = new User * [size + 1];
    for (int i = 0; i < size; i++)
        temp[i] = U[i];
    size++;
    U = temp;
    temp = nullptr;
}

void read_user_file(User**& U, int& size) {
    fstream read;
    read.open("User.txt", ios::in);

    if (read.is_open()) {
        while (!read.eof()) {

            string Color = "", Num_plate = "", Veh_name = "", User_id = "", Password = "", Car_category = "";
            int Model = 0, Milage = 0, No_of_seats = 0, Num_of_days = 0;
            bool Driver = 0;
            double Rent = 0.0;
            bool Rent_status = 0;
            string  Car_type = "", Gear_type = "";
            Car* C = new Car;

            string line = "";
            string temp = "";
            getline(read, line);
            stringstream ss(line);

            getline(ss, temp, ',');
            User_id = temp;
            getline(ss, temp, ',');
            Password = temp;
            temp = "";
            getline(ss, temp, ',');
            if (!temp.empty()) {
                Car_category = temp;
            };
            getline(ss, temp, ',');
            if (!temp.empty()) {
                Color = temp;
            };
            C->setColor(Color);
            temp = "";
            getline(ss, temp, ',');
            if (!temp.empty()) {
                Num_plate = temp;
            };
            C->setNumPlate(Num_plate);
            temp = "";
            getline(ss, temp, ',');
            if (!temp.empty()) {
                Veh_name = temp;
            };
            C->setVehName(Veh_name);
            temp = "";
            getline(ss, temp, ',');
            if (!temp.empty()) {
                try {
                    Model = stoi(temp);
                }
                catch (const invalid_argument& e) {};
            };
            C->setModel(Model);

            getline(ss, temp, ',');
            if (!temp.empty()) {
                try {
                    Milage = stoi(temp);
                }
                catch (const invalid_argument& e) {};
            };
            C->setMilage(Milage);

            getline(ss, temp, ',');
            if (!temp.empty()) {
                try {
                    No_of_seats = stoi(temp);
                }
                catch (const invalid_argument& e) {};
            };
            C->setNoOfSeats(No_of_seats);

            getline(ss, temp, ',');
            if (!temp.empty()) {
                try {
                    Driver = (bool)stoi(temp);
                }
                catch (invalid_argument& e) {};
            };
            C->setDriver(Driver);

            getline(ss, temp, ',');
            if (!temp.empty()) {
                try {
                    Rent = stod(temp);
                }
                catch (const invalid_argument& e) {};
            };
            C->setRent(Rent);

            getline(ss, temp, ',');
            if (!temp.empty()) {
                try {
                    Rent_status = (bool)stoi(temp);
                }
                catch (const invalid_argument& e) {};
            };
            C->setRent_status(Rent_status);

            getline(ss, temp, ',');
            if (!temp.empty()) {
                Car_type = temp;
            };
            C->setCar_type(Car_type);
            getline(ss, temp, ',');
            if (!temp.empty()) {
                Gear_type = temp;
            };
            C->setGear_type(Gear_type);

            getline(ss, temp, ',');
            if (!temp.empty()) {
                try {
                    Num_of_days = stoi(temp);
                }
                catch (const invalid_argument& e) {};
            }
            expand_user_arr(U, size);
            U[size - 1] = new User(User_id, Password, C, Num_of_days, Car_category);
            delete C;
            C = nullptr;

        }
    }
    else
        cout << "Error while opening file.\n\n";
}

void write_user_file(User**& U, int& size) {
    remove("User.txt");
    fstream write;
    write.open("User.txt", ios::out);

    if (write.is_open()) {
        for (int i = 0; i < size; i++) {
            write << U[i]->getUser_id() << ", ";
            write << U[i]->getPassword();

            if (U[i]->getNum_of_days() != 0) {
                Car* C = U[i]->getCar();
                write << ", ";
                write << U[i]->getCar_category() << ", ";
                write << C->getColor() << ", ";
                write << C->getNumPlate() << ", ";
                write << C->getVehName() << ", ";
                write << C->getModel() << ", ";
                write << C->getMilage() << ", ";
                write << C->getNoOfSeats() << ", ";
                write << C->getDriver() << ", ";
                write << C->getRent() << ", ";
                write << C->getRent_status() << ", ";
                write << C->getCar_type() << ", ";
                write << C->getGear_type() << ", ";
                write << U[i]->getNum_of_days();
                C = nullptr;
            }
            if (i != size - 1)
                write << endl;
        }
        write.close();
    }
    else
        cout << "Error while opening file.\n\n";
}
