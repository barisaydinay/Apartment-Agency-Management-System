/* Baris Aydinay - 2452977
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only
*/
#ifndef Apartment_h
#define Apartment_h
#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;

#include "Building.h"



class Apartment { // This file only includes prototypes of functions
protected:
	int apartmentId;
	int numberOfRooms;
	int price;
	int size;
public:
	Apartment();
	Apartment(int,int,int,int);
	int getApartmentId();
	int getNumberOfRooms();
	int getPrice();
	int getSize();
	void setApartmentId(int);
	void setNumberOfRooms(int);
	void setPrice(int );
	void setSize(int);
	virtual void printDetails(); // I used virtual keyword because I have 2 type of apartments, and it must use the correct function from the baseclass
	virtual int calculateRentalorMonthlyPrice(); // I used virtual keyword because I have 2 type of apartments, and it must use the correct function from the baseclass
	virtual int monthlyOrdaily(); // I used virtual keyword because I have 2 type of apartments, and it must use the correct function from the baseclass
};


class DailyRentalApartment : public Apartment { // Used inheritance since Daily Rental Apartment is subclass of apartments
private:
	enum decorationStyle { Minimalist, Modern, Classic } apartType; // I have 3 apartTypes, and assignment wants us to create enum
public:
	DailyRentalApartment();
	DailyRentalApartment(int, int , int , int , int);
	void setType(int);
	int  calculateRentalorMonthlyPrice();
	void printDetails();
	int monthlyOrdaily();
};


class MonthlyRentalApartment : public Apartment { // Used inheritance since Monthly Rental Apartment is subclass of apartments
private:
	bool hasFurniture; // In here, I have True or False condition 
public:
	MonthlyRentalApartment();
	MonthlyRentalApartment(bool, int, int, int, int);
	void setFurniture(int);
	int calculateRentalorMonthlyPrice();
	void printDetails();
	int monthlyOrdaily();
	
};


#endif
