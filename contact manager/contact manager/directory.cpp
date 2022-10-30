//
// Created by leon on 26/10/2022.
//

#include "directory.h"
#include <iostream>
#include <fstream>
#include <iterator>

directory::directory() {
    file_name = "contacts.txt";
}

//adds a contact to the directory
bool directory::add_contact() {
     string firstName;
     string lastName;
     cout << "Enter name: ";
        cin >> firstName >> lastName;
        contact.set_name (firstName + " " + lastName);

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

//finds a contact to remove
bool directory::findContactToRemove(string first , string last) {

    // itterate through the list
    for (list<contact_properties>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
        // if the contact is found
        if (it->get_name() == contact.get_name()) {
            // remove the contact
            contacts.erase(it);
            return true;
        }
    }
    return 0;
}

//removes a contact from the directory
bool directory::removeContact() {
    string firstName;
    string lastName;
    cout << "Enter name: ";
    cin >> firstName >> lastName;
    contact.set_name (firstName + " " + lastName);

    // if the contact is found
    if (findContactToRemove(firstName, lastName)) {
        cout << "Contact removed" << endl;
        return true;
    }
    // if the contact is not found
    else {
        cout << "Contact not found" << endl;
        return false;
    }
}

//searches for a contact in the directory
bool directory::search_contact() {
    // itterate again
    for (list<contact_properties>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
        // if the contact is found
        if (it->get_name() == contact.get_name()) {
            // print the contact
            it->print_contact();
            return true;
        }
    }
    
    return 0;
    
}

//updates a contact in the directory
bool directory::update_contact() {
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
    
    return 0;
    
}


//prints the directory
void directory::print_directory() {
    // Get contact info from printcontact function
    printcontact();
}
//prints contact information
bool directory::printcontact() {
    // itterate again
    for (list<contact_properties>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
        // print the contact
        it->get_name();
        it->get_phone();
        it->get_email();
        it->get_address();
        return true;
    }
    return true;
}
//writes the directory to a file
bool directory::write_to_file() {
    // open the file
    
    ofstream file;
    
    
    file.open("./directory.txt", ios::app);
    
    // if the file is not open
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return -1;
    }
    // innitialize variables
    list<contact_properties>::iterator it;
    string name, phone, email, address;
    // IF the file is open
    if (file.is_open()) {
        // itterate again
        for (it = contacts.begin(); it != contacts.end(); ++it) {
            // get the contact info
            name = it->get_name();
            phone = it->get_phone();
            email = it->get_email();
            address = it->get_address();
            // write the contact info to the file
            file << " " << name << " " << phone << " " << email << " " << address;
        }
        // close the file
        file.close();
        return true;            
        
        
    }   
    // close the file
    file.close();
    return true;
}

//reads the directory from a file
bool directory::read_from_file() {
    // open the file
    ifstream file;
    file.open("../directory.txt");
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

//reads a contact from the directory
bool directory::readcontact() {
    // itterate again
    for (list<contact_properties>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
        // if the contact is found
        if (it->get_name() == contact.get_name()) {
            // read the contact
            contact = *it;
            return true;
        }
    }
    return 0;
}
