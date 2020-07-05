#pragma once
#include <string>
#include <sstream>

using namespace std;

class Vehicle
{
public:
	Vehicle(); // default constructor
	Vehicle(const string &name, const string &vin, const string &color, const string & type, int vEngine, int yearProd, int yearCommis);
	virtual ~Vehicle() {}  // destructor
	virtual void printInfo() = 0; // information output
	virtual void writeToFile(ostream &os) = 0; // write to file
	virtual void readFromFile(const string &str) = 0; // read from file

protected:
	string baseInfo(); // general information output for any type of transport
	
protected:
	int vEngine; // engine volume
	int yearProduction; // production year
	int yearCommissioning; // commissioning year
	string nameVehicle; // vehicle name
	string vin; // VIN number
	string color; // color
	string typeFuel; // fuel type
};