#include<iostream>
#include<string>
#include"Friend.h"

using namespace std;

const int CAP = 10;

/*The user inputs name and birthYear in the array
but first the user inputs how manny friends to input*/

void registerFriends(Friend theFriends[], int arrCap, int &nrOf);

int main()
{
	//static alocated Friend array of size CAP 
	Friend myFriends[CAP]; // Creates 10 deafults Friend objects
	int nrOfFriends = 0;

	registerFriends(myFriends, CAP, nrOfFriends)

	return 0;
}

void registerFriends(Friend theFriends[], int arrCap, int & nrOf)
{
	cout << "How many friends do you whant to register: ";
	cin >> nrOf;
	cin.ignore();
}
