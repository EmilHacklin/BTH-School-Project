#include "Employee.h"

Employee::Employee(string name, string email, int salary) :Person(name, email)
{
	this->salary = salary;
}

Employee::Employee(const Employee & originalEmployee):
	Person(originalEmployee)
{
	if (this != &originalEmployee)
	{
		this->salary = originalEmployee.salary;
	}
}

Employee & Employee::operator=(const Employee & originalEmployee)
{
	if (this != &originalEmployee)
	{
		Person::operator=(originalEmployee);
		this->salary = originalEmployee.salary;
	}
	return *this;
}

int Employee::getSalary() const
{
	return this->salary;
}

string Employee::toStringSpec() const
{
	return "\nSalary: " + to_string(this->salary);
}

Employee* Employee::clone() const
{
	return new Employee(*this);
}

Employee::~Employee()
{
	cout << "Destroying a employee" << endl;
}