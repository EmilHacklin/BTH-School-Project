#pragma once
#include <cstdlib>
#include <ctime>

extern const int DEFAULTNROFSIDESONDIE; //Default number of sides

class Dice
{
private:
	int value; //The value of the dice roll
	int nrOfSidesOnDie; //Number of sides on the die
public:
	Dice(const int nrOfSidesOnDie = DEFAULTNROFSIDESONDIE); //Default number of sides is the default argument for the constructor
	void toss();
	int getCurrentValue() const;
	int getNrOfSidesOnDie() const;
	~Dice();
};