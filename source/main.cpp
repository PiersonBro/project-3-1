#include <string>
#include <stack>
#include <iostream>
#include <vector>
#include <fstream>
#include "Token.h"
using namespace std;

int main() {
    // we used cplusplus.com for more info on if/ofstreams and their members
    string filename;
    cout << "Name of file to be checked: ";
    cin >> filename;
    // open then read file
    ifstream FILE;
    FILE.open(filename);
    if (FILE.is_open() == false) {
        cout << "Error opening file." << endl;
        return -1;
    }
    string store;
    string other;
    while (FILE.eof() != true) {
        getline(FILE, store);
        other = other + "\n" + store;
    }
    cout << other << endl;
    bool parsed = bracket_parser(other);
    if (parsed == true) {
        cout << "Your file is a-ok!" << endl;
    }

    return 0;
}