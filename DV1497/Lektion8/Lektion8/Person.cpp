#include "Person.h"

Person::Person(string name, string email)
{
	this->name = name;
	this->email = email;
}

Person::Person(const Person & originalPerson)
{
	if (this != &originalPerson)
	{
		this->name = originalPerson.name;
		this->email = originalPerson.email;
	}
}

Person & Person::operator=(const Person & originalPerson)
{
	if (this != &originalPerson)
	{
		this->name = originalPerson.name;
		this->email = originalPerson.email;
	}
	return *this;
}

string Person::getName() const
{
	return this->name;
}

string Person::toString() const
{
	return "\nName: " + this->name + "\nEmail-address: " + this->email + this->toStringSpec();
}

Person::~Person()
{
	cout << "Destroying a person" << endl;
}