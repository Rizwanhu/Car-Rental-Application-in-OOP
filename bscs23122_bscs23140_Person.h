#pragma once
#include <string>
#include <cstdlib> 
using namespace std;

class Person
{
protected:
    string user_id;
    string password;

public:
    Person(string User_id = "", string Password = "");

    void generate_password();
    void setpassword(string a);
    void setUser_id(string a);

    string getUser_id();
    string getPassword();
};