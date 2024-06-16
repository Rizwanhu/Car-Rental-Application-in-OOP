#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<cmath>
#include<string>
#include<ctime>
#include <sstream>
#include<stdlib.h>
#include <chrono>
#include <thread>

#include "bscs23122_bscs23140_Vehicle.h"
#include"bscs23122_bscs23140_Car.h"
#include "bscs23122_bscs23140_LuxuryCar.h"
#include "bscs23122_bscs23140_WeddingCar.h"
#include "bscs23122_bscs23140_CasualCar.h"
#include "bscs23122_bscs23140_Truck.h"
#include "bscs23122_bscs23140_Jeep.h"
#include "bscs23122_bscs23140_Person.h"
#include "bscs23122_bscs23140_User.h"

void addUser();
using namespace std;

/*Abstract class->vehicle
* Polymorphism-> implemented by print function
* Inheritance->Multi level inheritance
* Aggregation in user class
* operator overloading->admin
* Exception Handling->read_user_files
*/
string date = "1-04-2024";
void car_menu()
{
	ifstream ini("carrentalsystem.txt");
	char strn[1000];

	while (ini)
	{
		ini.getline(strn, 1000);
		if (ini)
		{
			cout << strn << endl;
		}
	}

	ini.close();
	std::this_thread::sleep_for(std::chrono::seconds(1));

}
bool check_yes_or_no(char a) 
{
	if (a == 'y' || a == 'Y')
		return true;

	return false;
}

void space(int j = 50)
{
	for (int i = 0; i < j; i++)
		cout << " ";
};

bool compare_string(string str1, string str2) 
{
	if (str1.length() == str2.length())
	{
		for (int i = 0; i < (int)str1.length(); i++) 
		{
			if (str1[i] != str2[i]) 
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
};






class Admin :virtual public Person
{
public:
	Admin(string us = "Qureshi") 
	{
		user_id = us;
		password = "Rizwan_Talha";
	}

	void AddLuxuxryCard()
	{
		Luxury_Car** C = nullptr;
		int size = 0;
		read_luxury_car(C, size);
		string Color = "", Num_plate = "", Veh_name = "";
		int Model = 0, Milage = 0, No_of_seats = 0;
		bool Driver = 0;
		double Rent = 0.0;
		bool Rent_status = 0;
		string  Car_type = "", Gear_type = "";
		bool Sun_roof = 0;
		cin.ignore();
		cout << "Enter Color  :";
		getline(cin, Color);
		cout << "Enter Number Plate  :";
		getline(cin, Num_plate);
		cout << "Enter Vehicle Name ";
		getline(cin, Veh_name);
		cout << "Enter model";
		cin >> Model;
		cout << "Enter Milage  :";
		cin >> Milage;
		cout << "Enter Number of seat  :";
		cin >> No_of_seats;
		cin.ignore();
		cout << "Enter Car Type  :";
		getline(cin, Car_type);
		cout << "Enter Car Rent  :";
		cin >> Rent;
		cin.ignore();
		cout << "Enter Gear Type  :";
		getline(cin, Gear_type);
		cout << "Enter Sun Roof status (1 or 0)  :";
		cin >> Sun_roof;
		expand_luxury_car_arr(C, size);
		C[size - 1] = new Luxury_Car(Color, Num_plate, Veh_name, Model, Milage, No_of_seats, 0, Rent, 0, Car_type, Gear_type, Sun_roof);
		write_luxury_car(C, size);
		C = nullptr;
		cout << "Added" << endl;
		system("pause");
	}
	void AddJeep()
	{
		Jeep** C = nullptr;
		int size = 0;
		read_jeep(C, size);
		string Color = "", Num_plate = "", Veh_name = "";
		int Model = 0, Milage = 0, No_of_seats = 0;
		bool Driver = 0;
		double Rent = 0.0;
		bool Rent_status = 0;
		bool off_road_capability;
		string terrain_type, Car_type, Gear_type;
		cin.ignore();
		cout << "Enter Color  :";
		getline(cin, Color);
		cout << "Enter Number Plate  :";
		getline(cin, Num_plate);
		cout << "Enter Vehicle Name ";
		getline(cin, Veh_name);
		cout << "Enter model";
		cin >> Model;
		cout << "Enter Milage  :";
		cin >> Milage;
		cout << "Enter Number of seat  :";
		cin >> No_of_seats;
		cin.ignore();
		cout << "Enter terrain_type";
		getline(cin, terrain_type);
		cout << "Enter Jeep Type  :";
		getline(cin, Car_type);
		cout << "Enter Gear Type  :";
		getline(cin, Gear_type);
		cout << "Enter Jeep Rent  :";
		cin >> Rent;
		cin.ignore();
		cout << "Enter off road capability (1 or 0)  :";
		cin >> off_road_capability;
		expand_jeep_arr(C, size);
		C[size - 1] = new Jeep(Color, Num_plate, Veh_name, Model, Milage, No_of_seats, 0, Rent, 0, Car_type, Gear_type, off_road_capability, terrain_type);
		write_jeep(C, size);
		C = nullptr;
		cout << "Added" << endl;
		system("pause");
	}
	void AddTruck()
	{
		Truck** C = nullptr;
		int size = 0;
		read_truck(C, size);
		string Color = "", Num_plate = "", Veh_name = "";
		int Model = 0, Milage = 0, No_of_seats = 0;
		bool Driver = 0;
		double Rent = 0.0;
		bool Rent_status = 0;
		string  Car_type = "", Gear_type = "";
		int towing_capacity = 0, cardo_capacity = 0, wheeler = 0;
		cin.ignore();
		cout << "Enter Color  :";
		getline(cin, Color);
		cout << "Enter Number Plate  :";
		getline(cin, Num_plate);
		cout << "Enter Vehicle Name ";
		getline(cin, Veh_name);
		cout << "Enter model";
		cin >> Model;
		cout << "Enter Milage  :";
		cin >> Milage;
		cout << "Enter Number of seat  :";
		cin >> No_of_seats;
		cin.ignore();
		cout << "Enter Truck Type  :";
		getline(cin, Car_type);
		cout << "Enter Truck Rent  :";
		cin >> Rent;
		cin.ignore();
		cout << "Enter Gear Type  :";
		getline(cin, Gear_type);
		cout << "Enter Towing capcity  :";
		cin >> towing_capacity;
		cout << "Enter cargo Capacity  :";
		cin >> cardo_capacity;
		cout << "Enter Number of wheel  :";
		cin >> wheeler;
		expand_truck(C, size);
		C[size - 1] = new Truck(Color, Num_plate, Veh_name, Model, Milage, No_of_seats, 0, Rent, 0, Car_type, Gear_type, cardo_capacity, towing_capacity, wheeler);
		write_truck(C, size);
		C = nullptr;
		cout << "Added" << endl;
		system("pause");
	}
	void AddCasualCard() 
	{
		Casual_Car** C = nullptr;
		int size = 0;
		read_casual_car(C, size);
		string Color = "", Num_plate = "", Veh_name = "", Condition = "";
		int Model = 0, Milage = 0, No_of_seats = 0;
		bool Driver = 0;
		double Rent = 0.0;
		bool Rent_status = 0;
		string  Car_type = "", Gear_type = "";
		bool Ac_status = 0;
		cin.ignore();
		cout << "Enter Color  :";
		getline(cin, Color);
		cout << "Enter Number Plate  :";
		getline(cin, Num_plate);
		cout << "Enter Vehicle Name ";
		getline(cin, Veh_name);
		cout << "Enter Condition :";
		getline(cin, Condition);
		cout << "Enter model";
		cin >> Model;
		cin.ignore();
		cout << "Enter Milage  :";
		cin >> Milage;
		cout << "Enter Number of seat  :";
		cin >> No_of_seats;
		cin.ignore();
		cout << "Enter Car Type  :";
		getline(cin, Car_type);
		cout << "Enter Car Rent  :";
		cin >> Rent;
		cin.ignore();
		cout << "Enter Gear Type  :";
		getline(cin, Gear_type);
		cout << "AC Avalaibility (1 or 0)  :";
		cin >> Ac_status;
		expand_casual_car_arr(C, size);
		C[size - 1] = new Casual_Car(Color, Num_plate, Veh_name, Model, Milage, No_of_seats, 0, Rent, 0, Car_type, Gear_type, Condition, Ac_status);
		write_casual_car(C, size);
		C = nullptr;
		cout << "Added" << endl;
		system("pause");
	}
	void AddWeddingCar()
	{
		Wedding_Car** C = nullptr;
		int size = 0;
		read_wedding_car(C, size);
		string Color = "", Num_plate = "", Veh_name = "";
		int Model = 0, Milage = 0, No_of_seats = 0;
		bool Driver = 0;
		double Rent = 0.0;
		bool Rent_status = 0;
		string  Car_type = "", Gear_type = "";
		bool Decor = 0;
		cin.ignore();
		cout << "Enter Color  :";
		getline(cin, Color);
		cout << "Enter Number Plate  :";
		getline(cin, Num_plate);
		cout << "Enter Vehicle Name ";
		getline(cin, Veh_name);
		cout << "Enter model";
		cin >> Model;
		cout << "Enter Milage  :";
		cin >> Milage;
		cout << "Enter Number of seat  :";
		cin >> No_of_seats;
		cin.ignore();
		cout << "Enter Car Type  :";
		getline(cin, Car_type);
		cout << "Enter Car Rent  :";
		cin >> Rent;
		cin.ignore();
		cout << "Enter Gear Type  :";
		getline(cin, Gear_type);
		cout << "Decor Requirement (1 or 0)  :";
		cin >> Decor;
		expand_wedding_car_arr(C, size);
		C[size - 1] = new Wedding_Car(Color, Num_plate, Veh_name, Model, Milage, No_of_seats, 0, Rent, 0, Car_type, Gear_type, Decor);
		write_wedding_car(C, size);
		C = nullptr;
		cout << "Added" << endl;
		system("pause");
	}
	void RegisterUser()
	{
		addUser();
		cout << "Added" << endl;
		system("pause");
	}
	friend ostream& operator << (ostream& os, const Admin& A);
};
ostream& operator << (ostream& os, const Admin& A)
{
	os << "User id  :" << A.user_id << endl;
	os << "Password  :" << A.password << endl;
	return os;
}

void car_message()
{
	system("cls");
	car_menu();


	space(40);
	cout << "What KIND of vehicle you want to rent ?\n\n";
	space(50);
	cout << "1. Casual Car.\n";
	space(50);
	cout << "2. Wedding Car.\n";
	space(50);
	cout << "3. Luxury Car.\n";
	space(50);
	cout << "4. Jeep (4x4).\n";
	space(50);
	cout << "5. Truck.\n";
	space();
	cout << "6. Exit.\n\n";
}

void generate_car_invoice(Car* C, User**& U, int& size, int& user_no) {
	system("cls");
	int Num_of_days = 0;
	car_menu();



	U[user_no]->setVehicle_num_plate(C->getNumPlate());
	U[user_no]->setCar(C);
	cout << "Enter the number of days up to which you want vehicle : ";
	cin >> Num_of_days;
	U[user_no]->setNum_of_days(Num_of_days);

	double mul = ((double)Num_of_days) / 15;

	double bill = (C->getRent()) * mul;
	if (C->getDriver())
		bill += 1500;

	system("cls");
	car_menu();


	space();
	cout << "INVOICE\n";
	space(40);
	cout << "----------------------------------\n";
	space();
	cout << "User id : " << U[user_no]->getUser_id() << endl;
	space();
	cout << "Vehicle name : " << C->getVehName() << endl;
	space();
	cout << "Vehicle number : " << C->getNumPlate() << endl;
	space();
	cout << "Renting for : " << U[user_no]->getNum_of_days() << endl;
	space();
	cout << "Rent per 15 days : Rs." << C->getRent() << endl;
	space();
	cout << "Driver cost : Rs.";
	if (C->getDriver())
		cout << "1500";
	else
		cout << "0";
	cout << endl;
	space(40);
	cout << "----------------------------------\n";
	space();
	cout << "Bill : Rs." << bill << endl;;
	space(40);
	cout << "----------------------------------\n\n";

	cout << "Kindly pay the bill at the counter.\n\n";

	system("pause");


}



void rent_casual_car(User**& U, int& size_u, int& user_no) {
	Casual_Car** Cc = nullptr;
	int size_c = 0;
	string Num_plate = "";
	int car_no = 0;
	read_casual_car(Cc, size_c);
	bool flag = true;
	int counter = 0;

	while (flag)
	{
		system("cls");
		counter++;
		for (int i = 0; i < size_c; i++) {
			if (Cc[i]->getRent_status() == 0) {
				Cc[i]->print();
				cout << endl;
			}
		}
		if (counter > 1)
		{
			cout << "Car not found.\nInvalid Input.\n\a";
		}
		if (counter == 1)
			cin.ignore();

		cout << "From above Enter the Casual Car number (number plate) you want to rent : ";
		getline(cin, Num_plate);
		for (int i = 0; i < size_c; i++) {
			if (compare_string(Cc[i]->getNumPlate(), Num_plate)) {
				flag = false;
				char temp;
				cout << "Do you want driver?\nEnter Y for yes and N for no : ";
				cin >> temp;
				if (check_yes_or_no(temp))
					Cc[i]->setDriver(1);

				car_no = i;
				Cc[i]->setRent_status(1);
				generate_car_invoice(Cc[i], U, size_u, user_no);
				write_casual_car(Cc, size_c);
				deallocate_casual_car_double_arr(Cc, size_c);
				return;
			}
		}
	}


}
void rent_jeep(User**& U, int& size_u, int& user_no) {
	Jeep** Lc = nullptr;
	int size_c = 0;
	string Num_plate = "";
	int car_no = 0;
	read_jeep(Lc, size_c);
	bool flag = true;
	int counter = 0;
	while (flag) {
		system("cls");
		counter++;
		for (int i = 0; i < size_c; i++) {
			if (Lc[i]->getRent_status() == 0) {
				Lc[i]->print();
				cout << endl;
			}
		}
		if (counter > 1) {
			cout << "Car not found.\nInvalid Input.\n\a";
		}
		if (counter == 1)
			cin.ignore();
		cout << "From above Enter the Jeep number (number plate) you want to rent : ";
		getline(cin, Num_plate);
		for (int i = 0; i < size_c; i++) {
			if (compare_string(Lc[i]->getNumPlate(), Num_plate)) {
				char temp;
				flag = false;
				cout << "Do you want driver?\nEnter Y for yes and N for no : ";
				cin >> temp;
				if (check_yes_or_no(temp))
					Lc[i]->setDriver(1);
				car_no = i;
				Lc[i]->setRent_status(1);

				generate_car_invoice(Lc[i], U, size_u, user_no);
				write_jeep(Lc, size_c);
				deallocate_jeep_double_arr(Lc, size_c);
				return;
			}
		}

	}

}


void rent_wedding_car(User**& U, int& size_u, int& user_no) {
	Wedding_Car** Wc = nullptr;
	int size_c = 0;
	string Num_plate = "";
	int car_no = 0;
	read_wedding_car(Wc, size_c);
	bool flag = true;
	int counter = 0;

	while (flag)
	{
		counter++;
		system("cls");
		for (int i = 0; i < size_c; i++) {
			if (Wc[i]->getRent_status() == 0) {
				Wc[i]->print();
				cout << endl;
			}
		}
		if (counter > 1)
		{
			cout << "Car not found.\nInvalid Input.\n\a";
		}
		if (counter == 1)
			cin.ignore();
		cout << "From above Enter the Wedding Car number (number plate) you want to rent : ";
		getline(cin, Num_plate);
		for (int i = 0; i < size_c; i++) {
			if (compare_string(Wc[i]->getNumPlate(), Num_plate)) {
				char temp;
				cout << "\nDo you want decor?\nEnter Y for yes and N for no : ";
				cin >> temp;
				if (check_yes_or_no(temp))
					Wc[i]->setDecor(1);
				cout << "\nDo you want driver?\nEnter Y for yes and N for no : ";
				cin >> temp;
				if (check_yes_or_no(temp))
					Wc[i]->setDriver(1);

				car_no = i;
				Wc[i]->setRent_status(1);

				generate_car_invoice(Wc[i], U, size_u, user_no);
				write_wedding_car(Wc, size_c);
				deallocate_wedding_car_double_arr(Wc, size_c);
				return;
			}
		}
	}
	cout << "Car not found.\n\n";

}

void rent_luxury_car(User**& U, int& size_u, int& user_no) {
	Luxury_Car** Lc = nullptr;
	int size_c = 0;
	string Num_plate = "";
	int car_no = 0;
	read_luxury_car(Lc, size_c);
	bool flag = true;
	int counter = 0;
	while (flag) {
		system("cls");
		counter++;
		for (int i = 0; i < size_c; i++) {
			if (Lc[i]->getRent_status() == 0) {
				Lc[i]->print();
				cout << endl;
			}
		}
		if (counter > 1) {
			cout << "Car not found.\nInvalid Input.\n\a";
		}
		cin.ignore();
		cout << "From above Enter the Luxury Car number (number plate) you want to rent : ";
		getline(cin, Num_plate);
		for (int i = 0; i < size_c; i++) {
			if (compare_string(Lc[i]->getNumPlate(), Num_plate)) {
				char temp;
				flag = false;
				cout << "Do you want driver?\nEnter Y for yes and N for no : ";
				cin >> temp;
				if (check_yes_or_no(temp))
					Lc[i]->setDriver(1);
				car_no = i;
				Lc[i]->setRent_status(1);

				generate_car_invoice(Lc[i], U, size_u, user_no);
				write_luxury_car(Lc, size_c);
				deallocate_luxury_car_double_arr(Lc, size_c);
				return;
			}
		}

	}

}

void rent_truck(User**& U, int& size_u, int& user_no)
{
	Truck** Lc = nullptr;
	int size_c = 0;
	string Num_plate = "";
	int car_no = 0;
	read_truck(Lc, size_c);
	bool flag = true;
	int counter = 0;
	while (flag) {
		system("cls");
		counter++;
		for (int i = 0; i < size_c; i++) {
			if (Lc[i]->getRent_status() == 0) {
				Lc[i]->print();
				cout << endl;
			}
		}
		if (counter > 1) {
			cout << "Car not found.\nInvalid Input.\n\a";
		}
		if (counter == 1)
			cin.ignore();
		cout << "From above Enter the Jeep number (number plate) you want to rent : ";
		getline(cin, Num_plate);
		for (int i = 0; i < size_c; i++) {
			if (compare_string(Lc[i]->getNumPlate(), Num_plate)) {
				char temp;
				flag = false;
				cout << "Do you want driver?\nEnter Y for yes and N for no : ";
				cin >> temp;
				if (check_yes_or_no(temp))
					Lc[i]->setDriver(1);
				car_no = i;
				Lc[i]->setRent_status(1);

				generate_car_invoice(Lc[i], U, size_u, user_no);
				write_truck(Lc, size_c);
				deallocate_double_truck_arr(Lc, size_c);
				return;
			}
		}

	}

}

void user_rent_car(User**& U, int& size, int& user_no) {

	int counter = 0;

	while (1) {

		int count = 0;
		int choice = 0;
		counter++;
		if (counter > 1) {
			expand_user_arr(U, size);

			U[size - 1] = new User(U[user_no]->getUser_id(), U[user_no]->getPassword(), nullptr, 0);
			user_no = size - 1;
		}
		while (choice <= 0 || choice >= 7) {
			count++;
			car_message();
			if (count > 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input.\n\a";
			}
			cout << "Enter your choice : ";
			cin >> choice;

		}
		if (choice == 1)
			rent_casual_car(U, size, user_no);
		else if (choice == 2)
			rent_wedding_car(U, size, user_no);
		else if (choice == 3)
			rent_luxury_car(U, size, user_no);
		else if (choice == 4)
			rent_jeep(U, size, user_no);
		else if (choice == 5)
			rent_truck(U, size, user_no);
		else if (choice == 6)
			break;

	}
	return;
}


void sort(User**& U, int& size, int& user_no) {
	swap(U[0], U[user_no]);
	user_no = 0;
	for (int i = 1; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (compare_string(U[user_no]->getUser_id(), U[i]->getUser_id()) && U[i]->getNum_of_days() == 0) {
				swap(U[i], U[j]);
			}
		}
	}
}



bool reset_Car_values(User**& U_temp, int& size_t, Casual_Car**& Cc, Wedding_Car**& Wc, Luxury_Car**& Lc, Jeep**& J, Truck**& T, int size_c, int size_w, int size_l, int size_j, int size_tr, string Num_plate) {

	for (int i = 0; i < size_t; i++) {
		if (compare_string(U_temp[i]->getVehicle_num_plate(), Num_plate)) {

			for (int j = 0; j < size_c; j++) {
				if (compare_string(Cc[j]->getNumPlate(), Num_plate)) {
					Cc[j]->setRent_status(0);
					Cc[j]->setDriver(0);
					break;
				}
			}

			for (int j = 0; j < size_w; j++) {
				if (compare_string(Wc[j]->getNumPlate(), Num_plate)) {
					Wc[j]->setRent_status(0);
					Wc[j]->setDriver(0);
					Wc[j]->setDecor(0);
					break;
				}
			}

			for (int j = 0; j < size_l; j++) {

				if (compare_string(Lc[j]->getNumPlate(), Num_plate)) {

					Lc[j]->setRent_status(0);
					Lc[j]->setDriver(0);
					break;
				}
			}

			for (int j = 0; j < size_j; j++) {
				if (compare_string(J[j]->getNumPlate(), Num_plate)) {
					J[j]->setRent_status(0);
					J[j]->setDriver(0);
					break;
				}
			}


			for (int j = 0; j < size_tr; j++) {
				if (compare_string(T[j]->getNumPlate(), Num_plate)) {
					T[j]->setRent_status(0);
					T[j]->setDriver(0);
					break;
				}
			}

			U_temp[i]->setVehicle_num_plate("");
			U_temp[i]->setNum_of_days(0);
			return true;
		}
	}

	return false;
}


void reduce_user_arr(User**& U, int& size) {
	User** temp = new User * [size - 1];

	for (int i = 0; i < size - 1; i++) {
		temp[i] = new User(U[i]->getUser_id(), U[i]->getPassword(), U[i]->getCar(), U[i]->getNum_of_days());
	}

	deallocate_user_double_arr(U, size);
	size--;
	U = temp;
	temp = nullptr;

}

int count_user_occurrence(User**& U, int user_no, int size) {
	int count = 0;
	for (int i = 0; i < size; i++)
		if (compare_string(U[user_no]->getUser_id(), U[i]->getUser_id()) && U[i]->getNum_of_days() == 0 && user_no != i)
			count++;
	return count;
}


void user_return_car(User**& U, int& size, int& user_no) {

	//cout << "*************************\n";

	User** U_temp = nullptr;
	int size_t = 0;
	for (int i = 0; i < size; i++) {
		if (compare_string(U[i]->getUser_id(), U[user_no]->getUser_id()) && U[i]->getNum_of_days() != 0 && user_no != i) {
			expand_user_arr(U_temp, size_t);
			U_temp[size_t - 1] = U[i];
		}
	}
	/*U_temp[size_t - 1]->print();
	system("pause");*/

	if (U_temp != nullptr) {
		Truck** T = nullptr;
		Casual_Car** Cc = nullptr;
		Wedding_Car** Wc = nullptr;
		Luxury_Car** Lc = nullptr;
		Jeep** J = nullptr;
		int size_c = 0;
		int size_w = 0;
		int size_l = 0;
		int size_j = 0;
		int size_tr = 0;
		read_truck(T, size_tr);
		read_casual_car(Cc, size_c);
		read_wedding_car(Wc, size_w);
		read_luxury_car(Lc, size_l), read_jeep(J, size_j);;

		for (int i = 0; i < size_t; i++) {
			for (int j = 0; j < size_c; j++) {
				if (compare_string(U_temp[i]->getVehicle_num_plate(), Cc[j]->getNumPlate())) {
					Cc[j]->print();
				}

			}

			for (int j = 0; j < size_w; j++) {
				if (compare_string(U_temp[i]->getVehicle_num_plate(), Wc[j]->getNumPlate())) {
					Wc[j]->print();
				}

			}

			for (int j = 0; j < size_l; j++) {
				if (compare_string(U_temp[i]->getVehicle_num_plate(), Lc[j]->getNumPlate())) {
					Lc[j]->print();
				}

			}
			for (int j = 0; j < size_j; j++) {
				if (compare_string(U_temp[i]->getVehicle_num_plate(), J[j]->getNumPlate())) {
					J[j]->print();
				}

			}

			for (int j = 0; j < size_tr; j++) {
				if (compare_string(U_temp[i]->getVehicle_num_plate(), T[j]->getNumPlate())) {
					T[j]->print();
				}

			}


		}
		string Num_plate = "";
		cin.ignore();
		cout << "Enter the number plate of Car you want to return : ";
		getline(cin, Num_plate);

		if (reset_Car_values(U_temp, size_t, Cc, Wc, Lc, J, T, size_c, size_w, size_l, size_j, size_tr, Num_plate)) {
			sort(U, size, user_no);
			reduce_user_arr(U, size);
			write_user_file(U, size);
			write_casual_car(Cc, size_c);
			write_wedding_car(Wc, size_w);
			write_luxury_car(Lc, size_l), write_jeep(J, size_j);
			write_truck(T, size_tr);
			cout << "Car Returned Successfully.\n\n";

			deallocate_casual_car_double_arr(Cc, size_c);
			deallocate_wedding_car_double_arr(Wc, size_w);
			deallocate_luxury_car_double_arr(Lc, size_l);
			deallocate_jeep_double_arr(J, size_j);
			deallocate_double_truck_arr(T, size_tr);

			system("pause");
		}

	}
}

void second_main_menu(User**& U, int& size, int& user_no) {
	while (1) {
		int choice = 0;
		int counter = 0;
		while (choice <= 0 || choice >= 5) {
			system("cls");
			counter++;
			car_menu();


			space();
			cout << "PURPOSE OF VISIT.\n\n";
			space();
			cout << "1. Rent a Vehicle.\n";
			space();
			cout << "2. Return a Vehicle.\n";
			space();
			cout << "3. Exit.\n\n";


			if (counter > 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input.\n\a";
			}
			cout << "Enter your choice : ";
			cin >> choice;
		}

		if (choice == 1) {
			user_rent_car(U, size, user_no);
		}
		else if (choice == 2)
			user_return_car(U, size, user_no);
		else if (choice == 3)
			break;
	}
	system("pause");
}
void first_main_menu() {
	User** U = nullptr;
	int size_u = 0;
	read_user_file(U, size_u);

	bool flag = true;
	int count = 0;
	//system("Cls");
	cin.ignore();
	while (flag) {
		count++;
		system("Cls");
		car_menu();

		string User_id = "basim123", Password = "basimpassword";
		if (count > 1) {
			cout << "User not found.\n\a";
		}

		cout << "Enter your User_id : ";
		getline(cin, User_id);
		cout << "\nEnter you password : ";
		getline(cin, Password);
		int user_no = 0;

		int counter = 0;
		for (int i = 0; i < size_u; i++) {
			if (compare_string(U[i]->getUser_id(), User_id) && compare_string(U[i]->getPassword(), Password)) {
				if (U[i]->getNum_of_days() == 0) {
					flag = false;
					user_no = i;
					second_main_menu(U, size_u, user_no);
					sort(U, size_u, user_no);
					counter = count_user_occurrence(U, user_no, size_u);
					while (counter > 1) {
						sort(U, size_u, user_no);
						reduce_user_arr(U, size_u);
						counter = count_user_occurrence(U, user_no, size_u);
					}
					write_user_file(U, size_u);
					deallocate_user_double_arr(U, size_u);
					return;
				}
				else {
					flag = false;
					system("Cls");

					car_menu();

					space(40);
					cout << "Be vigilant to return the prevoius car in time.\n";
					system("pause");
					expand_user_arr(U, size_u);
					U[size_u - 1] = new User(U[i]->getUser_id(), U[i]->getPassword(), nullptr, 0);
					user_no = size_u - 1;
					second_main_menu(U, size_u, user_no);
					sort(U, size_u, user_no);
					counter = count_user_occurrence(U, user_no, size_u);
					while (counter > 1) {
						sort(U, size_u, user_no);
						reduce_user_arr(U, size_u);
						counter = count_user_occurrence(U, user_no, size_u);

					}
					write_user_file(U, size_u);
					deallocate_user_double_arr(U, size_u);
					return;
				}

			}

		}

	}
}
bool check_user_existence(User**& U, int& size, string user_id) {
	read_user_file(U, size);
	for (int i = 0; i < size; i++) {
		if (compare_string(U[i]->getUser_id(), user_id)) {
			return true;
		}

	}
	return false;
}
//Rizwan
/*
Add user function simple add username and password to user.txt so it is added as user
and secondly it also checks for already existance of a username
*/
void addUser() {
	User** U = nullptr;
	int size = 0;
	string username, password;
	int count = 0;
	do {
		U = nullptr;
		size = 0;
		if (count == 0) {
			cout << "Enter Username  :";
		}
		else {
			cout << "User name Alrady Exist try again  :";
		}
		cin >> username;
		count++;
	} while (check_user_existence(U, size, username));
	cout << "Enter Password  :";
	cin >> password;
	expand_user_arr(U, size);
	U[size - 1] = new User(username, password);
	write_user_file(U, size);
	U = nullptr;
}
//Admin login
void admin_login(Admin A) {
	string user_id;
	string password;
	int count = 0;
	do {
		if (count == 0) {
			cout << "Enter Admin id  :";
			cin >> user_id;
			cout << "Enter password  :";
			cin >> password;
			count++;
		}
		else {
			cout << endl << endl << "Wrong credentials" << endl << endl;
			cout << "Enter Valid Admin id  :";
			cin >> user_id;
			cout << "Enter Valid password  :";
			cin >> password;
		}
	} while (compare_string(A.getUser_id(), user_id) == 0 || compare_string(A.getPassword(), password) == 0);
	cout << "Logged In as Admin" << endl << endl;
}
void user_menu()
{
	while (true)
	{
		system("Cls");
		int choice = 0;
		car_menu();

		space(); cout << "1.Register\n";
		space(); cout << "2.Login\n";
		space(); cout << "3.Exit.\n\n";
		space(); cout << "Enter choice  :";
		cin >> choice;
		while (choice <= 0 || choice >= 4)
		{
			system("cls");
			car_menu();

			space(); cout << "1.Register\n";
			space(); cout << "2.Login\n";
			space(); cout << "3.Exit.\n\n";
			space();
			cout << "invalid Option Selected.\n\a";
			space(); cout << "Enter valid choice : ";
			cin >> choice;
		}

		if (choice == 1)
		{
			addUser();
			system("cls");
			first_main_menu();
		}
		else if (choice == 2)
			first_main_menu();
		else
			break;

	}


}
void admin_functions(Admin A)
{
	while (true)
	{
		int counter = 0;
		int choice = 0;

		while (counter <= 0 || counter >= 9)
		{
			counter++;
			system("Cls");
			car_menu();


			space(); cout << "1. Add Casual Car.\n";
			space(); cout << "2. Add Luxury Car.\n";
			space(); cout << "3. Add Wedding Car.\n";
			space(); cout << "4. Add Jeep.\n";
			space(); cout << "5. Add Truck.\n";
			space(); cout << "6. Add New User.\n";
			space(); cout << "7. View Credentials\n";
			space(); cout << "8. Exit.\n";

			if (counter > 1)
			{
				cout << "Invalid Input.\n\a";
			}

			cout << "Enter choice : "; cin >> choice;

		}

		if (choice == 1)
			A.AddCasualCard();
		else if (choice == 2)
			A.AddLuxuxryCard();
		else if (choice == 3)
			A.AddWeddingCar();
		else if (choice == 4)
			A.AddJeep();
		else if (choice == 5)
			A.AddTruck();
		else if (choice == 6)
			A.RegisterUser();
		else if (choice == 7)
		{
			cout << A;
			system("pause");
		}
		else
			break;

	}

}
void home_page()
{
	while (true)
	{
		int choice = 0;
		int counter = 0;
		while (choice <= 0 || choice >= 4)
		{
			counter++;
			system("Cls");
			car_menu();

			space(); cout << "1. Admin.\n";
			space(); cout << "2. User.\n";
			space(); cout << "3. Exit.\n\n";

			if (counter > 1)
				cout << "Invalid Input.\n\a";

			cout << "Enter Choice : "; cin >> choice;
		}
		if (choice == 1)
		{
			Admin A;
			admin_login(A);
			admin_functions(A);

		}
		else if (choice == 2)
		{
			user_menu();
		}
		else
			break;

	}

}
void starting_menu()
{
	ifstream wel("start.txt");
	char str[1000];

	while (wel) {
		wel.getline(str, 1000);
		if (wel) {
			cout << str << endl;
		}
	}

	wel.close();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	car_menu();
	home_page();
}
int main() {
	srand(time(0));
	system("color B5");
	starting_menu();
	return 0;
}