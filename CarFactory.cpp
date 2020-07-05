#include "stdafx.h"
#include "CarFactory.h"
#include <string>
#include <iostream>
#include "Car.h"

using namespace std;

Vehicle * CarFactory::create()
{
	int vEngine;
	int yearProduction;
	int yearCommissioning;
	string nameVehicle;
	string vin;
	string color;
	string typeFuel;
	bool babySeat;
	string answer;

	// enter the values ​​of the car parameters
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
	cout << "Is have babyseat (y/n): ";
	getline(cin, answer);
	babySeat = (answer == "y") ? true : false;

	// return the newly created object Car
	return new Car(nameVehicle, vin, color, typeFuel, vEngine, yearProduction, yearCommissioning, babySeat);
}
