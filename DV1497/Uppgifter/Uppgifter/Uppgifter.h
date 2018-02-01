#pragma once
#include<iostream>
#include<Windows.h>
#include<string>

using namespace std;

void assignmentHeader(int nr);
void enterToContinue();
void clearScreen();
void printStars(int nr);


void assignmentHeader(int nr)
{
	cout << "***Assignment " << nr << "***\n\n";
}

void enterToContinue()
{//Prints a message and continue the program after the user inputs enter
	cout << "\n*** Press \"Enter\" to continue ***";
	cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');
	clearScreen();
}

void clearScreen() //This is not my code
{
	HANDLE hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count, cellCount;
	COORD homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE || !GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		return;
	}

	cellCount = csbi.dwSize.X *csbi.dwSize.Y; //Get the number of cells in the current buffer
	// Fill the entire buffer with spaces
	if (!FillConsoleOutputCharacter(hStdOut, (TCHAR) ' ', cellCount, homeCoords, &count) || 
		!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count))
	{//Fill the entire buffer with the current colours and attributes
		return;
	}

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void printStars(int nr)
{
	string stars = "\n";

	for (int i = 0; i < nr; i++)
	{
		stars = stars + "*";
	}

	cout << stars;
}
