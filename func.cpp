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
	//Filestream is created
	fileName.open("numFile.txt");
	//Opens the file
	if (fileName.is_open()) {
		while (!fileName.eof()) {
			//Reads the file all the way to the end
			int i = 0;
			for (i = 0; i < arraySize; i++) {
				//Wrties all contents of file into the array
				fileName >> nameOfArray[i];
			}
		}
	}
}

//Function searches array for the specified number
void searchArray(int nameOfArray[], int arraySize) {
	int i = 0;
	int numToSearch = 0;
	int foundNum = 0;
	
	cout << "Enter number to search --> ";
	cin >> numToSearch;
	cout << endl;
	//Looks for number
	for (i = 0; i < arraySize; i++) {
		if (nameOfArray[i] == numToSearch) {
			//Once found, number is assigned to variable and index is given
			foundNum = nameOfArray[i];
			cout << "Number found! Index of number is " << i << endl;
			cout << endl;
		}
		
	}
	//If not found, this prints
	if (numToSearch != foundNum) {
		cout << "Sorry, number was not found" << endl;
		cout << endl;
	}
}

void modifyInts(int nameOfArray[], int arraySize) {
	bool randomBool = true;
	int indexToModify = 0;
	int oldValue = 0;
	int newValue = 0;
	//Do while is here so the function keeps running even if user enters something wrong
	do {
		try {
			//try and catch is for error catching
			cout << "Enter the index of the number you'd like to replace --> ";
			cin >> indexToModify;
			cout << endl;
			//if user enters a non number or an index that doesnt exist, the if loop activates and throws error to catch
			if (cin.fail() || indexToModify > arraySize || indexToModify < 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw 20;
			}

			cout << "Enter the number you would like to replace the old one with --> ";
			cin >> newValue;
			cout << endl;
			//if user enters a non number or an index that doesnt exist, the if loop activates and throws error to catch
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw 20;
			}
			//Bool is set to false to break the do while
			randomBool = false;
			//Old value is saved to show user later
			oldValue = nameOfArray[indexToModify];

			nameOfArray[indexToModify] = newValue;
			//New and old value is shown to user
			cout << "The new value is " << nameOfArray[indexToModify] << ", the old value was " << oldValue << endl;
			cout << endl;
			break;
		}
		//Catch is for catching user input errors and continuing the function
		catch (int e) {
			cout << "Invalid user Input" << endl;
			cout << endl;
			continue;
		}
		break;
	} while (randomBool != false);
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
					cout << "Enter a number you would like to add to the array --> ";
					cin >> numToAdd;
					cout << endl;
					//if user enters a non number or an index that doesnt exist, the if loop activates and throws error to catch
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						throw 18;
					}
					//If user doesn't enter anything stupid, loop is killed and number is added
					else {
						random = false;
						nameOfArray[i] = numToAdd;
						cout << "Integer added!" << endl;
						cout << endl;
						break;
					}
				}
			}
			break;
		}
		//Catch is for catching user input errors and continuing the function
		catch (int f) {
			cout << "Invalid user input" << endl;
			cout << endl;
			continue;
		}

	} while (random = true);
}

void removeOrZero(int nameOfArray[], int arraySize) {
	//Pretty simple, asks user for an index, and removes the number at that index
	int i = 0; 
	int numToReplace = 0;
	cout << "Enter the index of the number you would like to remove --> ";
	cin >> numToReplace;
	cout << endl;

	cout << "Number has been removed!" << endl;

	nameOfArray[numToReplace] = i;
}
