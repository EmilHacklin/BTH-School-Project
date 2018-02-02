#include "Dice.h"

Dice::Dice(int sides)
{
	if (sides > 0) //If sides is larger then 0 roll a die with that many sides
	{
		this->value = ((rand() % sides) + 1);
		this->sides = sides;
	}
	else //Om sides is negative or zero roll default 6 sided die
	{
		this->value = ((rand() % 6) + 1);
	}
}

void Dice::toss()
{//Roll die of that many sides
	this->value = ((rand() % this->sides) + 1);
}

int Dice::getCurrentValue() const
{//Return value
	return this->value;
}


Dice::~Dice()
{
}
