#include "ProtocolColumn.h"

const int ROWS = 6;

ProtocolColumn::ProtocolColumn(string name)
{
	this->name = name;
	this->resultArray = new int*[ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		this->resultArray[i] = new int[2];
		this->resultArray[i][0] = 0; //Result in that row
		this->resultArray[i][1] = 0; //Have been changed 0 == no 1 == yes
	}
}

bool ProtocolColumn::addResult(const int diceValue, const int result)
{
	if (diceValue > 0 && diceValue < 7)
	{
		if (!this->resultArray[diceValue - 1][1])
		{
			this->resultArray[diceValue - 1][0] = result;
			this->resultArray[diceValue - 1][1] = 1;
			return true;
		}
	}
	return false;
}

string ProtocolColumn::getPlayerName() const
{
	return this->name;
}

int ProtocolColumn::getTotalSum() const
{
	int totalSum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		totalSum += this->resultArray[i][0];
	}
	return totalSum;
}


bool ProtocolColumn::isFilled() const
{
	for (int i = 0; i < ROWS; i++)
	{
		if (!this->resultArray[i][1])
		{
			return false;
		}
	}
	return true;
}

string ProtocolColumn::toString() const
{
	string returnString = this->name;
	for (int i = 0; i < ROWS; i++)
	{
		returnString += "\n";
		returnString += to_string(i + 1);
		returnString += "     :  ";
		returnString += to_string(this->resultArray[i][0]);
	}
	returnString += "\n-------------------";
	returnString += "\nSUM =    ";
	returnString += to_string(this->getTotalSum());
	returnString += "\n";
	return returnString;
}

ProtocolColumn::~ProtocolColumn()
{
	for (int i = 0; i < ROWS; i++)
	{
		delete[] this->resultArray[i];
	}
	delete[] this->resultArray;
}
