#include "bscs23122_bscs23140_CasualCar.h"


Casual_Car::Casual_Car(string Color, string Num_plate, string Veh_name,
    int Model, int Milage, int No_of_seats, bool Driver, double Rent, bool Rent_status,
    string Car_type, string Gear_type, string Condition, bool Ac_status)
    : Car(Color, Num_plate, Veh_name, Model, Milage, No_of_seats, Driver, Rent, Rent_status, Car_type, Gear_type),
    condition(Condition), ac_status(Ac_status) {}

void Casual_Car::setCondition(string c)
{
    condition = c;
}

void Casual_Car::setAc_status(bool a)
{
    ac_status = a;
}

string Casual_Car::getCondition()
{
    return condition;
}

bool Casual_Car::getAc_status() 
{
    return ac_status;
}

void Casual_Car::print() 
{
    Car::print();
    cout << "Condition: " << condition << endl;
    cout << "AC Status : " << (ac_status ? "Working" : "Not Working") << endl;
}

Casual_Car::~Casual_Car() {}

void deallocate_casual_car_double_arr(Casual_Car**& Cc, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete Cc[i];
    }
    delete[] Cc;
    Cc = nullptr;
}

void expand_casual_car_arr(Casual_Car**& ptr, int& size)
{
    Casual_Car** temp = new Casual_Car * [size + 1];
    for (int i = 0; i < size; i++) 
    {
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
    size++;
}

void copy(string& str1, string str2)
{
    for (int i = 0; i < (int)str2.length(); i++)
    {
        str1 += str2[i];
    }
}

void read_casual_car(Casual_Car**& Cc, int& size)
{
    fstream read;
    read.open("Casual_Car.txt", ios::in);
    if (read.is_open()) {
        while (!read.eof()) {
            string Color = "", Num_plate = "", Veh_name = "", Condition = "";
            int Model = 0, Milage = 0, No_of_seats = 0;
            bool Driver = 0;
            double Rent = 0.0;
            bool Rent_status = 0;
            string Car_type = "", Gear_type = "";
            bool Ac_status = 0;

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
            copy(Condition, temp_str);
            getline(ss, temp_str, ',');
            if (!temp_str.empty())
            {
                Ac_status = stoi(temp_str);
            }

            expand_casual_car_arr(Cc, size);
            Cc[size - 1] = new Casual_Car(Color, Num_plate, Veh_name, Model, Milage, No_of_seats, Driver, Rent, Rent_status, Car_type, Gear_type, Condition, Ac_status);
        }
        read.close();
    }
    else 
    {
        cout << "Error Opening File.\n\n";
    }
}

void write_casual_car(Casual_Car**& Cc, int& size)
{
    remove("Casual_Car.txt");
    fstream write;
    write.open("Casual_Car.txt", ios::out);

    if (write.is_open()) 
    {
        for (int i = 0; i < size; i++)
        {
            write << Cc[i]->getColor() << ", ";
            write << Cc[i]->getNumPlate() << ", ";
            write << Cc[i]->getVehName() << ", ";
            write << Cc[i]->getModel() << ", ";
            write << Cc[i]->getMilage() << ", ";
            write << Cc[i]->getNoOfSeats() << ", ";
            write << Cc[i]->getDriver() << ", ";
            write << static_cast<long int>(Cc[i]->getRent()) << ", ";
            write << Cc[i]->getRent_status() << ", ";
            write << Cc[i]->getCar_type() << ", ";
            write << Cc[i]->getGear_type() << ", ";
            write << Cc[i]->getCondition() << ", ";
            write << Cc[i]->getAc_status();
            if (i != size - 1)
            {
                write << endl;
            }
        }
        write.close();
    }
    else {
        cout << "Error while opening file.\n\n";
    }
}