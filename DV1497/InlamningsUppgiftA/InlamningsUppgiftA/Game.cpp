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

	Yatzee yatzee(nrOfPlayers); //Skapa ett Yatzee-objekt baserat p� nrOfPlayers
	
	for (int i = 0; i < nrOfPlayers; i++) //L�t anv�ndaren mata in namnen p� spelarna och l�gg till spelarna till Yatzee-objektet
	{
		string name = "";
		cout << "Name of player number " << i+1 << ": ";
		getline(cin, name);
		yatzee.addPlayer(name);
	}

	do //S� l�nge som inte alla spelare har spelat klart
	{
		if (!yatzee.isCurrentPlayerDone())
		{
			int value = 0;
			cout << yatzee.protocolInfoOfCurrentPlayer() << endl; //Presentera protokollet f�r aktuell spelare
			yatzee.toss(); //Kasta en omg�ng t�rningar
			for (int i = 0; i < 2; i++) //Upprepa 2 g�nger
			{
				cout << "You tossed: " << yatzee.infoOfLatestToss() << endl; //Visa t�rningarnas utfall
				cout << "Which value do you want to save or 0 to toss them all: "; //L�t anv�ndaren mata in vilket t�rningsv�rde som ska sparas
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
				yatzee.toss(value); //Kasta alla �vriga t�rningar
			}
			cout << "You tossed: " << yatzee.infoOfLatestToss() << endl; //Visa t�rningarnas utfall
			cout << "Which value do you want to save: "; //L�t anv�ndaren mata in vilket t�rningsv�rde som ska sparas
			cin >> value;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			while (!yatzee.addResult(value))
			{
				if (yatzee.isCurrentPlayerValueFull(value)) //S� l�nge som t�rningsv�rdet redan �r ifyllt	
				{
					cout << "THAT VALUE IS FULL: Try again" << endl;
				}
				else
				{
					cout << "INVALID INPUT: Try again" << endl;
				}
				cout << "Which value do you want to save: "; //L�t anv�ndaren mata in vilket t�rningsv�rde resultatet ska sparas p�
				cin >> value;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			cout << yatzee.protocolInfoOfCurrentPlayer() << endl; //Presentera protokollet f�r aktuell spelare
			yatzee.nextPlayersTurn(); //N�sta spelares tur
			system("pause");
		}
		system("cls");//Rensa sk�rmen och pausa
	} while (!yatzee.areAllPlayersDone());

	for (int i = 0; i < nrOfPlayers; i++)
	{
		cout << yatzee.protocolInfoOfCurrentPlayer() << endl; //Presentera protokollkolumnen och totalsumman f�r varje spelare
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