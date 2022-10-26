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
    ~directory();

    bool add_contact(contact_properties contact);
    bool remove_contact(contact_properties contact);
    bool search_contact(contact_properties contact);
    bool update_contact(contact_properties contact);
    void print_directory();
    bool write_to_file();
    bool read_from_file();
    bool readcontcts (string firstNames, string lastNames, string phone, string email, string address);

private:
    list<contact_properties> contacts;
    string file_name;
};


#endif //CMS_DIRECTORY_H
