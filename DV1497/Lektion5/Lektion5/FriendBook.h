#pragma once
#include <string>
#include<fstream>
#include "Friend.h"

using namespace std;
class FriendBook
{
private:
	string title;
	//Friend* myFriends; // f�r dynamisk allokering av array med Friend-objekt
	Friend* *myFriends; // f�r dynamsik allokering av arraye med Friend-pekare
	int capacity;
	int nrOfFriends;
	void expand();
	void copy(const FriendBook & orginalObject);
	void dealocate();
public:
	FriendBook(string title = "unknown", int capacity = 3);
	FriendBook(const FriendBook &orginalObject);
	~FriendBook();
	FriendBook& operator=(const FriendBook &orginalObject);
	bool addFriend(string name, int birthYear); // use� the == operator to avoid multiples
	// leta upp v�nnen motsvarande parametrarna och ta bort om denna finns, returner
	// sant om detta gjordes och falskt annar
	bool removeFriend(string name, int birthYear); 
	// returnera sant om v�n motsvarande parametrarna finns och falskt annars
	bool existFriend(string name, int birthYear) const;
	//void getFriendsBornByYearAsString(string arr[], int nrOf, int year) const;
	int getNrOfFriends() const;
	// returnera titel
	string getTitle() const;
	// �ndra titel till paramaterns v�rde
	void setTitle(string title);
	// t�m, tillse att antalet v�nner �r 0
	void clear();
	// fyller arrayen arr med str�ngar motsvarande toString() f�r de v�nner som finns i arrayen myFriends
	void getFriendsAsString(string arr[], int nrOf)const; //???
	// skriver v�nnernas namn och f�delse�r p� fil, �verst p� filen antalet v�nner
	void saveOnFile(string filename) const; 
	// l�ser uppgifter fr�n fil enligt ovan och l�gger in i arrayen myFriends
	void readFromFile(string filename); 
};