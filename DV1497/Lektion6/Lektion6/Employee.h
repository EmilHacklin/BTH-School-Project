#pragma once
#include "Person.h"
class Employee :
	public Person
{
private:
	int salary;
public:
	Employee(string name, string email, int salary = 0);
	int getSalary() const;
	string toString() const;
	~Employee();
};

