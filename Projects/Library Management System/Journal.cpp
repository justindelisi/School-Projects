#include <iostream>
#include <string>
#include <iomanip>
#include "Journal.h"
using namespace std;

string journal::getExtra()
{
	return to_string(volume);
}
char journal::getType()
{
	return type;
}
void journal::print()
{
	cout << " ID         Title                Status      Volume " << endl;
	cout << setw(8) << left << getID() << setw(25) << left << getName() << "    ";
	if (getStatus() == true)
		cout << setw(8) << left << "In ";
	else
		cout << setw(8) << left << "Out ";
	cout << setw(15) << volume << endl;
}

journal::journal(int i, string n, bool s, int v)
	:item(i, n, s)
{
	volume = v;
}
journal::journal():item()
{
	volume = 0;
}