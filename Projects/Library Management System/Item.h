#include <string>
#include <vector>
using namespace std;
#ifndef ITEM_H
#define ITEM_H


class item
{
public:
	string getName();
	//returns name of item
	int getID();
	//return id of item
	bool getStatus();
	// returns status of item. True if is in library, otherwise false
	void setStatus(bool);
	//sets the status of the selected item
	virtual char getType() = 0;
	//pure virtual function that returns the type of item
	virtual string getExtra() = 0;
	//pure virtual function that returns the extra info from item
	//Author for books, issue number for magazines, volume number for journals
	virtual void print() = 0;
	//pure virtual print function
	item(int i, string n, bool s);
	//constuctor with paramaters
	item();//default constructor

private:
	int ID;
	string Name;
	bool status;
};
#endif // !ITEM_H
