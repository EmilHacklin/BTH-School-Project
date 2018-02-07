#include <iostream>
#include <string>
#include "Friend.h"

using namespace std;

int main()
{
	{
		Friend bestFriend("Rune", 1933); // anrop av konstruktor genomförs
		Friend oldestFriend("Kaj Olle", 1925); // ...

		cout << "Best friends name is " << bestFriend.getName() << endl;
		cout << "Oldest friends name is " << oldestFriend.getName() << endl;

		// användaren ska mata in uppgifter för bästa vännen
		// jämför denna med den redan befintliga

		string aName;
		int aBirthYear;
		cout << " Do you remeber your best friend? " << endl;

		cout << "Input name: ";
		getline(cin, aName);
		cout << "Input birth year: ";
		cin >> aBirthYear;
		cin.ignore();

		Friend tempFriend(aName, aBirthYear);

		if (tempFriend == bestFriend)
		{
			cout << "YES!!!" << endl;
		}
		else
		{
			cout << "NO!!!" << endl;
		}

	}
	


	/*if (tempFriend.operator==(bestFriend))
	{

	}*/


	/*cout << "Input a new name: ";
	string aName;
	getline(cin, aName);

	bestFriend.setName(aName);
	oldestFriend.setBirthYear(1923);

	cout << "Best friends name is " << bestFriend.getName() << endl;
	cout << "Oldest friends name is " << oldestFriend.getName() << endl;

	cout << oldestFriend.toString() << endl;*/

	getchar();
	return 0;
}