#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
public:
	Car(); 
	Car(const string &name, const string &vin, const string &color, const string & type, int vEngine, int yearProd, int yearCommis, bool hasBabySeat);
	~Car() override;
	void printInfo() override; 
	void writeToFile(ostream &os) override;
 	void readFromFile(const string &str) override;

private:
	bool hasBabySeat; // is there a child seat
};

