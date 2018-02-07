#pragma once
#include<string>
#include<fstream>
#include<cstdlib>
#include "Friend.h"

using namespace std;

class FriendBook
{
private:
	string title;
	Friend* myFriends; // för dynamisk allokering av array
	int capacity;
	int nrOfFriends;

public:
	FriendBook(string title = "unknown", int capacity = 3);
	bool addFriend(string name, int birthYear); // use  the == operator to avoid multiples
	bool removeFriend(string name, int birthYear); // parameters name, birthdate, ...
	bool existFriend(string name, int birthYear) const; // parameters name, birthdate, ...
	void getFriendsBornByYearAsString(string arr[], int nrOf, int year) const;
	int getNrOfFriends() const;
	string getTitle() const;
	void setTitle(string title);
	void clear();//???
	void getFriendsAsString(string arr[], int nrOf)const;
	void saveOnFile(string filename) const; 
	void readFromFile(string filename); 
	~FriendBook();
};