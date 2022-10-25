//
//  contact.hpp
//  phonebook
//
//  Created by leon on 24/10/2022.
//

#ifndef contact_hpp
#define contact_hpp

#include <string>
 
using namespace std;
 
class contact {
    string fullName;
    string phoneNumber;
public:
    contact();
    contact(string name, string number);
    contact(const contact& other);
 
    string getFullName();
    string getPhoneNumber();
    bool setFullName(string);
    bool setPhoneNumber(string);
};
#endif /* contact_hpp */