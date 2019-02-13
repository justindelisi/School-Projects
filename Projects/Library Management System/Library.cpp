#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Library.h"
#include "Book.h"
#include "Journal.h"
#include "Magazine.h"
#include "Item.h"
using namespace std;

void Library::addItem()
{
	char type = ' ';
	int id, issue, vol;
	string nam, auth;
	bool flag = true;
	bool found = false;
	cout << "Please enter B for Book, "
		<< "M for Magazine, or J for Journal: ";
	cin >> type;
	type = toupper(type);
	if (type != 'B' && type != 'M' && type != 'J')
	{
		cout << "Invalid entry" << endl;
		addItem();
	}
	while (flag == true)
	{
		cout << "Enter the title of the item: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, nam);
		if (type == 'B')
		{
			cout << "Enter the author name: ";
			getline(cin, auth);
			for (unsigned int i = 0; i < items.size(); i++)
			{
				if (items[i]->getName() == nam && items[i]->getExtra() == auth)
				{
					found = true;
					cout << "This item already exists. Please re-enter" << endl;
					break;
				}
					
			}
			if(found == false)
			{
				id = items.back()->getID() + 1;
				items.push_back(new book(id, nam, true, auth));
				cout << nam << " has been added to the library." << endl;
				flag = false;
			}
				
		}
		if (type == 'M')
		{
			cout << "Enter the issue number: ";
			cin >> issue;
			for (unsigned int i = 0; i < items.size(); i++)
			{
				if (nam == items[i]->getName() && type == items[i]->getType() 
					&& to_string(issue) == items[i]->getExtra())
				{
					found = true;
					cout << "This item already exists. Please re-enter" << endl;
					break;
				}

			}
			if (found == false)
			{
				id = items.back()->getID() + 1;
				items.push_back(new magazine(id, nam, true, issue));
				cout << nam << " Issue: " << issue << " has been added to the library." << endl;
				flag = false;
			}
				
		}
		if (type == 'J')
		{
			cout << "Enter the volume number: ";
			cin >> vol;
			for (unsigned int i = 0; i < items.size(); i++)
			{
				if (nam == items[i]->getName() && type == items[i]->getType()
					&& to_string(vol) == items[i]->getExtra())
				{
					found = true;
					cout << "This item already exists. Please re-enter" << endl;
					break;
				}

			}
			if (found == false)
			{
				id = items.back()->getID() + 1;
				items.push_back(new journal(id, nam, true, vol));
				cout << nam << " Volume: " << vol << " has been added to the library." << endl;
				flag = false;
			}
		}
	}
	

	


}

void Library::checkOutItem()
{
	char input;
	bool flag = true;
	int index = search();
	if (index >= 0)
	{
		
		if (items[index]->getStatus() == false)
		{
			cout << "Error: This item is already checked out." << endl;
			cout << "Search for another item to check out? Y/N" << endl;
			cin >> input;
			if (toupper(input) == 'Y')
				checkOutItem();
			else
				flag = false;
				return;
		}
		while (flag == true)
		{
			cout << "Check out this item? Y/N" << endl;
			cin >> input;
			if (toupper(input) == 'Y')
			{
				items[index]->setStatus(false);
				cout << items[index]->getName() << " checked out." << endl;
				flag = false;
			}
			else if (toupper(input) == 'N')
			{
				flag = false;
			}
			else
			{
				cout << "Invalid input. " << endl;
			}
		}
		
	}
	return;
}
//uses search function and if found changes the status from false to true
void Library::returnItem()
{
	char input;
	bool flag = true;
	int index = search(); //reuses search function to find the item
	if (index >= 0)
	{
		if (items[index]->getStatus() == true) // true means item is already returned
		{
			cout << "Error: This item is already returned." << endl;
			cout << "Search for another item to return? Y/N" << endl;
			cin >> input;
			if (toupper(input) == 'Y')
				returnItem();
			else
				flag = false;
				return;
		}
		while (flag == true)
		{
			cout << "Return this item? Y/N" << endl;
			cin >> input;
			if (toupper(input) == 'Y')
			{
				items[index]->setStatus(true); //changes status to in(true)
				cout << items[index]->getName() << " returned." << endl;
				flag = false;
			}
			else if (toupper(input) == 'N')
			{
				flag = false;
			}
			else
			{
				cout << "Invalid input. " << endl;
			}
		}

	}
	return;
}

//search input is title or author by the user and searches for that item
//returns the index of the item if found, or -1 if not found
int Library::search()
{
	string input;
	int option;
	bool flag = true;
	try
	{
		cout << "Enter 1 to search by title " << endl
			<< "Enter 2 to search by author (books only)" << endl;
		cin >> option;
		if (option != 1 && option != 2)
			throw string("wrong");//check for invalid input
		if (option == 1)
		{
			cout << "Enter the title: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, input);
			for (unsigned int i = 0; i < items.size(); i++)
			{
				if (items[i]->getName() == input) // if the name matches print the item and return
												  // it's index
				{
					cout << "Item found: " << endl;
					items[i]->print();
					cout << endl;
					return i;
				}
			}
		}
		if (option == 2)
		{
			cout << "Enter the author name: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, input);
			for (unsigned int i = 0; i < items.size(); i++)
			{
				if (items[i]->getExtra() == input)
				{
					cout << "Item found: " << endl;
					items[i]->print();
					cout << endl;
					return i;
				}
			}
		}
		while (flag == true) 
		{
			cout << "Item was not found. Search again? Y/N";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, input);
			if (input == "y" || input == "Y")
				search();
			else if (input == "n" || input == "N")
				return -1; //return an index of -1 to let other functions see it wasn't found
			else
				cout << "Invalid input" << endl;
		}
	}
	catch (string s)
	{
		cout << "Invalid option!" << endl;
		search();
	}
	
}
//list all takes in the type and prints a list of all items
void Library::listAll()
{
	char type;
	cout << "Enter B for books, M for magazines, or J for journals: ";
	cin >> type;
	type = toupper(type);
	if (type == 'B' || type == 'M' || type == 'J')
	{
		for (unsigned int i = 0; i < items.size(); i++)
		{
			if (items[i]->getType() == type)
			{
				items[i]->print();
				cout << endl;
			}
		}
		cout << endl;
	}
	else
	{
		cout << "Invalid input." << endl;
		listAll();
	}
	

}

//constructor initiates library with 5 of each type
Library::Library()
{
	items.push_back(new book(1001, "Animal Farm", true, "George Orwell"));
	items.push_back(new book(1002, "1984", true, "George Orwell"));
	items.push_back(new book(1003, "A Dance with Dragons", true, "George RR Martin"));
	items.push_back(new book(1004, "The Theory of Everything", true, "Stephen Hawking"));
	items.push_back(new book(1005, "Mistborn", true, "Brandon Sanderson"));

	items.push_back(new magazine(1006, "People", true, 23));
	items.push_back(new magazine(1007, "Variety", true, 37));
	items.push_back(new magazine(1008, "Red Book", true, 2013));
	items.push_back(new magazine(1009, "Popular Science", true, 289));
	items.push_back(new magazine(1010, "Us", true, 965));

	items.push_back(new journal(1011, "Science and Medicine", true, 3));
	items.push_back(new journal(1012, "Psychology Today", true, 22));
	items.push_back(new journal(1013, "Nature", true, 67));
	items.push_back(new journal(1014, "New Scientist", true, 101));
	items.push_back(new journal(1015, "Popular Culture", true, 72));
}

//destructor deletes each pointer and clears the vector
Library::~Library()
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
	items.clear();
}