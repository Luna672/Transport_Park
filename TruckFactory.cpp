#include "stdafx.h"
#include "TruckFactory.h"
#include <string>
#include <iostream>
#include "Truck.h"

Vehicle * TruckFactory::create()
{
	int vEngine;
	int yearProduction;
	int yearCommissioning;
	string nameVehicle;
	string vin;
	string color;
	string typeFuel;
	int cargoVol;

	// parameters input
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
	cout << "Input cargo volume: ";
	cin >> cargoVol;
	cin.get();

	// return the newly created object Truck
	return new Truck(nameVehicle, vin, color, typeFuel, vEngine, yearProduction, yearCommissioning, cargoVol);
}