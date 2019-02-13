#include <vector>
#include "Item.h"
#include "Book.h"
#include "Journal.h"
#include "Magazine.h"
using namespace std;

class Library
{
public:
	void addItem();
	//has user enter in each field for a new entry into library
	//checks if item is already in library
	//adds item to vector of item base class pointers
	void checkOutItem();
	//uses search function to look for the item to be checked out
	//if item is in, changes status to out (false)
	void returnItem();
	//uses search function to look for item to be returned
	//if status is out, changes status to in (true)
	int search();
	//takes input from user either title or author (for books only)
	//checks through vector to see if any matches
	//if found prints to screen and returns the index of the item
	void listAll();
	//takes input for which type of item user wants to list
	//iterates through vector and prints each item matching the type
	Library();
	//default constructor
	//adds in 5 of each type of item into vector of base class pointers
	~Library();
	//destructor
	//deletes all pointers in the vector

private:
	vector<item*>items;
};