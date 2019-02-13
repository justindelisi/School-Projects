#include <iostream>
#include <string>
#include <iomanip>
#include "Magazine.h"
using namespace std;

string magazine::getExtra()
{
	return to_string(issueNumber);
}
void magazine::setIssueNumber(int is)
{
	issueNumber = is;
}

char magazine::getType()
{
	return type;
}

void magazine::print()
{
	cout << " ID         Title                Status      Issue " << endl;
	cout << setw(8) << left << getID() << setw(25) << left << getName() << "    ";
	if (getStatus() == true)
		cout << setw(8) << left << "In ";
	else
		cout << setw(8) << left << "Out ";
	cout << setw(15) << issueNumber << endl;

}

magazine::magazine(int i, string n, bool s, int is)
	:item(i, n, s)
{
	issueNumber = is;
}
magazine::magazine():item()
{
	issueNumber = 0;
}