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
	// skapa tv� dynamiskt allokerade Dice-objekt (t�rningar)
	// vilka representera 6-sidiga t�rningar
	// som kan n�s via tv� olika pekarvariabler

	// kasta de b�da t�rningarna 5 g�nger och 
	// presentera t�rningarnas v�rde
	
	// tillse att det inte blir n�gra minnesl�ckor
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
	// 6-sidiga t�rningar

	// kasta alla t�ningarna en g�ng och 
	// presentera t�rningarnas v�rde

	// tillse att det inte blir n�gra minnesl�ckor
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
	// inneh�llande Dice pekare (pekare till t�rningar)
	// Tillse att alla pekare i denna array �r nullptr

	// skapa (genom dynamisk minnesallokering) 2 Dice-objekt
	// som representerar 8-sidiga t�rningar
	// och "placera dessa p�" de tv� f�rsta positionerna i arrayen

	// skapa ytterligare 2 Dice-objekt (genom dynamick minnesallokering)
	// vilka representerar 4-sidiga t�rningar och 
	// "placera dessa p�" de tv� sista positionerna i arrayen

	// kasta alla t�ningarna en g�ng och 
	// presentera t�rningarnas v�rde

	// tillse att det inte blir n�gra minnesl�ckor
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
	// inneh�llande Dice-pekare 
	// tillse att alla pekare blir nullptr

	// skapa f�r alla pekarna genom dynamisk minnesallokering
	// Dice-objekt vilka representerar 17-sidiga t�rningar

	// kasta alla t�ningarna en g�ng och 
	// presentera t�rningarnas v�rde

	// tillse att det inte blir n�gra minnesl�ckor
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
	// inneh�llande Dice pekare (pekare till t�rningar)
	// Tillse att alla pekare i denna array �r nullptr

	// skapa f�r alla pekarna genom dynamisk minnesallokering
	// Dice-objekt vilka representerar 6-sidiga t�rningar

	// kasta alla t�rningarna 1 g�ng

	// l�t anv�ndaren mata in ett m�lv�rde, dvs ett v�rde inom [1..6]

	// best�m hur m�nga av t�rningarna som hade det v�rde som anv�ndaren
	// matat in 

	// skriv ut resultatet, dvs antalet t�rningar som var samma som 
	// anv�ndarens inmatade v�rde
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
	// inneh�llande Dice-pekare

	// skapa f�r alla pekarna genom dynamisk minnesallokering
	// Dice-objekt vilka representerar 7-sidiga t�rningar

	// l�t anv�ndaren mata in hur m�nga ytterligare t�rningar
	// som ska skapa

	// expandera arrayen med detta antal

	// skapa 7 sidiga Dice-objekt f�r de "extra" Dice-pekarna 
	
	// kasta alla t�rningar och presentera t�rningarnas v�rdena

	// tillse att det inte blir n�gra minnesl�ckor
}
