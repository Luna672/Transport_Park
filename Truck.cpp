#include "stdafx.h"
#include "Truck.h"
#include <iostream>

using namespace std;

Truck::Truck()
{
	nameVehicle = "Truck";
	cargoVolume = 0;
}

Truck::Truck(const string &name, const string &vin, const string &color, const string & type, int vEngine, int yearProd, int yearCommis, int cargoVolume)
	: Vehicle(name, vin, color, type, vEngine, yearProd, yearCommis)
{
	this->cargoVolume = cargoVolume;
}

Truck::~Truck()
{
}

void Truck::printInfo()
{
	// first, display general basic information, then already specific to this class
	cout << baseInfo() << ", Cargo Volume: " << cargoVolume << endl;
}

void Truck::writeToFile(ostream &os)
{
	// write parameters to the stream
	os << nameVehicle << " " << vin << " " << yearProduction <<
		" " << yearCommissioning << " " << color << " " << typeFuel << " " << vEngine << " " << cargoVolume << endl;
}

void Truck::readFromFile(const string &str)
{
	istringstream iss(str);// string stream
	// read the components of the string in the appropriate parameters
	iss >> nameVehicle >> vin >> yearProduction >> yearCommissioning >> color >> typeFuel >> vEngine >> cargoVolume;
}