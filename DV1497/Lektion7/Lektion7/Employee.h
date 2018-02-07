#pragma once
#include "Person.h"

class Employee :
	public Person
{
private:
	int salary;
public:
	Employee(string name = "?", string email = "?", int salary = 0);
	int getSalary() const;
	virtual string toStringSpec() const;
	virtual ~Employee();
};