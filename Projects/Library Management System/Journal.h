
#ifndef JOURNAL_H
#define JOURNAL_H
#include <string>
#include "Item.h"
using namespace std;
class journal : public item
{
public:
	string getExtra();
	//returns volume
	char getType();
	//returns 'J'
	void print();
	//prints to screen
	journal(int i, string n, bool s, int v);
	//constructor with paramaters
	journal();
	//default constructor

private:
	int volume;
	const char type = 'J';
};
#endif // !JOURNAL_H
