#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <array>
#include <iomanip>
#include <iostream>
#include "funcFile.h"

using namespace std;

int main() {
	//Array that file contents goes into
	const int sizeOfArray = 150;
	int intArray[sizeOfArray] = { };
	//Function call
	readFileFunc(intArray, sizeOfArray);
	//Function call
	searchArray(intArray, sizeOfArray);

	//Function with try and catch implemented
	modifyInts(intArray, sizeOfArray);

	//Function with try and catch implemented
	addInts(intArray, sizeOfArray);

	//Function call
	removeOrZero(intArray, sizeOfArray);
}