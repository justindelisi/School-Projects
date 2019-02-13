#ifndef MAGAZINE_H
#define MAGAZINE_H


#include <string>
#include "Item.h"

class magazine : public item
{
public:
	string getExtra();
	//returns issuenumber
	void setIssueNumber(int);
	//sets issue number
	char getType();
	//returns 'M'
	void print();
	//prints to screen

	magazine(int i, string n, bool s, int is);
	//constuctor with paramaters
	magazine();
	//default constructor
private:
	int issueNumber;
	const char type = 'M';
};
#endif // !MAGAZINE_H

