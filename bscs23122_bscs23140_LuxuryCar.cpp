#include "bscs23122_bscs23140_LuxuryCar.h"

Luxury_Car::Luxury_Car(string Color, string Num_plate, string Veh_name,
    int Model, int Milage, int No_of_seats, bool Driver, double Rent, bool Rent_status,
    string Car_type, string Gear_type, bool Sun_roof)
    : Car(Color, Num_plate, Veh_name, Model, Milage, No_of_seats, Driver, Rent, Rent_status, Car_type, Gear_type),
    sun_roof(Sun_roof) {}

void Luxury_Car::setSun_roof(bool t)
{
    sun_roof = t;
}

bool Luxury_Car::getSun_roof()
{
    return sun_roof;
}

void Luxury_Car::print()
{
    Car::print();
    cout << "Sun Roof : " << (sun_roof ? "Yes" : "No") << endl;
}

Luxury_Car::~Luxury_Car() {}

void deallocate_luxury_car_double_arr(Luxury_Car**& Lu, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete Lu[i];
    }
    delete[] Lu;
    Lu = nullptr;
}

void expand_luxury_car_arr(Luxury_Car**& ptr, int& size) 
{
    Luxury_Car** temp = new Luxury_Car * [size + 1];
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

void read_luxury_car(Luxury_Car**& Lc, int& size) 
{
    fstream read;
    read.open("Luxury_Car.txt", ios::in);
    if (read.is_open()) {
        while (!read.eof()) {
            string Color = "", Num_plate = "", Veh_name = "";
            int Model = 0, Milage = 0, No_of_seats = 0;
            bool Driver = 0;
            double Rent = 0.0;
            bool Rent_status = 0;
            string Car_type = "", Gear_type = "";
            bool Sun_roof = 0;

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
            if (!temp_str.empty())
            {
                Model = stoi(temp_str);
            }
            getline(ss, temp_str, ',');
            if (!temp_str.empty())
            {
                Milage = stoi(temp_str);
            }
            getline(ss, temp_str, ',');
            if (!temp_str.empty())
            {
                No_of_seats = stoi(temp_str);
            }
            getline(ss, temp_str, ',');
            if (!temp_str.empty())
            {
                Driver = stoi(temp_str);
            }
            getline(ss, temp_str, ',');
            if (!temp_str.empty())
            {
                Rent = stod(temp_str);
            }
            getline(ss, temp_str, ',');
            if (!temp_str.empty())
            {
                Rent_status = stoi(temp_str);
            }

            getline(ss, temp_str, ',');
            copy(Car_type, temp_str);
            getline(ss, temp_str, ',');
            copy(Gear_type, temp_str);
            getline(ss, temp_str, ',');
            if (!temp_str.empty()) 
            {
                Sun_roof = stoi(temp_str);
            }

            expand_luxury_car_arr(Lc, size);
            Lc[size - 1] = new Luxury_Car(Color, Num_plate, Veh_name, Model, Milage, No_of_seats, Driver, Rent, Rent_status, Car_type, Gear_type, Sun_roof);
        }
        read.close();
    }
    else 
    {
        cout << "Error Opening File.\n\n";
    }
}

void write_luxury_car(Luxury_Car**& Lc, int& size)
{
    remove("Luxury_Car.txt");
    fstream write;
    write.open("Luxury_Car.txt", ios::out);

    if (write.is_open()) 
    {
        for (int i = 0; i < size; i++) 
        {
            write << Lc[i]->getColor() << ", ";
            write << Lc[i]->getNumPlate() << ", ";
            write << Lc[i]->getVehName() << ", ";
            write << Lc[i]->getModel() << ", ";
            write << Lc[i]->getMilage() << ", ";
            write << Lc[i]->getNoOfSeats() << ", ";
            write << Lc[i]->getDriver() << ", ";
            write << static_cast<long int>(Lc[i]->getRent()) << ", ";
            write << Lc[i]->getRent_status() << ", ";
            write << Lc[i]->getCar_type() << ", ";
            write << Lc[i]->getGear_type() << ", ";
            write << Lc[i]->getSun_roof();
            if (i != size - 1)
                write << endl;
        }
        write.close();
    }
    else {
        cout << "Error while opening file.\n\n";
    }
}
