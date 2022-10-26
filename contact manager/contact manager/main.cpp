#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <chrono>
#include <thread>
#include "contact_properties.h"
#include "directory.h"


using namespace std;

// function prototypes
bool read_file(directory &dir);
void print_menu();
char get_user_input();
bool quit_program();

int main() {
    // create a directory object
    directory dir;
    // INITIALIZE THE DIRECTO
    // read the file
    read_file(dir);
    // print the menu
    print_menu();
    // get the user input
    char user_input = get_user_input();

    switch (user_input) {
        case '1':
            // add a contact
            break;
        case '2':
            // remove a contact
            break;
        case '3':
            // search for a contact
            break;
        case '4':
            // update a contact
            break;
        case '5':
            // print the directory
            break;
        case '6':
            // write to file
            break;
        case '7':
            // read from file
            break;
        case '8':
            // quit the program
            quit_program();
            break;
        default:
            cout << "Invalid input. Please try again." << endl;
            break;

    }
}

