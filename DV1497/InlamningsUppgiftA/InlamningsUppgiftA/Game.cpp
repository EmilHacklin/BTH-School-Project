#include "Yatzee.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	int nrOfPlayers = 0, winnerSum = 0;

	cout << "How many players whant to play? ";
	cin >> nrOfPlayers; 
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (nrOfPlayers <= 0 )
	{
		cout << "INVALID INPUT: Try again" << endl;
		cout << "How many players whant to play? ";
		cin >> nrOfPlayers;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	Yatzee yatzee(nrOfPlayers); //Skapa ett Yatzee-objekt baserat på nrOfPlayers
	
	for (int i = 0; i < nrOfPlayers; i++) //Låt användaren mata in namnen på spelarna och lägg till spelarna till Yatzee-objektet
	{
		string name = "";
		cout << "Name of player number " << i+1 << ": ";
		getline(cin, name);
		yatzee.addPlayer(name);
	}

	do //Så länge som inte alla spelare har spelat klart
	{
		if (!yatzee.isCurrentPlayerDone())
		{
			int value = 0;
			cout << yatzee.protocolInfoOfCurrentPlayer() << endl; //Presentera protokollet för aktuell spelare
			yatzee.toss(); //Kasta en omgång tärningar
			for (int i = 0; i < 2; i++) //Upprepa 2 gånger
			{
				cout << "You tossed: " << yatzee.infoOfLatestToss() << endl; //Visa tärningarnas utfall
				cout << "Which value do you want to save or 0 to toss them all: "; //Låt användaren mata in vilket tärningsvärde som ska sparas
				cin >> value;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				while (value < 0 || value > 6)
				{
					cout << "INVALID INPUT: Try again" << endl;
					cout << "Which value do you want to save or 0 to toss them all: ";
					cin >> value;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				yatzee.toss(value); //Kasta alla övriga tärningar
			}
			cout << "You tossed: " << yatzee.infoOfLatestToss() << endl; //Visa tärningarnas utfall
			cout << "Which value do you want to save: "; //Låt användaren mata in vilket tärningsvärde som ska sparas
			cin >> value;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			while (!yatzee.addResult(value))
			{
				if (yatzee.isCurrentPlayerValueFull(value)) //Så länge som tärningsvärdet redan är ifyllt	
				{
					cout << "THAT VALUE IS FULL: Try again" << endl;
				}
				else
				{
					cout << "INVALID INPUT: Try again" << endl;
				}
				cout << "Which value do you want to save: "; //Låt användaren mata in vilket tärningsvärde resultatet ska sparas på
				cin >> value;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			cout << yatzee.protocolInfoOfCurrentPlayer() << endl; //Presentera protokollet för aktuell spelare
			yatzee.nextPlayersTurn(); //Nästa spelares tur
			system("pause");
		}
		system("cls");//Rensa skärmen och pausa
	} while (!yatzee.areAllPlayersDone());

	for (int i = 0; i < nrOfPlayers; i++)
	{
		cout << yatzee.protocolInfoOfCurrentPlayer() << endl; //Presentera protokollkolumnen och totalsumman för varje spelare
		if (winnerSum < yatzee.getCurrentPlayerSum()) //Finds out what the winning score was
		{
			winnerSum = yatzee.getCurrentPlayerSum();
		}
		yatzee.nextPlayersTurn();
	}

	for (int i = 0; i < nrOfPlayers; i++) //Prints out who won
	{
		if (winnerSum == yatzee.getCurrentPlayerSum())
		{
			cout << "\n*** The winner is " << yatzee.nameOfCurrentPlayer() << " with " << to_string(winnerSum) << " Points ***\n" << endl;
		}
		yatzee.nextPlayersTurn();
	}
	
	system("pause");
	return 0;
}