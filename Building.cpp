/* Baris Aydinay - 2452977
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only
*/
#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;
#include "Building.h"

// Same methods as I used Agency.cpp (constructors,add,search,calculate,..)
	Building::Building() {  
		buildingId = 0;
		address = new char[100];
		strcpy(address, "Not provided");
		int i;
		for (i = 0; i < 50; i++)
		{
			this->apartments[i] = NULL;
		}
	}
	Building::Building(int buildingId, const char* address, Apartment& apartments) {
		int i = 0;
		this->buildingId = buildingId;
		this->address = new char[100];
		strcpy(this->address, address);
		while (this->apartments[i] != NULL) { i = i + 1; }
		this->apartments[i] = &apartments;
	}
	void Building::setBuildingId(int id) {
		buildingId = id;
	}
	
	void Building::setBuildingAddress(const char* adres) {
		address = new char[100];
		strcpy(address, adres);
	}

	int Building::getBuildingId() {
		return buildingId;
	}
	const char* Building::getBuildingAddress() {
		return address;
	}
	void Building::getApartments() {
		int i = 0;
		while (apartments[i] != NULL) {
			apartments[i]->printDetails();
			i++;
		}
	}
	void Building::addApartment(Apartment& apartment) { // Adds the apartment to the specified building
		int i;
		for (i = 0; i < 50; i++)
		{
			if (apartments[i] == NULL) {
				apartments[i] = &apartment;
				break;
			}
		}

	}
	void Building::printSpecifiedRoomsDaily(int rooms) {
		int i;
		
		for (i = 0; i < 50; i++) {
			if (apartments[i] == NULL) break;
			if (apartments[i]->getNumberOfRooms() == rooms && apartments[i]->monthlyOrdaily() == 1) {
				apartments[i]->printDetails();
			}
		}
	}
	void Building::printSpecifiedRoomsMonthly(int rooms) {
		int i;
		
		for (i = 0; i < 50; i++) {
			if (apartments[i] == NULL) break;
			if (apartments[i]->getNumberOfRooms() == rooms && apartments[i]->monthlyOrdaily() == 2) {
				apartments[i]->printDetails();
			}
		}

	}

	int Building::CountDailyandRooms(int room) { // All these Count functions are used to see if the apartment is daily or monthly
		int i;
		for (i = 0; i < 50; i++) {
			if (apartments[i] == NULL) { return 0; }
			if (apartments[i]->monthlyOrdaily() == 1 && apartments[i]->getNumberOfRooms() == room) return 1;
		}

	}
	int Building::CountMonthlyandRooms(int room) { // All these Count functions are used to see if the apartment is daily or monthly
		int i;
		for (i = 0; i < 50; i++) {
			if (apartments[i] == NULL) { return 0; }
			if (apartments[i]->monthlyOrdaily() == 2 && apartments[i]->getNumberOfRooms() == room) return 1;
		}

	}

	int Building::CountDailyandBigger(int newsize) { // All these Count functions are used to see if the apartment is daily or monthly
		int i;
		for (i = 0; i < 50; i++) {
			if (apartments[i] == NULL) { return 0; }
			if (apartments[i]->monthlyOrdaily() == 1 && apartments[i]->getSize() >= newsize) return 1;
		}

	}

	int Building::CountMonthlyandBigger(int newsize) { // All these Count functions are used to see if the apartment is daily or monthly
		int i;
		for (i = 0; i < 50; i++) {
			if (apartments[i] == NULL) { return 0; }
			if (apartments[i]->monthlyOrdaily() == 2 && apartments[i]->getSize() >= newsize) return 1;
		}

	}

	void Building::printSpecifiedSizeDaily(int newsize) {
		int i;
		int daily = 0; int monthly = 0;
		for (i = 0; i < 50; i++) {
			if (apartments[i] == NULL) break;
			if (apartments[i]->getSize() >= newsize && apartments[i]->monthlyOrdaily() == 1) {
				apartments[i]->printDetails();
			}
		}

	}

	void Building::printSpecifiedSizeMonthly(int newsize) {
		int i;
		int daily = 0; int monthly = 0;
		for (i = 0; i < 50; i++) {
			if (apartments[i] == NULL) break;
			if (apartments[i]->getSize() >= newsize && apartments[i]->monthlyOrdaily() == 2) {
				apartments[i]->printDetails();
			}
		}

	}

	int Building::CountMonthlyandCheaper(int newprice) { // All these Count functions are used to see if the apartment is daily or monthly
		int i;
		for (i = 0; i < 50; i++) {
			if (apartments[i] == NULL) { return 0; }
			if (apartments[i]->monthlyOrdaily() == 2 && (apartments[i]->getPrice() / 30) <= newprice) return 1;
		}

	}

	int Building::CountDailyandCheaper(int newprice) { // All these Count functions are used to see if the apartment is daily or monthly
		int i;
		for (i = 0; i < 50; i++) {
			if (apartments[i] == NULL) { return 0; }
			if (apartments[i]->monthlyOrdaily() == 1 && apartments[i]->getPrice() <= newprice) return 1;
		}

	}

	void Building::printCheapersMonthly(int newprice) {
		int i;
		for (i = 0; i < 50; i++) {
			if (apartments[i] == NULL) break;
			if ((apartments[i]->getPrice() / 30) <= newprice && apartments[i]->monthlyOrdaily() == 2) {
				apartments[i]->printDetails();
			}
		}

	}
	void Building::printCheapersDaily(int newprice) {
		int i;
		for (i = 0; i < 50; i++) {
			if (apartments[i] == NULL) break;
			if (apartments[i]->getPrice() <= newprice && apartments[i]->monthlyOrdaily() == 1) {
				apartments[i]->printDetails();
			}
		}

	}
	void Building::printCheapers(int result) {
		int i;
		for (i = 0; i < 50; i++) {
			if (apartments[i] == NULL) break;
			if (apartments[i]->calculateRentalorMonthlyPrice() < result) apartments[i]->printDetails();
		}
	}
	void Building::printMonthlyOrDaily(int x) {
		int i;
		for (i = 0; i < 50; i++) {
			if (apartments[i] == NULL) break;
			else if (x == 0 && apartments[i]->monthlyOrdaily() - 1 == x) apartments[i]->printDetails();
			else if (x == 1 && apartments[i]->monthlyOrdaily() - 1 == x) apartments[i]->printDetails();


		}
	}
	void Building::priceSpecificDays(int roomno, int nodays) {
		int i;
		int result;
		for (i = 0; i < 50; i++) {
			if (apartments[i] == NULL) break;
			else if (apartments[i]->getApartmentId() == roomno) {
				result = apartments[i]->calculateRentalorMonthlyPrice() * nodays;
				cout << "The rent for your stay is " << result << " GBP!" << endl;
			}
		}
	}
	void Building::printBuildingWithAddress() {
		cout << "ID: " << buildingId << ", Address: " << address << endl;
	}
	void Building::printBuildingWithApartments() {
		int i;
		int daily = 0;
		int monthly = 0;
		cout << "ID: " << buildingId << ", Address: " << address << endl;
		for (i = 0; i < 50; i++) {
			if (apartments[i] == NULL) break;
			else if (apartments[i]->monthlyOrdaily() == 1) daily++;
			else monthly++;
		}

		if (daily == 0) cout << "Daily Rental Apartments:" << endl << "Not any!" << endl;
		else {
			cout << "Daily Rental Apartments:" << endl;

			for (i = 0; i < 50; i++) {
				if (apartments[i] == NULL) break;
				if (apartments[i]->monthlyOrdaily() == 1)
					apartments[i]->printDetails();
			}

		}
		if (monthly == 0) cout << "Monthly Rental Apartments:" << endl << "Not any!" << endl;
		else {
			cout << "Monthly Rental Apartments:" << endl;

			for (i = 0; i < 50; i++) {
				if (apartments[i] == NULL) break;
				if (apartments[i]->monthlyOrdaily() == 2)
					apartments[i]->printDetails();
			}

		}
	}

	void Building::operator=(const Building& tmp) { // assign
		int i;
		delete[] address;
		this->address = new char[strlen(tmp.address) + 1];
		strcpy(this->address, tmp.address);
		this->buildingId = tmp.buildingId;
		for (i = 0; i < 50; i++) {
			this->apartments[i] = tmp.apartments[i];
		}

	}

	Building::Building(const Building& tmp) { // copy
		int i;
		this->address = new char[strlen(tmp.address) + 1];
		strcpy(this->address, tmp.address);
		this->buildingId = tmp.buildingId;
		for (i = 0; i < 50; i++) {
			this->apartments[i] = tmp.apartments[i];
		}
	}

	Building::~Building() { // destroy
		int i;
		delete[]address;
		
	}







