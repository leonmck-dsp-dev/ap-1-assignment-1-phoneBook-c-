//
// Created by leon on 26/10/2022.
//

#ifndef CMS_DIRECTORY_H
#define CMS_DIRECTORY_H

#include <string>
#include <list>
#include <fstream>
#include "contact_properties.h"

class directory {

public:
    directory();
    //11//
    bool add_contact();
    bool findContactToRemove(string first , string last);
    bool removeContact();
    bool search_contact();
    bool update_contact();
    void print_directory();
    bool write_to_file();
    bool read_from_file();
    bool readcontact();
    bool printcontact();
    private:

// initialize contact object
    contact_properties contact;
    // initialize list of contacts
    list<contact_properties> contacts;
    string file_name;
};


#endif //CMS_DIRECTORY_H
