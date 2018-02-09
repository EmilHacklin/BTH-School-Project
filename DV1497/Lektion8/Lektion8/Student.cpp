#include "Student.h"

Student::Student(string name, string email, int regNr, string educationPgm)
	:Person(name, email)
{
	this->regNr = regNr;
	this->educationPgm = educationPgm;
}

Student::Student(const Student & originalStudent):
	Person(originalStudent)
{
	if (this != &originalStudent)
	{
		this->regNr = originalStudent.regNr;
		this->educationPgm = originalStudent.educationPgm;
	}
}

Student & Student::operator=(const Student & originalStudent)
{
	if (this != &originalStudent)
	{
		Person::operator=(originalStudent);
		this->regNr = originalStudent.regNr;
		this->educationPgm = originalStudent.educationPgm;
	}
	return *this;
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