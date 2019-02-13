#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include "Item.h"
using namespace std;

string item::getName()
{
	return Name;
}
int item::getID()
{
	return ID;
}
bool item::getStatus()
{
	return status;
}
void item::setStatus(bool stat)
{
	status = stat;
}

item::item(int i, string n, bool s)
{
	ID = i;
	Name = n;
	status = s;

}
item::item()
{
	ID = 0;
	Name = " ";
	status = false;
}