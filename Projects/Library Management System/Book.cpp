#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h"
using namespace std;

string book::getExtra()
{
	return author;
}
char book::getType()
{
	return type;
}
void book::print() 
{
	cout << " ID         Title                Status      Author " << endl;
	cout << setw(8) << left << getID() << setw(25) << left << getName() << "    ";
	if (getStatus() == true)
		cout << setw(8) << left << "In ";
	else
		cout << setw(8) << left << "Out ";
	cout << setw(15)<< author << endl;
}

book::book(int i, string n, bool s, string a)
	:item(i, n, s)
{
	author = a;
}
book::book():item()
{
	author = " ";
}