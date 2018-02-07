#include "Employee.h"

Employee::Employee(string name, string email, int salary) :Person(name, email)
{
	this->salary = salary;
}

int Employee::getSalary() const
{
	return this->salary;
}

string Employee::toString() const
{
	return Person::toString() + "\nSalary: " + to_string(this->salary);
}

Employee::~Employee()
{
	cout << "Destroying a employee" << endl;
}