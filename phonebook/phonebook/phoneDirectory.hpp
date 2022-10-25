//
//  phoneDirectory.hpp
//  phonebook
//
//  Created by leon on 24/10/2022.
//
#ifndef phoneDirectory_hpp
#define phoneDirectory_hpp
#include "phoneDirectory.hpp"
#include <string>
#include <list>
#include  "contact.hpp"

using namespace std;

class phoneDirectory {
        int numberOfContacts;
    list<contact> contacts;
public:
    phoneDirectory();
    bool addContact(contact);
    bool removeContact(contact);
    bool removeContact(string);
    bool updateContact(string, contact); 
    list<contact> searchbyName(string);
    list<contact> searchbyNumber(string);
    void listallcontacts();
};                  



#endif /* phoneDirectory_hpp */