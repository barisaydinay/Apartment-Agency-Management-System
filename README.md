# Apartment-Agency-Management-System
I implemented several C++ classes for an apartment agency management  system. This project aims to create a storage system for rental apartments. It will allow the  users to search for details of apartments available for an agency and their total cost for a specific  time interval.


*Classes*

AGENCY :
For each agency, I stored:
• Name (data type: char pointer)
• Buildings
For each agency, implemented the following member functions:
• A default (no-argument) constructor
• A constructor to initialize all the member variables
• Getter and setter functions as needed.
• A function to add a new building to the agency
• A function to print all the buildings with their addresses only
• A function to print the apartments in each building that have the specified number of rooms
• A function to print the apartments in each building which are bigger than the specified 
apartment size
• A function to print the apartments in each building which are cheaper than the specified 
price in a specified number of days
• A function to print the apartments in each building that are either daily or monthly rental
• A function to calculate the rental price of a specific apartment by using its given id in a 
specified number of days


BUILDING :
For each building, I stored:
• Building id (data type: int)
• Address (data type: char pointer)
• Apartments
For each building, implemented the following member functions:
• A default (no-argument) constructor
• A constructor to initialize all the member variables
• Getter and setter functions as needed.
• A function to add a new apartment to the building
• A function to print the apartments in a building that have the specified number of rooms
• A function to print the apartments in a building which are bigger than the specified 
apartment size
• A function to print the apartments in a building which are cheaper than the specified price 
in a specified number of days
• A function to print the apartments in a building that are either daily or monthly rental
• A function to calculate the rental price of a specific apartment by using its given id in a 
specified number of days
• A function to print a building with its address
• A function to print a building with its address and all its apartments


APARTMENT :
For each apartment, I stored:
• Apartment id (data type: int)
• Number of rooms (data type: int)
• Price (data type: int, monthly or daily rent in GBP)
• Size (data type: int)
For each apartment implemented the following member functions:
• A default (no-argument) constructor
• A constructor to initialize all the member variables
• Getter and setter functions as needed
• A function to print an apartment with its details


DAILY RENTAL APARTMENTS :
Each daily rental apartment is an apartment with an additional following attribute:
• decorationStyle (data type: enum apartType {Minimalist, Modern, Classic})
For each daily rental apartment, implemented the following member functions:
• A default (no-argument) constructor
• A constructor to initialize all the member variables
• A function to calculate the rental price in a specified number of days
• A function to print a daily rental apartment with its details


MONTHLY RENTAL APARTMENTS :
Each monthly rental apartment is an apartment with the following additional attribute:
• hasFurniture (datatype: bool)
For each monthly rental apartment, implemented the following member functions:
• A default (no-argument) constructor
• A constructor to initialize all the member variables
• A function to calculate the rental price in a specified number of days
• A function to print a monthly rental apartment with its details.


*APARTMENT AGENCY MANAGEMENT SYSTEM*


I implemented a command-line interface for the apartment agency management system,
which provides the following menu for the agency with the name “Manchester Comfort 
Apartments”.

1. Add a new building to the agency
2. Add a new apartment (monthly or daily rental) to a building
3. List all buildings with their addresses
4. List all apartments available for the agency
5. List all apartments that have the specified number of rooms
6. List all apartments which are bigger than the specified apartment size
7. List all apartments which are cheaper than the specified price in a specified number of days
8. List all apartments that are either daily or monthly rental
9. Calculate the price of a specific apartment in a specified number of days
0. Exit




