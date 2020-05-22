// Functions prototypes for Name Line Up.
#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int getNumOfNames();
void getNames(int, ofstream &);
void sortNames(int, ifstream &, ofstream &);
void swap(string &, string &);