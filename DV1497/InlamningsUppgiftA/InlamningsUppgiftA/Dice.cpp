#include "Dice.h"

void Dice::copyDice(const Dice & originalDice)
{
	this->value = originalDice.getCurrentValue();
	this->nrOfSidesOnDie = originalDice.nrOfSidesOnDie;
}

Dice::Dice(int nrOfSidesOnDie)
{
	if (nrOfSidesOnDie > 0) //If number of sides is larger then 0 roll a die with that many sides
	{
		this->value = ((rand() % nrOfSidesOnDie) + 1);
		this->nrOfSidesOnDie = nrOfSidesOnDie;
	}
	else //Om sides is negative or zero roll default 6 sided die
	{
		this->value = ((rand() % DEFAULTNROFSIDESONDIE) + 1);
		this->nrOfSidesOnDie = DEFAULTNROFSIDESONDIE;
	}
}

Dice::Dice(const Dice & originalDice)
{
	this->copyDice(originalDice);
}

Dice & Dice::operator=(const Dice & originalDice)
{
	this->copyDice(originalDice);
	return *this;
}

void Dice::toss()
{ //Roll die of that many sides
	this->value = ((rand() % this->nrOfSidesOnDie) + 1);
}

int Dice::getCurrentValue() const
{ //Return value
	return this->value;
}


Dice::~Dice()
{
}
