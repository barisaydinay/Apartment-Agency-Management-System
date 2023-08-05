/* Baris Aydinay - 2452977
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only
*/
#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;
#include "Agency.h"


	Agency::Agency() { // default constructor
		int i;
		name = new char[100];
		strcpy(name, "No-argument!");
		for (i = 0; i < 50; i++) {
			this->buildings[i] = NULL;
		}
	}
	Agency::Agency(const char* newName, Building& buildings) { // constructor with paramters
		int i = 0;
		this->name = new char[100];
		strcpy(this->name, newName);
		while (this->buildings[i] != NULL) { i = i + 1; }
		this->buildings[i] = &buildings;
	}
	const char* Agency::getAgencyName() { // fetchs the name of the agency
		return name;
	}
	void Agency::setAgencyName(const char* newName) { // sets the name of the agency
		this->name = new char[100];
		strcpy(this->name, newName);
	}
	void Agency::addBuilding(Building& newbuilding) { // adds building to the agency
		int i;
		for (i = 0; i < 50; i++)
		{
			if (buildings[i] == NULL) {
				buildings[i] = &newbuilding;
				break;

			}
		}
	}
	void Agency::printBuildingWithAddress() { // prints all building with agency
		int i = 0;
		while (buildings[i] != NULL) {
			buildings[i]->printBuildingWithAddress(); // calls another function which is defined in buildings
			i++;

		}

	}
	void Agency::printApartmentsinBuildingsSpecifiedRooms() { // prints the specified buildings with apartments inside, but also I used helper functions the count the apartments to see if there is any apartment or not
		int roomNumber, i;
		cout << "Enter the specified room number: ";
		cin >> roomNumber;
		int monthly = 0, daily = 0;

		for (i = 0; i < 50; i++) { // I used these for loops to count and print the correct message for the user
			if (buildings[i] == NULL) break;
			if (buildings[i]->CountDailyandRooms(roomNumber) == 1) { daily = 1; break; }
		}
		cout << "Daily Rental Apartments:" << endl;
		if (daily == 0) { cout << "Not any!" << endl; }
		else {
			for (i = 0; i < 50; i++) {
				if (buildings[i] == NULL) break;
				else buildings[i]->printSpecifiedRoomsDaily(roomNumber);
			}
		}

		for (i = 0; i < 50; i++) {
			if (buildings[i] == NULL) break;
			if (buildings[i]->CountMonthlyandRooms(roomNumber) == 1) { monthly = 1; break; }
		}
		cout << "Monthly Rental Apartments:" << endl;
		if (monthly == 0) { cout << "Not any!" << endl; }
		else {
			for (i = 0; i < 50; i++) {
				if (buildings[i] == NULL) break;
				else buildings[i]->printSpecifiedRoomsMonthly(roomNumber);
			}
		}

	}


	void Agency::printApartmentsinBuildingsBigger() { // Same methods from the previous
		int i, minsize;
		cout << "Enter minimum size: ";
		cin >> minsize;
		
		int daily = 0, monthly = 0;
		for (i = 0; i < 50; i++) {
			if (buildings[i] == NULL) break;
			else if (buildings[i]->CountDailyandBigger(minsize) == 1) { daily = 1; break; }
		}
		cout << "Daily Rental Apartments:" << endl;
		if (daily == 0) { cout << "Not any!" << endl; }
		else {
			for (i = 0; i < 50; i++) {
				if (buildings[i] == NULL) break;
				else buildings[i]->printSpecifiedSizeDaily(minsize);
			}
		}

		for (i = 0; i < 50; i++) {
			if (buildings[i] == NULL) break;
			else if (buildings[i]->CountMonthlyandBigger(minsize) == 1) { monthly = 1; break; }
		}
		cout << "Monthly Rental Apartments:" << endl;
		if (monthly == 0) { cout << "Not any!" << endl; }
		else {
			for (i = 0; i < 50; i++) {
				if (buildings[i] == NULL) break;
				else buildings[i]->printSpecifiedSizeMonthly(minsize);
			}
		}
	}

	void Agency::printApartmentsinBuildingsCheaper() { // Same method from the previous
		int i, price, days;
		int daily = 0, monthly = 0;
		cout << "Enter the price (GBP): ";
		cin >> price;
		cout << "Enter the days: ";
		cin >> days;
		int result = price / days;

		

		for (i = 0; i < 50; i++) {
			if (buildings[i] == NULL) break;
			else if (buildings[i]->CountDailyandCheaper(result) == 1) { daily = 1; break; }
		}
		cout << "Daily Rental Apartments:" << endl;
		if (daily == 0) { cout << "Not any!" << endl; }
		else {
			for (i = 0; i < 50; i++) {
				if (buildings[i] == NULL) break;
				else buildings[i]->printCheapersDaily(result);
			}
		}

		for (i = 0; i < 50; i++) {
			if (buildings[i] == NULL) break;
			else if (buildings[i]->CountMonthlyandCheaper(result) == 1) { monthly = 1; break; }
		}
		cout << "Monthly Rental Apartments:" << endl;
		if (monthly == 0) { cout << "Not any!" << endl; }
		else {
			for (i = 0; i < 50; i++) {
				if (buildings[i] == NULL) break;
				else buildings[i]->printCheapersMonthly(result);
			}
		}
	}

	void Agency::printDailyorMonthly() { // Looks all buildings and see if it is daily or monthly
		int i, x;
		cout << "Enter Daily/Monthly Rental (0/1): ";
		cin >> x;
		for (i = 0; i < 50; i++) {
			if (buildings[i] == NULL) break;
			else buildings[i]->printMonthlyOrDaily(x);
		}
	}
	void Agency::printRentalPriceSpesificApartment() { // Search all buildings and calculate the rental price
		int i, roomno, days;

		cout << endl << "Enter Room No: ";
		cin >> roomno;
		cout << "Enter Number of Days : ";
		cin >> days;
		for (i = 0; i < 50; i++) {
			if (buildings[i] == NULL) break;
			else buildings[i]->priceSpecificDays(roomno, days);
		}
	}

	void Agency::printBuildingsWithApartmentsInside() { // I used this function for menu selection 9, to print the available buildings and it's apartments inside
		int i;
		for (i = 0; i < 50; i++) {
			if (buildings[i] == NULL) break;
			else {
				cout << "In building: ";
				buildings[i]->printBuildingWithApartments();
			}


		}
	}

	Agency::Agency(const Agency& tmp) { // copy
		int i;
		this->name = new char[strlen(tmp.name) + 1];
		strcpy(this->name, tmp.name);
		for (i = 0; i < 50; i++) {
			this->buildings[i] = tmp.buildings[i];
		}
	}

	void Agency::operator=(const Agency& tmp) { // assign 
		int i;
		delete[] name;
		this->name = new char[strlen(tmp.name) + 1];
		strcpy(this->name, tmp.name);
		for (i = 0; i < 50; i++) {
			this->buildings[i] = tmp.buildings[i];
		}

	}

	Agency::~Agency() { // destroy
		
		delete[] name;
		
	}

