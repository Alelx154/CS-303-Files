#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <array>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include "funcFile.h"

using namespace std;

void readFileFunc(int nameOfArray[], int arraySize) {
	ifstream fileName;
	fileName.open("numFile.txt");

	if (fileName.is_open()) {
		while (!fileName.eof()) {
			int i = 0;
			for (i = 0; i < arraySize; i++) {
				fileName >> nameOfArray[i];
			}
		}
	}
}


void searchArray(int nameOfArray[], int arraySize) {
	int i = 0;
	int numToSearch = 0;
	int foundNum = 0;
	
	cout << "Enter number to search --> ";
	cin >> numToSearch;
	cout << endl;

	for (i = 0; i < arraySize; i++) {
		if (nameOfArray[i] == numToSearch) {
			foundNum = nameOfArray[i];
			cout << "Number found! Index of number is " << i << endl;
		}
		
	}
	if (numToSearch != foundNum) {
		cout << "Sorry, number was not found" << endl;
	}
}

void modifyInts(int nameOfArray[], int arraySize) {
	bool random = true;
	int indexToModify = 0;
	int oldValue = 0;
	int newValue = 0;
	do {
		try {
			cout << "Enter the index of the number you'd like to replace --> ";
			cin >> indexToModify;

			if (cin.fail() || indexToModify > arraySize || indexToModify < 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw 20;
			}

			random = false;
			cout << "Enter the number you would like to replace the old one with --> ";
			cin >> newValue;

			oldValue = nameOfArray[indexToModify];

			nameOfArray[indexToModify] = newValue;
			cout << "The new value is " << nameOfArray[indexToModify] << ", the old value was " << oldValue << endl;
			break;
		}
		catch (int e) {
			cout << "Invalid user Input" << endl;
			continue;
		}
	} while (random = true);
}
//Figuring this out was a real pain in the butt. There are easier ways to do this that don't involve the use of try and catch
void addInts(int nameOfArray[], int arraySize) {
	int i = 0;
	int numToAdd = 0;
	bool random = true;
	do {
		try {
			for (i = 0; i < arraySize; i++) {
				if (nameOfArray[i] == 0) {
					cout << "Enter the number you would like to add --> ";
					cin >> numToAdd;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						throw 19;
					}
					else {
						random = false;
						nameOfArray[i] = numToAdd;
						cout << "Integer added!" << endl;
						break;
					}
				}
				break;
			}
			break;
		}

		catch (int e) {
			cout << "Invalid user input" << endl;
			continue;
		}

	} while (random = true);
}

void removeOrZero(int nameOfArray[], int arraySize) {
	int i = 0; 
	int numToReplace = 0;
	cout << "Enter the index you would like to replace --> " << endl;
	cin >> numToReplace;

	nameOfArray[numToReplace] = i;
}
