#include "Friend.h"
#include <iostream>
using namespace std;

Friend::Friend(string name, int birthYear)
{
	// parametrarnas värden kopieras till objektets medlemsvariabler
	this->name = name; 
	this->birthYear = birthYear;
}

Friend::~Friend()
{
	cout << "Destructing the object " << this->toString() << endl;
}

//Friend::Friend()
//{
//	this->name = "?";
//	this->birthYear = 0;
//}

string Friend::getName() const
{
	return this->name;// returnera en kopia av namnet
}

void Friend::setName(string name)
{
	this->name = name;
}

void Friend::setBirthYear(int birthYear)
{
	if (birthYear >= 1900)
	{
		this->birthYear = birthYear;
	}
}

int Friend::age(int year) const
{
	return year - this->birthYear;
}

string Friend::toString() const
{
	string result;
	result = "The name is " + this->name + " and the year of birth is " + to_string(this->birthYear);
	return result;
}

bool Friend::operator==(const Friend &other) const
{
	/*bool isEqual = false;
	if (this->name == other.name && this->birthYear == other.birthYear)
	{
		isEqual = true;
	}
	return isEqual;*/
	return this->name == other.name && this->birthYear == other.birthYear;

}

bool Friend::operator<(const Friend &other) const
{
	return this->birthYear < other.birthYear;
}