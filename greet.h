#ifndef GREET_H
#define GREET_H

#include <iostream>
#include <fstream> // REQUIRED INCLUDE FOR FILE I/O
#include <cstdlib>
#include <string>

using namespace std;

// validate arguments
void valid_args(int);

// read x names from file into array of strings
string* read_names(fstream& file, const int x);

// sort names alphabetically using bubble-sort
void sort_names(string*& names, const int size);

// write out greeting messages in new file
void write_greeting(const string& filename, string* names, const int size);

#endif