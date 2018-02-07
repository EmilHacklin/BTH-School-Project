#include "Person.h"

Person::Person(string name, string email)
{
	this->name = name;
	this->email = email;
}

string Person::getName() const
{
	return this->name;
}

string Person::toString() const
{
	return "\nName: " + this->name + "\nEmail-address: " + this->email;
}


Person::~Person()
{
	cout << "Destroying a person" << endl;
}