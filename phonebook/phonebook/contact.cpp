//
//  contact.cpp
//  phonebook
//
//  Created by leon on 24/10/2022.
//
#include <string.h>
#include "contact.hpp"
// default constructor
contact::contact()
{
    fullName = "(Anonymous)";
    phoneNumber = "0";

}
// constructor with parameters
contact::contact(string name, string number)
{
    fullName = name;
    phoneNumber = number;
}

// copy constructor
contact::contact(const contact& other)
{
    fullName = other.fullName;
    phoneNumber = other.phoneNumber;
}

// return the full name of the contact
string contact::getFullName()
{
    return fullName;
}

// return the phone number of the contact
string contact::getPhoneNumber()
{
    return phoneNumber;
}

// user input for the full name of the contact
bool contact::setFullName(string name)
{
    if (name.length() > 0)
    {
        fullName = name;
        return true;
    }
    else
    {
        return false;
    }
}

// user input for the phone number of the contact
bool contact::setPhoneNumber(string number)
{
    if (number.length() == 10)
    {
        phoneNumber = number;
        return true;
    }
    else
    {
        return false;
    }
     
}