#include "University.h"

void University::expandPersons()
{
	Person* *temp = new Person*[this->capacity + INCREMENT];
	for (int i = 0; i < this->getNrOfPersons(); i++)
	{
		temp[i] = this->persons[i];
	}
	delete[] this->persons;
	this->persons = temp;
	this->capacity += INCREMENT;
}

University::University()
{
	this->persons = new Person*[INCREMENT];
	this->capacity = INCREMENT;
	this->nrOfStudents = 0;
	this->nrOfEmployees = 0;
}

University::University(const University & originalUniversity)
{
	if (this != &originalUniversity)
	{
		this->capacity = originalUniversity.capacity;
		this->persons = new Person*[this->capacity];
		this->nrOfStudents = originalUniversity.nrOfStudents;
		this->nrOfStudents = originalUniversity.nrOfEmployees;
		for (int i = 0; i < this->getNrOfPersons(); i++)
		{
			this->persons[i] = originalUniversity.persons[i]->clone();
			/*Student *stuPtr = dynamic_cast<Student*>(originalUniversity.persons[i]);
			if (stuPtr != nullptr)
			{
				this->persons[i] = new Student(*stuPtr);
			}
			else
			{
				this->persons[i] = new Employee(*dynamic_cast<Employee*>(originalUniversity.persons[i]));
			}*/
		}
	}
}

University & University::operator=(const University & originalUniversity)
{
	if (this != &originalUniversity)
	{
		this->~University;
		this->capacity = originalUniversity.capacity;
		this->persons = new Person*[this->capacity];
		this->nrOfStudents = originalUniversity.nrOfStudents;
		this->nrOfStudents = originalUniversity.nrOfEmployees;
		for (int i = 0; i < this->getNrOfPersons(); i++)
		{
			this->persons[i] = originalUniversity.persons[i]->clone();
			/*Student *stuPtr = dynamic_cast<Student*>(originalUniversity.persons[i]);
			if (stuPtr != nullptr)
			{
				this->persons[i] = new Student(*stuPtr);
			}
			else
			{
				this->persons[i] = new Employee(*dynamic_cast<Employee*>(originalUniversity.persons[i]));
			}*/
		}
	}
	return *this;
}

void University::add(const string name, const string email, const int regNr, const string educationPgm)
{
	if (this->getNrOfPersons() == (this->capacity - 1))
	{
		this->expandPersons();
	}
	this->persons[this->getNrOfPersons()] = new Student(name, email, regNr, educationPgm);
	this->nrOfStudents++;
}

void University::add(const string name, const string email, const int salary)
{
	if (this->getNrOfPersons() == (this->capacity - 1))
	{
		this->expandPersons();
	}
	this->persons[this->getNrOfPersons()] = new Employee(name, email, salary);
	this->nrOfEmployees++;
}

int University::getNrOfStudents() const
{
	return this->nrOfStudents;
}

int University::getNrOfEmployees() const
{
	return this->nrOfEmployees;
}

int University::getNrOfPersons() const
{
	return (this->nrOfStudents + this->nrOfEmployees);
}

string University::getAsStrings(const string * arr, const string what) const
{
	string returnString = "";
	for (int i = 0; i < this->getNrOfPersons(); i++)
	{
		returnString += this->persons[i]->toStringSpec();
		returnString += "\n";
	}
	return returnString;
}

int University::totalSalary() const
{
	int totalSalary = 0;
	for (int i = 0; i < this->getNrOfPersons(); i++)
	{
		if (dynamic_cast<Employee*>(this->persons[i]))
		{
			totalSalary += dynamic_cast<Employee*>(this->persons[i])->getSalary();
		}
	}
	return totalSalary;
}

bool University::remove(const string name)
{
	int i = 0;
	while (i < this->getNrOfPersons())
	{
		if (this->persons[i]->getName() == name)
		{ 
			Student *stuPtr = dynamic_cast<Student*>(this->persons[i]);
			if (stuPtr != nullptr)
			{
				this->nrOfStudents--;
			}
			else
			{
				this->nrOfEmployees--;
			}
			delete this->persons[i];
			if (i != this->getNrOfPersons())
			{
				this->persons[i] = this->persons[(this->getNrOfPersons() - 1)];
			}
			i = this->getNrOfPersons();
		}
		else
		{
			i++;
		}
	}
	return false;
}

bool University::readFromFile(const string filePath) const
{
	ifstream file;
	file.open(filePath);
	if (file.is_open())
	{
		//this->~University();
		//string convertString = "";
		//file >> convertString;
		//file.ignore();
		//this->capacity = stoi(convertString);
		while (!file.eof())
		{

		}
		file.close();
		return true;
	}
	else
	{
		return false;
	}
}

bool University::whriteToFile(const string filePath) const
{
	return false;
}

University::~University()
{
	for (int i = 0; i < this->getNrOfPersons(); i++)
	{
		delete this->persons[i];
	}
	this->nrOfEmployees = 0;
	this->nrOfStudents = 0;
	delete[] this->persons;
	this->capacity = 0;
}