#include "Dice.h"

const int DEFAULTNROFSIDESONDIE = 6;

Dice::Dice(int nrOfSidesOnDie)
{
	if (nrOfSidesOnDie > 0) //If number of sides is larger then 0 roll a die with that many sides
	{
		this->nrOfSidesOnDie = nrOfSidesOnDie;
	}
	else //Om sides is negative or zero roll default 6 sided die
	{
		this->nrOfSidesOnDie = DEFAULTNROFSIDESONDIE;
	}
	this->toss();
}

void Dice::toss()
{ //Roll die of that many sides
	this->value = ((rand() % this->nrOfSidesOnDie) + 1);
}

int Dice::getCurrentValue() const
{ //Return value
	return this->value;
}

int Dice::getNrOfSidesOnDie() const
{//Return number of sides on dice
	return this->nrOfSidesOnDie;
}

bool Dice::setNrOfSidesOnDie(const int nrOfSidesOnDie)
{
	if (nrOfSidesOnDie > 0)
	{
		this->nrOfSidesOnDie = nrOfSidesOnDie;
		return true;
	}
	return false;
}

Dice::~Dice()
{
}