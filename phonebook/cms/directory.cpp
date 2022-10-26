//
// Created by leon on 26/10/2022.
//

#include "directory.h"
#include <iostream>
#include <iterator>

directory::directory() {
    file_name = "contacts.txt";
}

bool directory::add_contact(contact_properties contact) {
     string firstName;
     string lastName;
     cout << "Enter name: ";
        cin >> firstName >> lastName;
        contact.set_name(firstName + " " + lastName);

     string phone;
        cout << "Enter phone number: ";
            cin >> phone;
            contact.set_phone(phone);

     string email;
        cout << "Enter email: ";
            cin >> email;
            contact.set_email(email);

     string address;
        cout << "Enter address: ";
            cin >> address;
            contact.set_address(address);

    contacts.push_back(contact);
    return true;
}

bool directory::remove_contact(contact_properties contact) {

    // itterate through the list
    for (list<contact_properties>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
        // if the contact is found
        if (it->get_name() == contact.get_name()) {
            // remove the contact
            contacts.erase(it);
            return true;
        }
    }
}

bool directory::search_contact(contact_properties contact) {
    // itterate again
    for (list<contact_properties>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
        // if the contact is found
        if (it->get_name() == contact.get_name()) {
            // print the contact
            it->print_contact();
            return true;
        }
    }
}

bool directory::update_contact(contact_properties contact) {
    // itterate again
    for (list<contact_properties>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
        // if the contact is found
        if (it->get_name() == contact.get_name()) {
            // update the contact
            string firstName;
            string lastName;
            cout << "Enter name: ";
            cin >> firstName >> lastName;
            it->set_name(firstName + " " + lastName);

            string phone;
            cout << "Enter phone number: ";
            cin >> phone;
            it->set_phone(phone);

            string email;
            cout << "Enter email: ";
            cin >> email;
            it->set_email(email);

            string address;
            cout << "Enter address: ";
            cin >> address;
            it->set_address(address);
            return true;
        }
    }
}

void directory::print_directory() {
    // itterate again
    for (list<contact_properties>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
        // print the contact
        it->print_contact();
    }
}

bool directory::write_to_file() {
    // open the file
    ofstream file;
    file.open(file_name);
    // itterate again
    for (list<contact_properties>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
        // write the contact to the file
        file << it->get_name() << endl;
        file << it->get_phone() << endl;
        file << it->get_email() << endl;
        file << it->get_address() << endl;
    }
    // close the file
    file.close();
    return true;
}

bool directory::read_from_file() {
    // open the file
    ifstream file;
    file.open(file_name);
    // itterate again
    for (list<contact_properties>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
        // read the contact from the file
        string name;
        string phone;
        string email;
        string address;
        getline(file, name);
        getline(file, phone);
        getline(file, email);
        getline(file, address);
        it->set_name(name);
        it->set_phone(phone);
        it->set_email(email);
        it->set_address(address);
    }
    // close the file
    file.close();
    return true;
}

bool directory::readcontcts(string firstNames, string lastNames, string phone, string email, string address) {
    // open the file
    ifstream file;
    file.open(file_name);
    // itterate again
    for (list<contact_properties>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
        // read the contact from the file
        string name;
        string phone;
        string email;
        string address;
        getline(file, name);
        getline(file, phone);
        getline(file, email);
        getline(file, address);
        it->set_name(name);
        it->set_phone(phone);
        it->set_email(email);
        it->set_address(address);
    }
    // close the file
    file.close();
    return true;
}


