#pragma once
#include "Person.h"

class Student :
	public Person
{
private:
	int regNr;
	string educationPgm;
public:
	Student(string name = "?", string email = "?", int regNr = 0, string educationPgm = "?");
	int getRegNr() const;
	string getEducationPgm() const;
	virtual string toString() const;
	virtual ~Student();
};