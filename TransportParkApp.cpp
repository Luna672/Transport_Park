// TransportParkApp.cpp: Defines an entry point for a console application

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Car.h"
#include "Tram.h"
#include "Truck.h"
#include "TramFactory.h"
#include "TruckFactory.h"
#include "CarFactory.h"

using namespace std;

void createCar(vector<Vehicle*> &vec)
{
	int countItem; // number of cars to create
	cout << "Input count car: ";
	cin >> countItem; // entering the number of cars
	cin.get(); 
	
	Factory *factory = new CarFactory; // create a car factory
	for (int i = 0; i < countItem; ++i) { 
		// the factory creates a car, returns a pointer to it, and places the pointer in the Transport vector
		vec.push_back(factory->create()); 
	}

	delete factory; // free memory
}

void createTruck(vector<Vehicle*> &vec)
{
	int countItem; // number of trucks to create
	cout << "Input count truck: ";
	cin >> countItem;  // entering the number of trucks
	cin.get();

	Factory *factory = new TruckFactory; // create truck factory
	for (int i = 0; i < countItem; ++i) {
		// the factory creates a truck, returns a pointer to it, and places the pointer in the Transport vector
		vec.push_back(factory->create()); 
	}

	delete factory; // free memory
}

void createTram(vector<Vehicle*> &vec)
{
	int countItem;
	cout << "Input count tram: ";
	cin >> countItem;
	cin.get();

	Factory *factory = new TramFactory; // create a tram factory
	for (int i = 0; i < countItem; ++i) {
		// the factory creates a tram, returns a pointer to it and places the pointer in the Transport vector
		vec.push_back(factory->create());
	}

	delete factory; // free memory
}

// save transport to file
void save(vector<Vehicle*> &vec)
{
	// open the file for reading
	ofstream out("storage.txt", ofstream::out);

	vector<Vehicle*> cars; // vector stores cars
	vector<Vehicle*> trucks;// vector stores trucks
	vector<Vehicle*> trams; // vector stores trams 

	// if the file opened
	if (out.is_open()) {
		for (int i = 0; i < vec.size(); ++i) { // pass through all transport in vector
			if (dynamic_cast<Car*>(vec[i])) { // if you can bring the pointer to the transport to the pointer to the car
				cars.push_back(vec[i]); // save in car vector
			} else if (dynamic_cast<Truck*>(vec[i])) {  // otherwise, if you can bring the pointer to the transport to the pointer to the Truck
				trucks.push_back(vec[i]);// save in truck vector
			} else if (dynamic_cast<Tram*>(vec[i])) {  // otherwise, if you can bring the pointer to transport to the pointer to the Tram
				trams.push_back(vec[i]);// save in the tram vector
			}
		}

		// if there are cars
		if (!cars.empty()) {
			out << "Car" << endl; // write the header to the file
			for (int i = 0; i < cars.size(); ++i)
				cars[i]->writeToFile(out); // write information on each car to a file
		}

		// if there are trucks
		if (!trucks.empty()) {
			out << "Truck" << endl; // write the header to the file
			for (int i = 0; i < trucks.size(); ++i)
				trucks[i]->writeToFile(out);// write information on each truck to a file
		}
		
		// if there are trams
		if (!trams.empty()) {
			out << "Tram" << endl; // write the header to the file
			for (int i = 0; i < trams.size(); ++i)
				trams[i]->writeToFile(out); // write information on each tram to a file
		}
	}
}

// Load transport from file
void load(vector<Vehicle*> &vec)
{
	ifstream in("storage.txt"); // open the file for reading

	if (in.is_open()) { // if opened
		string line;
		while (getline(in, line)) { // read the lines
			if (line == "Car") { // if the header is Car
				getline(in, line); // read the line
				do {
					Car *car = new Car(); // create object Machine
					car->readFromFile(line); // read its parameters from the file
					vec.push_back(car); // put the car in the vector Transport
					getline(in, line); // read the next line
				} while (line != "Truck" && line != "Tram" && line.length() != 0); // until a new header or end of file
			} 
			
			if (line == "Truck") {  // if the header is Truck
				getline(in, line); // read the line
				do {
					Truck *truck = new Truck();// create object Truck
					truck->readFromFile(line);// read its parameters from the file
					vec.push_back(truck);// put the car in the vector Transport
					getline(in, line);// read the next line
				} while (line != "Car" && line != "Tram" && line.length() != 0); // until a new header or end of file
			}

			if (line == "Tram") {
				getline(in, line); // read the line
				do {
					Tram *tram = new Tram(); // create object Tram
					tram->readFromFile(line);// read its parameters from the file
					vec.push_back(tram);// put the car in the vector Transport
					getline(in, line);// read the next line
				} while (line != "Car" && line != "Truck" && line.length() != 0); // until a new header or end of file
			}

			if (line.length() == 0) // if there is nothing more to read, exit the loop of reading lines from a file
				break;
		}
	}
}

// Display menu
void printMenu()
{
	system("cls"); // screen cleaning

	// display menu items
	cout << "1. Create Car" << endl; 
	cout << "2. Create Truck" << endl;
	cout << "3. Create Tram" << endl;
	cout << "4. Save" << endl;
	cout << "5. Load" << endl;
	cout << "6. Print info all vehicles" << endl;
	cout << "0. Exit" << endl;

	// waiting for the input of the command
	cout << "\nInput command: ";
}

int main()
{
	int command = -1; // command
 	int countItem = 0; // transport counter
	vector<Vehicle*> vec; // transport vector

	while (command != 0) { // until the exit from the program
		printMenu(); // display menu
		cin >> command; // command input
		cin.get(); 
		system("cls"); // screen cleaning
		
		switch (command) { // depending on the command, perform an action
		case 1:
			createCar(vec); // create car
			break;
		case 2:
			createTruck(vec);// create truck
			break;
		case 3:
			createTram(vec);// create tram
			break;
		case 4:
			save(vec); // save to file
			break;
		case 5:
			load(vec); // load from file
			break;
		case 6: // display information about transport
			for (int i = 0; i < vec.size(); ++i) {
				vec[i]->printInfo();
				cout << "\n";
			}
			cin.get();
			break;
		default:
			break;
		}
	}
	
	// free the memory allocated for each transport
	for (int i = 0; i < vec.size(); ++i) {
		delete vec[i];
	}

    return 0;
}