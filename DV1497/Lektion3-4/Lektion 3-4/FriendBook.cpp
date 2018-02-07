#include "FriendBook.h"

FriendBook::FriendBook(string title, int capacity)
{
	this->title = title;
	this->capacity = capacity;
	this->nrOfFriends = 0;
	this->myFriends = new Friend[this->capacity]; 
}

bool FriendBook::addFriend(string name, int birthYear)
{
	// finns vännen redan?
	bool didExist = false;
	Friend aFriend(name, birthYear);
	for (int i = 0; i < this->nrOfFriends; i++)
	{
		if (aFriend == this->myFriends[i])
		{
			didExist = true;
		}
	}

	if (!didExist)
	{
		if (this->nrOfFriends == this->capacity)
		{
			Friend* tempArray = new Friend[(this->capacity * 2)];
			for (unsigned short i = 0; i < this->capacity; i++)
			{
				tempArray[i].setName(this->myFriends[i].getName());
				tempArray[i].setBirthYear(abs(this->myFriends[i].age(0)));
			}
			delete[] this->myFriends;
			this->myFriends = tempArray;
		}
		this->myFriends[this->nrOfFriends] = aFriend;
		this->nrOfFriends++;
	}
	return !didExist;
}

bool FriendBook::removeFriend(string name, int birthYear)
{
	Friend searchFriend(name, birthYear);
	bool found = false;
	unsigned short index = 0;

	while (!found && index < this->nrOfFriends)
	{
		if (this->myFriends[index]== searchFriend)
		{
			found = true;
		}
		else
		{
			index++;
		}
	}

	if (found)
	{
		this->nrOfFriends--;
		this->myFriends[index].setName(this->myFriends[this->nrOfFriends].getName());
		this->myFriends[index].setBirthYear(abs(this->myFriends[this->nrOfFriends].age(0)));
		this->myFriends[this->nrOfFriends].setName("?");
		this->myFriends[this->nrOfFriends].setBirthYear(0);
		return true;
	}
	else
	{
		return false;
	}
}

bool FriendBook::existFriend(string name, int birthYear) const
{
	Friend searchFriend(name, birthYear);
	unsigned short index = 0;

	for (unsigned short i = 0; i < this->nrOfFriends; i++)
	{
		if (this->myFriends[i]== searchFriend)
		{
			return true;
		}
		else
		{
			index++;
		}
	}
	return false;
}

void FriendBook::getFriendsBornByYearAsString(string arr[], int nrOf, int year) const
{
	for (unsigned short i = 0; i < nrOf; i++)
	{
		if (this->myFriends[i].age(year) >= 0)
		{
			arr[i] = this->myFriends[i].toString();
		}
	}
}

int FriendBook::getNrOfFriends() const
{
	return this->nrOfFriends;
}

string FriendBook::getTitle() const
{
	return this->title;
}

void FriendBook::setTitle(string title)
{
	this->title = title;
}

void FriendBook::clear()
{
	this->nrOfFriends = 0;
}

void FriendBook::getFriendsAsString(string arr[], int nrOf) const
{
	for (unsigned short i = 0; i < nrOf; i++)
	{
		arr[i] = this->myFriends[i].toString();
	}
}

void FriendBook::saveOnFile(string filename) const
{
	ofstream outputFile(filename);
	if (outputFile.is_open())
	{
		outputFile << this->getTitle() << endl;
		outputFile << this->capacity << endl;
		outputFile << this->nrOfFriends << endl;
		for (unsigned short i = 0; i < this->nrOfFriends; i++)
		{
			outputFile << this->myFriends[i].getName() << endl;
			outputFile << abs(this->myFriends[i].age(0)) << endl;
		}
	}
	outputFile.close();
}

void FriendBook::readFromFile(string filename)
{
	ifstream inputFile(filename);
	if (inputFile.is_open())
	{
		inputFile >> this->title;
		inputFile.ignore((std::numeric_limits<streamsize>::max)(), '\n');
		inputFile >> this->capacity;
		inputFile.ignore((std::numeric_limits<streamsize>::max)(), '\n');
		delete[] this->myFriends;
		this->myFriends = new Friend[this->capacity];
		inputFile >> this->nrOfFriends;
		inputFile.ignore((std::numeric_limits<streamsize>::max)(), '\n');
		for (unsigned short i = 0; i < this->nrOfFriends; i++)
		{
			string name = "";
			int birthYear = 0;
			inputFile >> name;
			inputFile.ignore((std::numeric_limits<streamsize>::max)(), '\n');
			this->myFriends[i].setName(name);
			inputFile >> birthYear;
			inputFile.ignore((std::numeric_limits<streamsize>::max)(), '\n');
			this->myFriends[i].setBirthYear(birthYear);
		}
		inputFile.close();
	}
}

FriendBook::~FriendBook()
{
	delete[] this->myFriends;
}
