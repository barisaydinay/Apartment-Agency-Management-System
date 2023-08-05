/* Baris Aydinay - 2452977
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only
*/
#ifndef Building_h
#define Building_h
#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;

#include "Apartment.h"


class Building { // This file only includes prototypes of functions
private:
	int buildingId;
	char* address;
	Apartment* apartments[50];
public:
	Building();
	Building(int,const char*,Apartment&);
	void setBuildingId(int);
	void setBuildingAddress(const char*);
	int getBuildingId();
	const char* getBuildingAddress();
	void getApartments();
	void addApartment(Apartment&);
	void printSpecifiedRoomsDaily(int);
	void printSpecifiedRoomsMonthly(int);
	int CountDailyandRooms(int);
	int CountMonthlyandRooms(int);
	int CountDailyandBigger(int);
	int CountMonthlyandBigger(int);
	void printSpecifiedSizeDaily(int);
	void printSpecifiedSizeMonthly(int);
	int CountMonthlyandCheaper(int);
	int CountDailyandCheaper(int);
	void printCheapersMonthly(int);
	void printCheapersDaily(int);
	void printCheapers(int);
	void printMonthlyOrDaily(int);
	void priceSpecificDays(int,int);
	void printBuildingWithAddress();
	void printBuildingWithApartments();
	void operator=(const Building&); // assign
	Building(const Building&); // copy
	~Building(); // destroy


};

#endif
