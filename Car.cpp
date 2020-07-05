#include "stdafx.h"
#include "Car.h"
#include <iostream>

using namespace std;

Car::Car() : Vehicle() // Base constructor
{
	nameVehicle = "Car";
	this->hasBabySeat = false;
}

Car::Car(const string &name, const string &vin, const string &color, const string & type, int vEngine, int yearProd, int yearCommis, bool hasBabySeat)
	: Vehicle(name, vin, color, type, vEngine, yearProd, yearCommis)
{
	this->hasBabySeat = hasBabySeat;
}


Car::~Car()
{
}

void Car::printInfo()
{
	string answer = (hasBabySeat) ? "true" : "no"; // if there is a child seat then true
	// first, display general basic information, then already specific to this class
	cout << baseInfo() << ", Has baby seat: " << answer << endl; 
}

void Car::writeToFile(ostream &os)
{
	int isSeat = (hasBabySeat) ? 1 : 0;  // if there is a child seat then 1 otherwise 0
	// write parameters to the stream
	os << nameVehicle << " " << vin << " " << yearProduction <<
		" " << yearCommissioning << " " << color << " " << typeFuel << " " << vEngine << " " << isSeat << endl;
}

void Car::readFromFile(const string &str)
{
	istringstream iss(str); // string stream
	int isSeat;
	// read the components of the string in the appropriate parameters
	iss >> nameVehicle >> vin >> yearProduction >> yearCommissioning >> color >> typeFuel >> vEngine >> isSeat;
	hasBabySeat = (isSeat == 1) ? true : false; // determine if there is a child seat
}