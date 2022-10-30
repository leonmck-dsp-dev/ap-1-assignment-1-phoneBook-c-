#include <iostream>
#include <string>
#include <list>
#include <fstream>

#include "contact_properties.h"
#include "directory.h"


using namespace std;


// function prototypes
//bool read_file(directory &dir);
void print_menu();
char get_user_input();
bool quit_program(directory &dir ); //TODO: implement this

// main function
int main() {
    // create a directory object
    directory dir;
    // read the file
    dir.read_from_file();
    // print the menu
    print_menu();
    // get the user input
    char user_input = get_user_input();
    bool quit = false;
    // loop until the user quits
    do{ 
    switch (user_input) {
        case '1':
            // add a contact
        dir.add_contact();
            break;
        case '2':
            // remove a contact
            dir.removeContact();
            break;
        case '3':
            // search for a contact
            dir.search_contact();
            break;
        case '4':
            // update a contact
            dir.update_contact();
            break;
        case '5':
            // print the directory
            dir.print_directory();
            break;
        
        case '6':
            // quit the program
            quit = quit_program(dir);
            break;
        default:
            cout << "Invalid input. Please try again." << endl;
            break;

    }
    } while (quit == true);
    return 0;
}
// prints the menu
void print_menu() {
    cout << "1. Add a contact" << endl;
    cout << "2. Remove a contact" << endl;
    cout << "3. Search for a contact" << endl;
    cout << "4. Update a contact" << endl;
    cout << "5. Print the directory" << endl;
    cout << "6. Quit the program" << endl;
}
// get the user input
char get_user_input() {
    char user_input;
    cout << "Please enter your choice: ";
    cin >> user_input;
    return user_input;
}

// read the file

//quit the program
bool quit_program(directory &dir) 
{
//Confirm quit
cout << "warning: you are about to quit the program. Are you sure you want to quit? (y/n)" << endl;
//get user input
char user_input;
//loop until user enters y or n
bool quit = false;
cin >> user_input;
if (user_input == 'y') {
    dir.write_to_file();
    cout << "Thank you for using the directory program. Goodbye!" << endl;
    quit = true;

} else if (user_input == 'n') {
    quit = false;
    return quit;
} else {
    cout << "Invalid input. Please try again." << endl;
    return quit;
}
    return 0;
}


