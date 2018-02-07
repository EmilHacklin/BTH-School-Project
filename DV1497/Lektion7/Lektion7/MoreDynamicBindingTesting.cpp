#include<iostream>
#include<string>
#include<ctime>
#include"Student.h"
#include"Employee.h"

using namespace std;

int main()
{
	Person *persons[10] = { nullptr };
	int nrOfPeople = 0, pos = 0;
	int seed = static_cast<int>(time(0));
	string searchName = "";
	bool personFound = false;

	persons[0] = new Employee("Lisa", "lisa@bth.se", 42000);
	persons[1] = new Student("Kalle", "kalle@bth.se", 11111, "Nurse");
	persons[2] = new Employee("Gert", "gert@bth.se", 40000);
	persons[3] = new Employee("Rut", "rut@bth.se", 32000);
	persons[4] = new Student("Kaj", "kaj@bth.se", 11112, "CIVSPEL");
	nrOfPeople = 5;

	srand(seed);
	for (int i = 0; i < nrOfPeople; i++)
	{
		cout << persons[i]->toString() << endl;
	}

	cout << "\nEnter a name to find the person: ";
	getline(cin, searchName);
	do
	{
		if (searchName == persons[pos]->getName())
		{
			cout << "\nFound the person!" << endl;
			cout << persons[pos]->toString() << endl;;
			personFound = true;
		}
		else
		{
			pos++;
		}
	} while (!personFound && pos < nrOfPeople);
	if (pos == nrOfPeople)
	{
		cout << "\nPerson do not exist!" << endl;
		pos = -1;
	}

	for (int i = 0; i < nrOfPeople; i++)
	{
		cout << "Destroying: " << persons[i]->getName() << endl;
		delete persons[i];
	}

	cin.get();
	return 0;
}