//
//  phoneDirectory.cpp
//  phonebook
//
//  Created by leon on 24/10/2022.
//
#include <string>
#include <list>
#include <iostream>
#include "phoneDirectory.hpp"
#include "contact.hpp"

using namespace std;

phoneDirectory::phoneDirectory()
{
    contacts = list<contact>();
}
// Add a contact to the phone directory
bool phoneDirectory::addContact(contact newContact)
{
    if (numberOfContacts == 0)
    {
        contacts.push_back(newContact);
        numberOfContacts++;
        return true;
    }
    else
    {
        for (list<contact>::iterator it = contacts.begin(); it != contacts.end(); it++)
        {
            if (it->getFullName() == newContact.getFullName())
            {
                return false;
            }
        }
        contacts.push_back(newContact);
        numberOfContacts++;
        return true;
    }
    
}
//remove contact 
bool phoneDirectory::removeContact(contact oldContact)
{
    if (numberOfContacts == 0)
    {
        return false;
    }
    else
    {
        for (list<contact>::iterator it = contacts.begin(); it != contacts.end(); it++)
        {
            if (it->getFullName() == oldContact.getFullName())
            {
                contacts.remove(oldContact);
                numberOfContacts--;
                return true;
            }
        }
        return false;
    }
} 

// update contact
bool phoneDirectory::updateContact(string name, contact newContact)
{
    if (numberOfContacts == 0)
    {
        return false;
    }
    else
    {
        for (list<contact>::iterator it = contacts.begin(); it != contacts.end(); it++)
        {
            if (it->getFullName() == newContact.getFullName())
            {
                contacts.remove(newContact);
                contacts.push_back(newContact);
                return true;
            }
        }
        return false;
    }
}
// search by name
list<contact> phoneDirectory::searchbyName(string name)
{
    list<contact> searchResults;
    if (numberOfContacts == 0)
    {
        return searchResults;
    }
    else
    {
        for (list<contact>::iterator it = contacts.begin(); it != contacts.end(); it++)
        {
            if (it->getFullName() == name)
            {
                searchResults.push_back(*it);
            }
        }
        return searchResults;
    }
}

// search by number
list<contact> phoneDirectory::searchbyNumber(string number)
{
    list<contact> searchResults;
    if (numberOfContacts == 0)
    {
        return searchResults;
    }
    else
    {
        for (list<contact>::iterator it = contacts.begin(); it != contacts.end(); it++)
        {
            if (it->getPhoneNumber() == number)
            {
                searchResults.push_back(*it);
            }
        }
        return searchResults;
    }
}

// list all contacts
void phoneDirectory::listallcontacts()
{
    if (numberOfContacts == 0)
    {
        cout << "No contacts in the phone directory" << endl;
    }
    else
    {
        for (list<contact>::iterator it = contacts.begin(); it != contacts.end(); it++)
        {
            cout << it->getFullName() << " " << it->getPhoneNumber() << endl;
        }
    }
}

