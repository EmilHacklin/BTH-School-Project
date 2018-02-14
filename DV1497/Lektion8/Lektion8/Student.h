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
	Student(const Student& originalStudent);
	Student& operator=(const Student& originalStudent);
	int getRegNr() const;
	string getEducationPgm() const;
	virtual string toStringSpec() const;
	virtual Student* clone() const;
	virtual ~Student();
};