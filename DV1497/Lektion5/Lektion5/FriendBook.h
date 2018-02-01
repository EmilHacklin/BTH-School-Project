#pragma once
#include <string>
#include<fstream>
#include "Friend.h"

using namespace std;
class FriendBook
{
private:
	string title;
	//Friend* myFriends; // för dynamisk allokering av array med Friend-objekt
	Friend* *myFriends; // för dynamsik allokering av arraye med Friend-pekare
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
	bool addFriend(string name, int birthYear); // use  the == operator to avoid multiples
	// leta upp vännen motsvarande parametrarna och ta bort om denna finns, returner
	// sant om detta gjordes och falskt annar
	bool removeFriend(string name, int birthYear); 
	// returnera sant om vän motsvarande parametrarna finns och falskt annars
	bool existFriend(string name, int birthYear) const;
	//void getFriendsBornByYearAsString(string arr[], int nrOf, int year) const;
	int getNrOfFriends() const;
	// returnera titel
	string getTitle() const;
	// ändra titel till paramaterns värde
	void setTitle(string title);
	// töm, tillse att antalet vänner är 0
	void clear();
	// fyller arrayen arr med strängar motsvarande toString() för de vänner som finns i arrayen myFriends
	void getFriendsAsString(string arr[], int nrOf)const; //???
	// skriver vännernas namn och födelseår på fil, överst på filen antalet vänner
	void saveOnFile(string filename) const; 
	// läser uppgifter från fil enligt ovan och lägger in i arrayen myFriends
	void readFromFile(string filename); 
};