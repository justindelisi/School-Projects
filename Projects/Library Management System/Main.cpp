#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Library.h"
using namespace std;

int main()
{
	Library library;//starts a library with 5 of each type of item
	int option;
	cout << "Welcome to the Delisi Library Management System" << endl
		<< "***********************************************" << endl;
	while (true)
	{
		cout << "Please select from the following options: " << endl
			<< "1. Search Catalog" << endl
			<< "2. List all items by type" << endl
			<< "3. Checkout an item" << endl
			<< "4. Return an item" << endl
			<< "5. Add a new item" << endl
			<< "6. Exit" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			library.search();
			break;
		case 2:
			library.listAll();
			break;
		case 3: 
			library.checkOutItem();
			break;
		case 4: 
			library.returnItem();
			break;
		case 5: 
			library.addItem();
			break;
		case 6:
			cout << "Thank you for using Delisi Library Management System" << endl;
			return 0;
		default:
			cout << "Invalid entry. Please re-try. " << endl;
			break;
		}
			
	}
}