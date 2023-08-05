/* Baris Aydinay - 2452977
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only
*/
#ifndef Agency_h
#define Agency_h
#pragma warning(disable:4996)
using namespace std;
#include "Building.h"
#include "Apartment.h"


class Agency { // This file only includes prototypes of functions
private:
	char* name;
	Building* buildings[50];
public:
	Agency();
	Agency(const char*, Building&);
	const char* getAgencyName();
	void setAgencyName(const char* );
	void addBuilding(Building& );
	void printBuildingWithAddress();
	void printApartmentsinBuildingsSpecifiedRooms();
	void printApartmentsinBuildingsBigger();
	void printApartmentsinBuildingsCheaper();
	void printDailyorMonthly();
	void printRentalPriceSpesificApartment();
	void printBuildingsWithApartmentsInside();
	Agency(const Agency&); // copy
	void operator=(const Agency&); // assign
	~Agency(); // destroy
	
};



#endif