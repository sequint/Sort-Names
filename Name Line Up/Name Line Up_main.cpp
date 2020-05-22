/****Name Line Up****/
// Program takes in a list of names and sorts them in alphabetical order.
#include <iostream>
#include <string>
#include <fstream>
#include "Name Line Up_prototypes.h"
using namespace std;

int main()
{

	// Define output and input files for the list of names.
	ofstream outputFile;
	ifstream inputFile;
	int numOfNames;

	// Get the number of names that a user wants to write to the file.
	numOfNames = getNumOfNames();

	// Get the names from the user and write them to the file.
	getNames(numOfNames, outputFile);

	// Sort the file of names into alphebetic order.
	sortNames(numOfNames, inputFile, outputFile);

	return 0;
	
}