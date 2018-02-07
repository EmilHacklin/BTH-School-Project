#include "FriendBook.h"
#include <iostream>

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	FriendBook testBook("test book"); // kapaciten blir 3
	FriendBook loadTest;
	string* friends;
	int nrOf;

	cout << "nr of friends from " << testBook.getTitle() << " is: " << testBook.getNrOfFriends() << endl;
	getchar();

	
	testBook.addFriend("1", 1910);
	nrOf = testBook.getNrOfFriends();
	friends = new string[nrOf];
	testBook.getFriendsAsString(friends, nrOf);
	for (unsigned short i = 0; i < nrOf; i++)
	{
		cout << friends[i] << endl;
	}
	delete[] friends;
	getchar();

	testBook.setTitle("Test Book");
	cout << "nr of friends from " << testBook.getTitle() << " is: " << testBook.getNrOfFriends() << endl;
	getchar();


	testBook.addFriend("2", 1920);
	testBook.addFriend("3", 1930);
	testBook.addFriend("4", 1940);
	nrOf = testBook.getNrOfFriends();
	friends = new string[nrOf];
	testBook.getFriendsAsString(friends, nrOf);
	for (unsigned short i = 0; i < nrOf; i++)
	{
		cout << friends[i] << endl;
	}
	delete[] friends;
	getchar();

	if (testBook.existFriend("2", 1920))
	{
		cout << "2 born in 1920 exist" << endl;
	}
	else
	{
		cout << "2 born in 1920 do not exist" << endl;
	}
	getchar();

	testBook.removeFriend("2", 1920);
	nrOf = testBook.getNrOfFriends();
	friends = new string[nrOf];
	testBook.getFriendsAsString(friends, nrOf);
	for (unsigned short i = 0; i < nrOf; i++)
	{
		cout << friends[i] << endl;
	}
	delete[] friends;
	getchar();

	if (testBook.existFriend("2", 1920))
	{
		cout << "2 born in 1920 exist" << endl;
	}
	else
	{
		cout << "2 born in 1920 do not exist" << endl;
	}
	getchar();

	nrOf = testBook.getNrOfFriends();
	friends = new string[nrOf];
	testBook.getFriendsBornByYearAsString(friends, nrOf, 1920);
	for (unsigned short i = 0; i < nrOf; i++)
	{
		cout << friends[i] << endl;
	}
	delete[] friends;
	getchar();

	testBook.saveOnFile("testBook.txt");
	loadTest.readFromFile("testBook.txt");
	nrOf = testBook.getNrOfFriends();
	friends = new string[nrOf];
	loadTest.getFriendsAsString(friends, nrOf);
	for (unsigned short i = 0; i < nrOf; i++)
	{
		cout << friends[i] << endl;
	}
	delete[] friends;
	getchar();

	testBook.clear();
	nrOf = testBook.getNrOfFriends();
	friends = new string[nrOf];
	loadTest.getFriendsAsString(friends, nrOf);
	for (unsigned short i = 0; i < nrOf; i++)
	{
		cout << friends[i] << endl;
	}
	delete[] friends;
	getchar();
	return 0;
}