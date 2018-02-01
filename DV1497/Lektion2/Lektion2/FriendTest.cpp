#include<iostream>
#include<string>
#include"Friend.h"

using namespace std;

int main()
{
	Friend bestFriend("Rune", 1933); //Caling the Friend constructor
	Friend oldestFriend("Kaj Olle", 1925); // ...
	string newName;
	int newBirthYear;

	cout << bestFriend.toString() << endl;
	cout << oldestFriend.toString() << endl;

	cout << "Input new name for " << bestFriend.getName() << ": ";
	getline(cin, newName);
	bestFriend.setName(newName);
	cout << bestFriend.toString() << endl;

	cout << "Input new birthyear for " << oldestFriend.getName() << ": ";
	cin >> newBirthYear;
	cin.ignore();
	oldestFriend.setBirthYear(newBirthYear);
	cout << oldestFriend.toString() << endl;

	getchar();
	return 0;
}