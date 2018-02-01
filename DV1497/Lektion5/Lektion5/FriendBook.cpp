#include "FriendBook.h"

void FriendBook::expand()
{
	this->capacity += 3;
	//Friend* temp = new Friend[this->capacity];
	Friend* *temp = new Friend*[this->capacity];
	for (int i = 0; i < this->nrOfFriends; i++)
	{
		temp[i] = this->myFriends[i];
	}

	delete[] this->myFriends;
	this->myFriends = temp;
}

void FriendBook::copy(const FriendBook & orginalObject)
{
	this->title = orginalObject.title;
	this->capacity = orginalObject.capacity;
	this->nrOfFriends = orginalObject.nrOfFriends;
	this->myFriends = new Friend*[this->capacity];
	for (unsigned short i = 0; i < this->nrOfFriends; i++)
	{
		this->myFriends[i] = new Friend(*orginalObject.myFriends[i]);
	}
}

void FriendBook::dealocate()
{
	for (unsigned short i = 0; i < this->nrOfFriends; i++)
	{
		delete this->myFriends[i];
	}
	delete[] this->myFriends;
}

FriendBook::FriendBook(string title, int capacity)
{
	this->title = title;
	this->capacity = capacity;
	this->nrOfFriends = 0;
	//this->myFriends = new Friend[this->capacity]; 
	this->myFriends = new Friend*[this->capacity];
}

FriendBook::FriendBook(const FriendBook & orginalObject)
{
	this->copy(orginalObject);
}

FriendBook::~FriendBook()
{
	this->dealocate();
}

FriendBook& FriendBook::operator=(const FriendBook & orginalObject)
{
	this->dealocate();
	this->copy(orginalObject);
	return *this;
}

bool FriendBook::addFriend(string name, int birthYear)
{
	// finns vännen redan?
	bool didExist = false;
	//Friend aFriend(name, birthYear);
	Friend* aFriend = new Friend(name, birthYear);
	for (int i = 0; i < this->nrOfFriends; i++)
	{
		//if (aFriend == this->myFriends[i])
		if (*aFriend == *this->myFriends[i]) // JÄMFÖR OBJEKTEN
		{
			didExist = true;
		}
	}

	if (!didExist)
	{
		if (this->nrOfFriends == this->capacity)
		{
			// expandera
			this->expand();
		}

		this->myFriends[this->nrOfFriends] = aFriend;
		this->nrOfFriends++;
	}
	else
	{
		delete aFriend; // objetet läggs inte in i arrayen och måste avallokeras
	}
	return !didExist;
}

bool FriendBook::removeFriend(string name, int birthYear)
{
	// princip?
	// ersätt den som ska tas bort med den som är placerad sist eftersom ordningen är oväsentlig
	// hade ordningen varit väsentlig flyttas alla efter den som ska tas bort
	// ett steg <-
	Friend shearchFriend(name, birthYear);
	for (unsigned short i = 0; i < this->nrOfFriends; i++)
	{
		if (*this->myFriends[i] == shearchFriend)
		{
			delete this->myFriends[i];
			this->nrOfFriends--;
			this->myFriends[i] = this->myFriends[this->nrOfFriends];
			return true;
		}
	}
	return false;
}

bool FriendBook::existFriend(string name, int birthYear) const
{
	Friend searchFriend(name, birthYear);
	unsigned short index = 0;

	for (unsigned short i = 0; i < this->nrOfFriends; i++)
	{
		if (*this->myFriends[i] == searchFriend)
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
	this->dealocate();
	this->myFriends = new Friend*[this->capacity];
	this->nrOfFriends = 0;
}

void FriendBook::getFriendsAsString(string arr[], int nrOf) const// ???
{
	// fyller i arrayen arr med strängarna som erhålls från 
	// varje vän-objekt i den interna arrayen myFriends vid anrop av toString()
	if (nrOf > this->nrOfFriends)
	{
		nrOf = this->nrOfFriends;
	}
	for (int i = 0; i < nrOf; i++)
	{
		arr[i] = this->myFriends[i]->toString();
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
			outputFile << this->myFriends[i]->getName() << endl;
			outputFile << abs(this->myFriends[i]->age(0)) << endl;
		}
	}
	outputFile.close();
	// öppna filen med namnet filename
	// om filen är öppen
		// skriv antalet vänner på filen och byt rad
		// för varje vän
			// skriv namnet på filen och byt rad
			// skriv födelseåret på filen och byt rad
	// stäng filen
}

void FriendBook::readFromFile(string filename)
{
	// öppna filen med namnet filename
	// om filen är öppen
		// läs antalet vänner från filen och ignorera radslutet
		// för antalet vänner
			// läs namn
			// läs födelseår och ignorera radslutet
			// lägg till en vän på nästa lediga plats (hur??)
	// stäng filen
	ifstream inputFile(filename);
	if (inputFile.is_open())
	{
		inputFile >> this->title;
		inputFile.ignore((std::numeric_limits<streamsize>::max)(), '\n');
		inputFile >> this->capacity;
		inputFile.ignore((std::numeric_limits<streamsize>::max)(), '\n');
		this->dealocate();
		this->myFriends = new Friend*[this->capacity];
		inputFile >> this->nrOfFriends;
		inputFile.ignore((std::numeric_limits<streamsize>::max)(), '\n');
		for (unsigned short i = 0; i < this->nrOfFriends; i++)
		{
			string name = "";
			int birthYear = 0;
			inputFile >> name;
			inputFile.ignore((std::numeric_limits<streamsize>::max)(), '\n');
			inputFile >> birthYear;
			inputFile.ignore((std::numeric_limits<streamsize>::max)(), '\n');
			this->myFriends[i] = new Friend(name, birthYear);
		}
	}
	inputFile.close();
}
