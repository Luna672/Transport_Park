#pragma once
#include "Vehicle.h"

class Tram : public Vehicle
{
public:
	Tram();
	Tram(const string &name, const string &vin, const string &color, const string & type, int vEngine, int yearProd, int yearCommis, int numWay);
	~Tram();
	void printInfo() override;
	void writeToFile(ostream &os) override;
	void readFromFile(const string &str) override;

private:
	int numWay; // route number
};
