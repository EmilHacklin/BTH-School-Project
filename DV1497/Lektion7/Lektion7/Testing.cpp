#include<iostream>
#include "Student.h"
#include "Employee.h"

using namespace std;

int main()
{
	Person p("Kalle", "kalle@gmail.com");
	cout << "The name of person p " << p.getName() << endl
		<< "and toString() returns " << p.toString() << endl;

	Student s("Lisa", "lisa@bth.se", 123, "ITSÄK");
	cout << "The name of student s " << s.getName() << endl
		<< "and toString() returns " << s.toString() << endl
		<< "and regNr is " << s.getRegNr() << endl
		<< "and EducationPgm is " << s.getEducationPgm() << endl;

	Person* p1 = nullptr;
	Student* s1 = nullptr;
	Employee* e1 = new Employee("Rut", "rut@bth.se", 43000);
	cout << "pointer e1 is pointing to a Employee object calling toString()"
		<< e1->toString() << endl;

	p1 = new Person("Rune", "rune@hotmail.com");
	cout << "pointer p1 is pointing to a Person object calling toString()"
		<< p1->toString() << endl;

	s1 = new Student("Britta", "britta@bth.se", 432, "Spel");
	cout << "pointer s1 is pointing to a Student object calling toString()"
		<< s1->toString() << endl;

	delete p1;
	p1 = s1; //Pekara av basklasstyp kan peka på (ha adressen till objekt av subklasstyp
			 //s1 = p1; men inte det omvända!!!
	cout << "pointer p1 is pointing to a Student object calling toString()"
		<< p1->toString() << endl;

	delete s1;
	delete e1;

	cin.get();
	return 0;
}