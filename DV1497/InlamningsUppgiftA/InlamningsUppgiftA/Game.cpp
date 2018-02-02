#include "Yatzee.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	int nrOfPlayers=0;

	cout << "Hur många ska vara med och spela? ";
	cin >> nrOfPlayers; cin.ignore();

	//Skapa ett Yatzee-objekt baserat på nrOfPlayers
	
	//Låt användaren mata in namnen på spelarna och lägg till spelarna till Yatzee-objektet
	
	//Så länge som inte alla spelare har spelat klart
	
		//Presentera protokollet för aktuell spelare
		
		//Kasta en omgång tärningar
		
		//Upprepa 2 gånger

			//Visa tärningarnas utfall
			
			//Låt användaren mata in vilket tärningsvärde som ska sparas
			
			//Kasta alla övriga tärningar
		
		//Visa tärningarnas utfall
		
		//Låt användaren mata in vilket tärningsvärde resultatet ska sparas på
	
		//Så länge som tärningsvärdet redan är ifyllt	
	
			//Låt användaren mata in vilket tärningsvärde resultatet ska sparas på
		
		//Presentera protokollkolumnen för aktuell spelare	
		
		//Nästa spelares tur

		//Rensa skärmen och pausa
	
	//Presentera protokollkolumnen och totalsumman för varje spelare
	
	system("pause");
	return 0;
}