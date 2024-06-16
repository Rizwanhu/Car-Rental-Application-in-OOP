#include "bscs23122_bscs23140_Person.h"

Person::Person(string User_id, string Password) : user_id(User_id), password(Password) {}

void Person::generate_password()
{
    int length = 6;
    password = "";
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz123456789";
    for (int i = 0; i < length; i++) 
    {
        password += str[rand() % (61)];
    }
}

void Person::setpassword(string a)
{
    password = a;
}

void Person::setUser_id(string a)
{
    user_id = a;
}

string Person::getUser_id() 
{
    return user_id;
}

string Person::getPassword()
{
    return password;
}
