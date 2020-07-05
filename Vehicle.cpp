#include "stdafx.h"
#include "Vehicle.h"

Vehicle::Vehicle()
{

}

Vehicle::Vehicle(const string & name, const string & vin, const string & color, const string & type, int vEngine, int yearProd, int yearCommis)
{
	// save the parameters passed to the constructor
	this->vin = vin;
	this->color = color;
	typeFuel = type;
	this->vEngine = vEngine;
	yearProduction = yearProd;
	yearCommissioning = yearCommis;
	nameVehicle = name;

}

string Vehicle::baseInfo()
{
	ostringstream oss;
	// write a string to a string stream object
	oss << "Type vehicle: " << nameVehicle << ", VIN: " << vin << ", Year prod: " << yearProduction <<
		", Year commissioning: " << yearCommissioning << ", Color: " << color << ", Fuel: " << typeFuel <<
		", Volume engine: " << vEngine;

	return oss.str(); // return the generated string information
}