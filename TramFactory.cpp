#include "stdafx.h"
#include "TramFactory.h"
#include <string>
#include <iostream>
#include "Tram.h"


Vehicle * TramFactory::create()
{
	int vEngine;
	int yearProduction;
	int yearCommissioning;
	string nameVehicle;
	string vin;
	string color;
	string typeFuel;
	int numWay;

	// parameter input
	cout << "Input name: ";
	getline(cin, nameVehicle);
	cout << "Input vin: ";
	getline(cin, vin);
	cout << "Input color: ";
	getline(cin, color);
	cout << "Input vEngine: ";
	cin >> vEngine;
	cout << "Input yearProd: ";
	cin >> yearProduction;
	cout << "Input Commissioning: ";
	cin >> yearCommissioning; cin.get();
	cout << "Input FuelType: ";
	getline(cin, typeFuel);
	cout << "Input number way: ";
	cin >> numWay;
	cin.get();

	// return the newly created Tram object
	return new Tram(nameVehicle, vin, color, typeFuel, vEngine, yearProduction, yearCommissioning, numWay);
}