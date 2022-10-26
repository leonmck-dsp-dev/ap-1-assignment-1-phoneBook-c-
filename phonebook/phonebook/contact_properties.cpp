//
// Created by leon on 26/10/2022.
//

#include "contact_properties.h"
#include <iostream>



contact_properties::contact_properties() {
    name = "";
    phone = "";
    email = "";
    address = "";
}


contact_properties::contact_properties(string name, string phone, string email, string address) {
    this->name = name;
    this->phone = phone;
    this->email = email;
    this->address = address;
}

bool contact_properties::set_name(string name) {
    this->name = name;
    return true;
}

bool contact_properties::set_phone(string phone) {
    this->phone = phone;
    return true;
}

bool contact_properties::set_email(string email) {
    this->email = email;
    return true;
}

bool contact_properties::set_address(string address) {
    this->address = address;
    return true;
}

string contact_properties::get_name() {
    return name;
}

string contact_properties::get_phone() {
    return phone;
}

string contact_properties::get_email() {
    return email;
}

string contact_properties::get_address() {
    return address;
}

void contact_properties::print_contact() {
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Email: " << email << endl;
    cout << "Address: " << address << endl;
}