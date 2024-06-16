#include "bscs23122_bscs23140_Jeep.h"

Jeep::Jeep(string Color, string Num_plate, string Veh_name,
    int Model, int Milage, int No_of_seats, bool Driver, double Rent, bool Rent_status,
    string car_type, string gear_type, bool Off_road_capability, string Terrain_type)
    : Car(Color, Num_plate, Veh_name, Model, Milage, No_of_seats, Driver, Rent, Rent_status, car_type, gear_type),
    off_road_capability(Off_road_capability), terrain_type(Terrain_type) {}

void Jeep::setOff_road_capability(bool f)
{
    off_road_capability = f;
}

void Jeep::setTerrain_type(string t) 
{
    terrain_type = t;
}

bool Jeep::getOff_road_capability()
{
    return off_road_capability;
}

string Jeep::getTerrain_type()
{
    return terrain_type;
}

void Jeep::print() 
{
    cout << "-------------------" << veh_name << "----------------------" << endl;
    cout << "RENT : Rs." << rent << endl;
    cout << "No. Plate : " << num_plate << endl;
    cout << "Model : " << model << endl;
    cout << "Milage : " << milage << " km/liter" << endl;
    cout << "No. of Seats : " << no_of_seats << endl;
    cout << "Jeep Type : " << car_type << endl;
    cout << "Gear Type : " << gear_type << endl;
    cout << "Off Road Capability : " << (off_road_capability ? "Yes" : "No") << endl;
    cout << "Terrain Type : " << terrain_type << endl;
}

Jeep::~Jeep() {}

void expand_jeep_arr(Jeep**& ptr, int& size)
{
    Jeep** temp = new Jeep * [size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
    size++;
}

void deallocate_jeep_double_arr(Jeep**& U, int size) 
{
    for (int i = 0; i < size; i++)
    {
        delete U[i];
    }
    delete[] U;
    U = nullptr;
}

void copy(string& str1, string str2)
{
    for (int i = 0; i < (int)str2.length(); i++)
    {
        str1 += str2[i];
    }
}

void read_jeep(Jeep**& Cc, int& size) 
{
    fstream read;
    read.open("Jeep.txt", ios::in);
    if (read.is_open())
    {
        while (!read.eof()) 
        {
            string Color = "", Num_plate = "", Veh_name = "";
            int Model = 0, Milage = 0, No_of_seats = 0;
            bool Driver = 0;
            double Rent = 0.0;
            bool Rent_status = 0;
            string terrain_type = "";
            string car_type = "", gear_type = "";
            bool off_road_capability = 0;

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
            copy(car_type, temp_str);
            getline(ss, temp_str, ',');
            copy(gear_type, temp_str);
            getline(ss, temp_str, ',');
            if (!temp_str.empty())
            {
                off_road_capability = stoi(temp_str);
            }
            getline(ss, temp_str, ',');
            copy(terrain_type, temp_str);

            expand_jeep_arr(Cc, size);
            Cc[size - 1] = new Jeep(Color, Num_plate, Veh_name, Model, Milage, No_of_seats, Driver, Rent, Rent_status, car_type, gear_type, off_road_capability, terrain_type);
        }
        read.close();
    }
    else 
    {
        cout << "Error Opening File.\n\n";
    }
}

void write_jeep(Jeep**& Cc, int& size)
{
    remove("Jeep.txt");
    fstream write;
    write.open("Jeep.txt", ios::out);

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
            long int temp = static_cast<long int>(Cc[i]->getRent());
            write << temp << ", ";
            write << Cc[i]->getRent_status() << ", ";
            write << Cc[i]->getCar_type() << ", ";
            write << Cc[i]->getGear_type() << ", ";
            write << Cc[i]->getOff_road_capability() << ", ";
            write << Cc[i]->getTerrain_type();
            if (i != size - 1)
            {
                write << endl;
            }
        }

    }
}