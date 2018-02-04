#pragma once
#include <cstdlib>
#include <ctime>

const int DEFAULTNROFSIDESONDIE = 6; //Default number of sides

class Dice
{
private:
	int value; //The value of the dice roll
	int nrOfSidesOnDie; //Number of sides on the die
	//void copyDice(const Dice &originalDice);
public:
	Dice(const int nrOfSidesOnDie = DEFAULTNROFSIDESONDIE); //Default number of sides is the default argument for the constructor
	//Dice(const Dice &originalDice);
	//Dice& operator=(const Dice &originalDice);
	void toss();
	int getCurrentValue() const;
	int getNrOfSidesOnDie() const;
	~Dice();
};

