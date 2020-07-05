#include "stdafx.h"
#include "Tram.h"
#include <iostream>

using namespace std;

Tram::Tram()
{
	nameVehicle = "Tram";
	this->numWay = 0;
}

Tram::Tram(const string &name, const string &vin, const string &color, const string & type, int vEngine, int yearProd, int yearCommis, int numWay)
	: Vehicle(name, vin, color, type, vEngine, yearProd, yearCommis)
{
	this->numWay = numWay;
}

void Tram::printInfo()
{
	// first, display general basic information, then already specific to this class
	cout << baseInfo() << ", Number way: " << numWay << endl;
}

void Tram::writeToFile(ostream &os)
{
	// write parameters to the stream
	os << nameVehicle << " " << vin << " " << yearProduction <<
		" " << yearCommissioning << " " << color << " " << typeFuel << " " << vEngine << " " << numWay << endl;
}

void Tram::readFromFile(const string &str)
{
	istringstream iss(str); // string stream
	// read the components of the string in the appropriate parameters
	iss >> nameVehicle >> vin >> yearProduction >> yearCommissioning >> color >> typeFuel >> vEngine >> numWay;
}

Tram::~Tram()
{
}
