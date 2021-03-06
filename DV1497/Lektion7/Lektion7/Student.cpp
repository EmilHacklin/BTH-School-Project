#include "Student.h"

Student::Student(string name, string email, int regNr, string educationPgm)
	:Person(name, email)
{
	this->regNr = regNr;
	this->educationPgm = educationPgm;
}

int Student::getRegNr() const
{
	return this->regNr;
}

string Student::getEducationPgm() const
{
	return this->educationPgm;
}

string Student::toStringSpec() const
{
	return "\nReg nr: " + to_string(this->regNr)
		+ "\nEducation program: " + this->educationPgm;
}

Student::~Student()
{
	cout << "Destroying a student" << endl;
}