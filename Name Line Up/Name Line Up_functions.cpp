// Functions for Name Line Up.
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Name Line Up_prototypes.h"
using namespace std;


//************************************
//****Get Number of Names Function****
//************************************

int getNumOfNames()
{
	
	int tempNum;

	// Get the number of names that a user wants to write to the file.
	cout << "Enter the number of names to write to the file (1-25): ";
	cin >> tempNum;

	// Check that the number is between 1 and 25.
	while (tempNum < 1 || tempNum > 25)
	{
		cout << "Number must be between 1 and 25. Please re-enter: ";
		cin >> tempNum;
	}

	return tempNum;
}

//**************************
//****Get Names Function****
//**************************

void getNames(int numOfNames, ofstream &outFile)
{
	string name;

	// Open a file for names.
	outFile.open("unordered_names.txt");

	// Loop through the number of names and ask user for a new name at each iteration.
	for (int count = 1; count <= numOfNames; count++)
	{
		cout << "Enter Name #" << count << ": ";
		cin >> name;

		// Write the name to file names file.
		outFile << name << endl;
	}

	// Close the names file.
	outFile.close();

	// Confirmation message of data written to the file.
	cout << "'unordered_names.txt' has been updated with the entered names.\n\n";
}

//***************************
//****Sort Names Function****
//***************************

void sortNames(int numOfNames, ifstream &inFile, ofstream &outFile)
{
	// Create a vector to store the name data from the file captured earlier.
	vector<string> names;
	string tempName;

	inFile.open("unordered_names.txt");

	if (inFile)
	{
		while (inFile >> tempName)
		{
			names.push_back(tempName);
		}
	}

	inFile.close();
	
	// Sort the vector of names.
	int minIndex;
	string minValue;

	for (int start = 0; start < names.size() - 1; start++)
	{
		minIndex = start;
		minValue = names[start];
		for (int index = start + 1; index < names.size(); index++)
		{
			if (names[index] < minValue)
			{
				minValue = names[index];
				minIndex = index;
			}
		}
		swap(names[minIndex], names[start]);
	}

	// Write the ordered vector to a new ordered file.
	outFile.open("ordered_names.txt");

	for (int count = 0; count < names.size(); count++)
	{
		outFile << names[count] << endl;
	}

	outFile.close();

	cout << "'ordered_names.txt' has been updated with the entered names in order.\n\n";
}

//*********************
//****Swap Function****
//*********************

void swap(string &a, string &b)
{
	string temp = a;
	a = b;
	b = temp;
}