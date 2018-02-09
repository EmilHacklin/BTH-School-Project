#pragma once
#include"Employee.h"
#include"Student.h"

const int INCREMENT = 10;

class University
{
private:
	Person * *persons;
	int capacity;
	int nrOfStudents;
	int nrOfEmployees;
	void expandPersons();
public:
	University();
	University(const University& originalUniversity);
	University& operator=(const University& originalUniversity);
	void add(const string name, const string email, const int regNr,const string educationPgm);
	void add(const string name, const string email, const int salary);
	int getNrOfStudents() const;
	int getNrOfEmployees() const;
	int getNrOfPersons() const;
	string getAsStrings(const string* arr, const string what) const;
	int totalSalary() const;
	bool remove(const string name);
	bool readFromFile(const string filePath) const;
	bool whriteToFile(const string filePath) const;
	~University();
};

