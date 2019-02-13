#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "Item.h"
using namespace std;

class book:public item
{
public:
	string getExtra();
	//returns author
	char getType();
	//returns 'B'
	void print();
	//prints to screen
	book(int i, string n, bool s, string a);
	//constructor with paramaters
	book();
	//default constructor
private:
	string author;
	const char type = 'B';

};
#endif // !BOOK_H