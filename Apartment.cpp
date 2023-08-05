/* Baris Aydinay - 2452977
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only
*/
#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;

#include "Building.h"
#include "Apartment.h"



// Same methods as I used Agency.cpp (constructors,setters,getters,add,search,calculate,..)
	Apartment::Apartment() {
		apartmentId = 0;
		numberOfRooms = 0;
		price = 0;
		size = 0;

	}
	Apartment::Apartment(int apartmentId, int numberOfRooms, int price, int size) {
		this->apartmentId = apartmentId;
		this->numberOfRooms = numberOfRooms;
		this->price = price;
		this->size = size;
	}
	int Apartment::getApartmentId() {
		return apartmentId;
	}
	int Apartment::getNumberOfRooms() {
		return numberOfRooms;
	}
	int Apartment::getPrice() {
		return price;
	}
	int Apartment::getSize() {
		return size;
	}
	void Apartment::setApartmentId(int apartmentId) {
		this->apartmentId = apartmentId;

	}
	void Apartment::setNumberOfRooms(int numberOfRooms) {
		this->numberOfRooms = numberOfRooms;

	}
	void Apartment::setPrice(int price) {
		this->price = price;

	}
	void Apartment::setSize(int size) {
		this->size = size;

	}
	void Apartment::printDetails() {
		cout << "Room no: " << apartmentId << " Number of rooms: " << numberOfRooms << " Rent: " << price << " Size: " << size << endl;

	}
	int Apartment::calculateRentalorMonthlyPrice() {
		return (price);
	}
	int Apartment::monthlyOrdaily() {
		return -1;
	}

	DailyRentalApartment::DailyRentalApartment() {  // I defined my default apartType as Classic
		apartType = Classic;
	}
	DailyRentalApartment::DailyRentalApartment(int number, int apartmentId, int numberOfRooms, int price, int size) : Apartment(apartmentId, numberOfRooms, price, size) {
		if (number == 1) {    // In here I am overwriting it, because I used inheritance
			apartType = Minimalist;
		}
		else if (number == 2) { // From the user input, apartType is created basically
			apartType = Modern;
		}
		else {
			apartType = Classic;

		}
	}

	void DailyRentalApartment::setType(int i) { // setting the apartType to the spesific apartment
		if (i == 1) {
			apartType = Minimalist;
		}
		else if (i == 2) {
			apartType = Modern;
		}
		else {
			apartType = Classic;

		}

	}

	int  DailyRentalApartment::calculateRentalorMonthlyPrice() { // In here I actually do not take parameters to the function, but I calculated the price out of the function
		return (price); // It just returns the price of Daily Rental apartments price and I do my calculations outside
	}
	void DailyRentalApartment::printDetails() { // just printing the details
		
		cout << "Room no: " << apartmentId << " Number of rooms: " << numberOfRooms << " Rent: " << price << " Size: " << size << " Apart Type: ";

		switch (apartType)
		{
		case 0: cout << "Minimalist" << endl; break;
		case 1: cout << "Modern" << endl; break;
		case 2: cout << "Classic" << endl; break;
		}

	}
	int DailyRentalApartment::monthlyOrdaily() { // It returns 1, if it is daily
		return 1;
	}


	MonthlyRentalApartment::MonthlyRentalApartment() { // boolean conditions for furniture 
		hasFurniture = false;
	}
	MonthlyRentalApartment::MonthlyRentalApartment(bool select, int apartmentId, int numberOfRooms, int price, int size) : Apartment(apartmentId, numberOfRooms, price, size) {

		hasFurniture = select; // overwriting again for constructor

	}

	void MonthlyRentalApartment::setFurniture(int i) {
		if (i == 1) hasFurniture = true;
		else hasFurniture = false;
	}


	int MonthlyRentalApartment::calculateRentalorMonthlyPrice() { // ccalculations for price, if it is monthly
		int x = price / 30; // I'm dividing it 30 (assumed 1 month is 30 days), to calculate the daily price, and doing my operations based on daily price
		return (x);
	}
	void MonthlyRentalApartment::printDetails() { // printing details regarding to Has Furniture or Has not Furniture
		if (hasFurniture == true)
			cout << "Room no: " << apartmentId << " Number of rooms: "
			<< numberOfRooms << " Rent: " << price << " Size: " << size << " Furnished: Yes" << endl;
		else cout << "Room no: " << apartmentId << " Number of rooms: "
			<< numberOfRooms << " Rent: " << price << " Size: " << size << " Furnished: No" << endl;

	}
	int MonthlyRentalApartment::monthlyOrdaily() { // returning 2, if apartment is daily
		return 2;
	}


