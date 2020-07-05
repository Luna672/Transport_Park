#pragma once
#include "Vehicle.h"

class Truck : public Vehicle
{
public:
	Truck();
	Truck(const string &name, const string &vin, const string &color, const string & type, int vEngine, int yearProd, int yearCommis, int cargoVolume);
	~Truck();
	void printInfo() override;
	void writeToFile(ostream &os) override;
	void readFromFile(const string &str) override;

private:
	int cargoVolume; // cargo volume
};