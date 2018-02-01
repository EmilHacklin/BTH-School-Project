#include "Dice.h"
#include <iostream>

using namespace std;
void exercise1();
void exercise2();
void exercise3();
void exercise4();
void exercise5();
void exercise6();
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	cout << "Exercise1" << endl;
	exercise1();
	getchar();
	cout << "\nExercise2" << endl;
	exercise2();
	getchar();
	cout << "\nExercise3" << endl;
	exercise3();
	getchar();
	cout << "\nExercise4" << endl;
	exercise4();
	getchar();
	cout << "\nExercise5" << endl;
	exercise5();
	getchar();
	cout << "\nExercise6" << endl;
	exercise6();
	getchar();

	return 0;
}

void exercise1()
{
	Dice *dice1 = new Dice[6];
	Dice *dice2 = new Dice[6];

	for (unsigned short i = 1; i < 6; i++)
	{
		dice1->toss();
		dice2->toss();
		cout << "Roll number " << i << ": "<< dice1->getValue() << "   " << dice2->getValue() << endl;
	}
	
	delete[] dice1;
	delete[] dice2;
	// skapa två dynamiskt allokerade Dice-objekt (tärningar)
	// vilka representera 6-sidiga tärningar
	// som kan nås via två olika pekarvariabler

	// kasta de båda tärningarna 5 gånger och 
	// presentera tärningarnas värde
	
	// tillse att det inte blir några minnesläckor
}

void exercise2()
{
	Dice* *dice = new Dice*[4];
	for (unsigned short i = 0; i < 4; i++)
	{
		dice[i] = new Dice[6];
	}
	cout << "The toss gave: ";
	for (unsigned short i = 0; i < 4; i++)
	{
		cout << dice[i]->getValue() << "   ";
		delete[] dice[i];
	}

	delete[] dice;
	// Skapa en dynamiskt allokerad array 
	// med 4 st Dice-objekt som representerar 
	// 6-sidiga tärningar

	// kasta alla täningarna en gång och 
	// presentera tärningarnas värde

	// tillse att det inte blir några minnesläckor
}

void exercise3()
{
	Dice* *dice = new Dice*[4];
	for (unsigned short i = 0; i < 4; i++)
	{
		dice[i] = nullptr;
	}
	for (unsigned short i = 0; i < 4; i++)
	{
		if (i < 2)
		{
			dice[i] = new Dice[8];
		}
		else
		{
			dice[i] = new Dice[4];
		}
	}
	cout << "The toss gave: ";
	for (unsigned short i = 0; i < 4; i++)
	{
		dice[i]->toss();
		cout << dice[i]->getValue() << "   ";
		delete[] dice[i];
	}
	delete[] dice;
	// skapa en statiskt allokerad array med kapaciteten 4
	// innehållande Dice pekare (pekare till tärningar)
	// Tillse att alla pekare i denna array är nullptr

	// skapa (genom dynamisk minnesallokering) 2 Dice-objekt
	// som representerar 8-sidiga tärningar
	// och "placera dessa på" de två första positionerna i arrayen

	// skapa ytterligare 2 Dice-objekt (genom dynamick minnesallokering)
	// vilka representerar 4-sidiga tärningar och 
	// "placera dessa på" de två sista positionerna i arrayen

	// kasta alla täningarna en gång och 
	// presentera tärningarnas värde

	// tillse att det inte blir några minnesläckor
}

void exercise4()
{
	Dice* *dice = new Dice*[6];
	for (unsigned short i = 0; i < 6; i++)
	{
		dice[i] = nullptr;
	}
	for (unsigned short i = 0; i < 6; i++)
	{
		dice[i] = new Dice[17];
	}
	cout << "The toss gave: ";
	for (unsigned short i = 0; i < 6; i++)
	{
		dice[i]->toss();
		cout << dice[i]->getValue() << "   ";
		delete[] dice[i];
	}
	delete[] dice;
	// skapa en dynamsikt allokerad array av storlek 6
	// innehållande Dice-pekare 
	// tillse att alla pekare blir nullptr

	// skapa för alla pekarna genom dynamisk minnesallokering
	// Dice-objekt vilka representerar 17-sidiga tärningar

	// kasta alla täningarna en gång och 
	// presentera tärningarnas värde

	// tillse att det inte blir några minnesläckor
}

void exercise5()
{
	Dice* dice[10];
	unsigned short targetValue = 0, targetResult = 0;
	for (unsigned short i = 0; i < 10; i++)
	{
		dice[i] = nullptr;
	}
	for (unsigned short i = 0; i < 10; i++)
	{
		dice[i] = new Dice[6];
	}
	cout << "Enter a target value (1-6): ";
	cin >> targetValue;
	cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');
	for (unsigned short i = 0; i < 10; i++)
	{
		dice[i]->toss();
		if (dice[i]->getValue() == targetValue)
		{
			targetResult++;
		}
		delete[] dice[i];
	}
	cout << targetResult << " dice has the target value";
	// skapa en statiskt allokerad array med kapaciteten 10
	// innehållande Dice pekare (pekare till tärningar)
	// Tillse att alla pekare i denna array är nullptr

	// skapa för alla pekarna genom dynamisk minnesallokering
	// Dice-objekt vilka representerar 6-sidiga tärningar

	// kasta alla tärningarna 1 gång

	// låt användaren mata in ett målvärde, dvs ett värde inom [1..6]

	// bestäm hur många av tärningarna som hade det värde som användaren
	// matat in 

	// skriv ut resultatet, dvs antalet tärningar som var samma som 
	// användarens inmatade värde
}

void exercise6()
{
	Dice* *dice = new Dice*[5];
	unsigned short extraDice = 0;
	for (unsigned short i = 0; i < 5; i++)
	{
		dice[i] = new Dice[7];
	}
	cout << "How many extra dice do you want?: ";
	cin >> extraDice;
	cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');
	Dice* *tempDice = new Dice*[(extraDice + 5)];
	for (unsigned short i = 0; i < extraDice + 5; i++)
	{
		if (i < 5)
		{
			tempDice[i] = dice[i];
		}
		else
		{
			tempDice[i] = new Dice[7];
		}
	}
	delete[] dice;
	dice = tempDice;
	cout << "The toss gave: ";
	for (unsigned short i = 0; i < extraDice + 5; i++)
	{
		dice[i]->toss();
		cout << dice[i]->getValue() << "   ";
		delete[] dice[i];
	}
	delete[] dice;
	// ska en dynamsikt allokerad array av storlek 5
	// innehållande Dice-pekare

	// skapa för alla pekarna genom dynamisk minnesallokering
	// Dice-objekt vilka representerar 7-sidiga tärningar

	// låt användaren mata in hur många ytterligare tärningar
	// som ska skapa

	// expandera arrayen med detta antal

	// skapa 7 sidiga Dice-objekt för de "extra" Dice-pekarna 
	
	// kasta alla tärningar och presentera tärningarnas värdena

	// tillse att det inte blir några minnesläckor
}
