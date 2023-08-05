/* Baris Aydinay - 2452977
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only
*/
#include <iostream>
#include <string.h>
#pragma warning(disable:4996) // In order to avoid string warnings
//#include "Building.h"  Actually I do not need to include Building and Apartment headers, it also works with only Agency.h
//#include "Apartment.h"
#include "Agency.h"




using namespace std;

int main() // This is my main .cpp, it basically includes my menu functions to call class operations
{
    Agency myAgency;
    myAgency.setAgencyName("Manchester Comfort Apartments");
    Building myBuildings[50]; // I am initializing my Buildings and apartments with arrays, since it satisfys Aggregation method
    DailyRentalApartment myDailyApartments[50];
    MonthlyRentalApartment myMonthlyApartments[50];
    char* adres;
    adres = new char[100];

    int i,k,j,choice;
    int flag=0;
    i = 0; //for buildings
    k = 0; //for daily apartments
    j = 0; //for monthly apartments
    cout << "!!!Welcome to Agency Management System!!!" << endl;
    cout << "--------------------------------------------- " << endl;
    cout << "Please select an operation" << endl;
    cout << "1. Add a new building to the agency" << endl << "2. Add a new apartment (monthly or daily rental) to a building" << endl;
    cout << "3. List all buildings" << endl << "4. List all apartments available for the agency" << endl;
    cout << "5. List all apartments that have the specified number of rooms" << endl;
    cout << "6. List all apartments which are bigger than the specified apartment size" << endl;
    cout << "7. List all apartments which are cheaper than the specified price in a specified number of days" << endl;
    cout << "8. List all apartments that are either daily or monthly rental" << endl;
    cout << "9. Calculate the price of a specific apartment in a specified number of days" << endl << "0.Exit" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Your selection: ";
    cin >> choice;
    if (choice == 0) {
        cout << "Thanks for choosing Agency Management System!" << endl;
        flag = 1;
        cout << "---------------------------------------------" << endl;
    }
    else {
        do {
            if (choice == 1) {
                cout << "What is the address of your building : " << endl;
                getchar(); // Asked our instructor and, allowed us to use getchar() in order to take char* with spaces.
                cin.getline(adres, 100);
                myBuildings[i].setBuildingAddress(adres);
                myBuildings[i].setBuildingId(i);
                myAgency.addBuilding(myBuildings[i]);
                cout << "The building is created with the id number " << myBuildings[i].getBuildingId() << "." << endl;
                i++;
                cout << "---------------------------------------------" << endl;
                cout << "Your selection: ";
                cin >> choice;
            }
            else if (choice == 2) {
                int id,type,roomno,numberOfrooms,rent,size;
                cout << "Which building you want to add apartment into ? " << endl;
                cout << "Available Buildings: " << endl;
                myAgency.printBuildingWithAddress();
                cout << "Building id: ";
                cin >> id;
                cout << "What is the type of the apartment?" << endl;
                cout << "1. Daily Rental Apartment" << endl;
                cout << "2. Monthly Rental Apartment" << endl;
                cout << "Type: ";
                cin >> type;
                cout << "Enter room number: ";
                cin >> roomno;
                cout << "Enter number of rooms: ";
                cin >> numberOfrooms;
                cout << "Enter rent (GBP): ";
                cin >> rent;
                cout << "Enter size (m2): ";
                cin >> size;
                if (type == 1) {
                    int selection;
                    cout << "Decoration Style: " << endl;
                    cout << "1. Minimalist" << endl;
                    cout << "2. Modern" << endl;
                    cout << "3. Classic" << endl << "Your selection: " << endl;
                    cin >> selection;
                    myDailyApartments[k].setApartmentId(roomno);
                    myDailyApartments[k].setNumberOfRooms(numberOfrooms);
                    myDailyApartments[k].setPrice(rent);
                    myDailyApartments[k].setSize(size);
                    myDailyApartments[k].setType(selection);
                    myBuildings[id].addApartment(myDailyApartments[k]);
                    k++;
                    cout << "Apartment successfully added!" << endl;
                }
                else {
                    int selection2;
                    cout << "Furnished (Yes(1) / No (0)):";
                    cin >> selection2;
                    myMonthlyApartments[j].setApartmentId(roomno);
                    myMonthlyApartments[j].setNumberOfRooms(numberOfrooms);
                    myMonthlyApartments[j].setPrice(rent);
                    myMonthlyApartments[j].setSize(size);
                    myMonthlyApartments[j].setFurniture(selection2);
                    myBuildings[id].addApartment(myMonthlyApartments[j]);
                    j++;
                    cout << "Apartment successfully added!" << endl;
                }
                cout << "---------------------------------------------" << endl;
                cout << "Your selection: ";
                cin >> choice;
            }
            else if (choice == 3) {
                cout << "Buildings: " << endl;
                myAgency.printBuildingWithAddress();
                cout << "---------------------------------------------" << endl;
                cout << "Your selection: ";
                cin >> choice;
            }
            else if (choice == 4) {
                myAgency.printBuildingsWithApartmentsInside();
                cout << "---------------------------------------------" << endl;
                cout << "Your selection: ";
                cin >> choice;
            }
            else if (choice == 5) {
                myAgency.printApartmentsinBuildingsSpecifiedRooms();
                cout << "---------------------------------------------" << endl;
                cout << "Your selection: ";
                cin >> choice;
                                    
            }
            else if (choice == 6) {
                myAgency.printApartmentsinBuildingsBigger();
                cout << "---------------------------------------------" << endl;
                cout << "Your selection: ";
                cin >> choice;

            }
            else if (choice == 7) {
                myAgency.printApartmentsinBuildingsCheaper();
                cout << "---------------------------------------------" << endl;
                cout << "Your selection: ";
                cin >> choice;
            }
            else if (choice == 8) {
                myAgency.printDailyorMonthly();
                cout << "---------------------------------------------" << endl;
                cout << "Your selection: ";
                cin >> choice;
            }
            else {
            cout << "Available Buildings:" << endl;
            myAgency.printBuildingsWithApartmentsInside();
            myAgency.printRentalPriceSpesificApartment();
            cout << "---------------------------------------------" << endl;
            cout << "Your selection: ";
            cin >> choice;

            }
           
        } while (choice != 0);
        if (flag == 0) {
            cout << "Thanks for choosing Agency Management System!" << endl;
            cout << "---------------------------------------------" << endl;
        }


    }


}


