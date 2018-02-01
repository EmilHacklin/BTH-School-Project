#include "Friend.h"

Friend::Friend(string name, int birthYear)
{
	//The parameters values gets copied to the membervaribles
	this->name = name;
	this->birthYear = birthYear;
}

Friend::Friend()
{
	this->name = "?";
	this->birthYear = 0;
}

string Friend::getName()
{
	return this->name;
}

int Friend::getBirthYear()
{
	return this->birthYear;
}

void Friend::setName(string name)
{
	this->name = name;
}

void Friend::setBirthYear(int birthYear)
{
	if (birthYear < 2000)
	{
		this->birthYear = birthYear;
	}
}

string Friend::toString()
{
	return this->name + " born in " + to_string(this->birthYear);
}
