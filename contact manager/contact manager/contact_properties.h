//
// Created by leon on 26/10/2022.
//

#ifndef CMS_CONTACT_PROPERTIES_H
#define CMS_CONTACT_PROPERTIES_H
#include <string>


using namespace std;

class contact_properties {

public:
struct contact {
    string name;
    string phone;
    string email;
    string address;
};
  
    contact_properties();
    contact_properties(string name, string phone, string email, string address);
     bool set_name(string name);
     bool set_phone(string phone);
     bool set_email(string email);
     bool set_address(string address);
     string get_name();
     string get_phone();
     string get_email();
     string get_address();
     void print_contact();
private:
    string name;
    string phone;
    string email;
    string address;
};


#endif //CMS_CONTACT_PROPERTIES_H
