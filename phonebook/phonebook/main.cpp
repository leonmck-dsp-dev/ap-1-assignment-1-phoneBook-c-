//
//  main.cpp
//  phonebook
//
//  Created by leon on 24/10/2022.
//
 #include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "contact.hpp"
#include "PhoneDirectory.hpp"
 
using namespace std;

phoneDirectory *phonebook;

void readFromFile()
{
    ifstream file;
    file.open("phonebook.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            string name = line.substr(0, line.find(","));
            string number = line.substr(line.find(",") + 1, line.length());
            contact newContact(name, number);
            phonebook->addContact(newContact);
        }
    }
    file.close();
}

int main(int argc, char ** argv)
{
    phonebook = new phoneDirectory();
    readFromFile();
    cout << "Welcome to the phonebook" << endl;
    cout << "Please select an option" << endl;
    cout << "1. Add a contact" << endl;
    cout << "2. Remove a contact" << endl;
    cout << "3. Update a contact" << endl;
    cout << "4. Search by name" << endl;
    cout << "5. Search by number" << endl;
 
    int option;
    cin >> option;
    switch (option)
    {
        case 1:
        {
            cout << "Please enter the name of the contact" << endl;
            string name;
            cin >> name;
            cout << "Please enter the number of the contact" << endl;
            string number;
            cin >> number;
            contact newContact(name, number);
            if (phonebook->addContact(newContact))
            {
                cout << "Contact added successfully" << endl;
            }
            else
            {
                cout << "Contact already exists" << endl;
            }
            break;
        }
        case 2:
        {
            cout << "Please enter the name of the contact" << endl;
            string name;
            cin >> name;
            if (phonebook->removeContact(name))
            {
                cout << "Contact removed successfully" << endl;
            }
            else
            {
                cout << "Contact does not exist" << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Please enter the name of the contact" << endl;
            string name;
            cin >> name;
            cout << "Please enter the new number of the contact" << endl;
            string number;
            cin >> number;
            contact newContact(name, number);
            if (phonebook->updateContact(name, newContact))
            {
                cout << "Contact updated successfully" << endl;
            }
            else
            {
                cout << "Contact does not exist" << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Please enter the name of the contact" << endl;
            string name;
            cin >> name;
            list<contact> results = phonebook->searchbyName(name);
            if (results.size() == 0)
            {
                cout << "No results found" << endl;
            }
            else
            {
                for (list<contact>::iterator it = results.begin(); it != results.end(); it++)
                {
                    cout << it->getFullName() << " " << it->getPhoneNumber() << endl;
                }
            }
            break;
        }
        case 5:
        {
            cout << "Please enter the number of the contact" << endl;
            string number;
            cin >> number;
            list<contact> results = phonebook->searchbyNumber(number);
            if (results.size() == 0)
        {  
             cout << "No results found" << endl;

        }
        else
        {
            for (list<contact>::iterator it = results.begin(); it != results.end(); it++)
            {
                cout << it->getFullName() << " " << it->getPhoneNumber() << endl;
            }
        }
    }
}
}