#include "ProtocolColumn.h"

void ProtocolColumn::copyProtocolColumn(const ProtocolColumn & originalProtocolColumn)
{
	this->playerName = originalProtocolColumn.getPlayerName();
	this->nrOfRows = originalProtocolColumn.getNrOfRows(); //This number of rows is set to the same as originalProtocolColumns
	this->resultArray = new int*[this->nrOfRows];
	for (int i = 0; i < this->nrOfRows; i++) //While i is less than number of rows
	{
		this->resultArray[i] = new int[2]; //Every item in result array is allocated a array of 2 int values
		this->resultArray[i][0] = originalProtocolColumn.resultArray[i][0]; //Result in that row is given the same value as in originalProtocolColumn
		this->resultArray[i][1] = originalProtocolColumn.resultArray[i][1]; //Have been changed 0 == no 1 == yes is given the same state as in originalProtocolColumn
	}
}

void ProtocolColumn::deallocateRows()
{
	for (int i = 0; i < this->nrOfRows; i++) //For each element in the array
	{
		delete[] this->resultArray[i]; //Delete the elements array
	}
	this->nrOfRows = 0;
	delete[] this->resultArray; //Delete the array itself
}

ProtocolColumn::ProtocolColumn(string playerName, int nrOfRows)
{
	this->playerName = playerName;
	if (nrOfRows > 0) //If number of rows is a valid
	{
		this->nrOfRows = nrOfRows;
	}
	else // If number of rows is invalid (0 or negative) 
	{
		this->nrOfRows = DEFAULTNROFROWS; //Number of rows is set at default
	}
	this->resultArray = new int*[this->nrOfRows]; //Result array is allocated a array of int* with size of number of rows
	for (int i = 0; i < this->nrOfRows; i++) //While i is less than number of rows
	{
		this->resultArray[i] = new int[2]; //Every item in result array is allocated a array of 2 int values
		this->resultArray[i][0] = 0; //Result in that row
		this->resultArray[i][1] = false; //Have been changed 0 == no 1 == yes
	}
}

ProtocolColumn::ProtocolColumn(const ProtocolColumn & originalProtocolColumn)
{
	this->copyProtocolColumn(originalProtocolColumn); //Calling the member function copyProtocolColumn
}

ProtocolColumn & ProtocolColumn::operator=(const ProtocolColumn & originalProtocolColumn)
{
	this->deallocateRows(); //Calling member function deallocateRows
	this->copyProtocolColumn(originalProtocolColumn); //Calling the member function copyProtocolColumn
	return *this; //Returns reference to  this
}

bool ProtocolColumn::addResult(const int diceValue, const int result)
{
	if (diceValue > 0 && diceValue <= this->nrOfRows) //If diceValue is a valid number
	{
		if (!this->resultArray[diceValue - 1][1]) //If the number has not been changed
		{
			this->resultArray[diceValue - 1][0] = result; //Change the value to result
			this->resultArray[diceValue - 1][1] = true; //Set change marker to true
			return true;
		}
	}
	return false;
}

string ProtocolColumn::getPlayerName() const
{
	return this->playerName; //Returns playerName variable
}

int ProtocolColumn::getNrOfRows() const
{
	return this->nrOfRows; //Returns number of rows
}

int ProtocolColumn::getTotalSum() const
{
	int totalSum = 0;
	for (int i = 0; i < this->nrOfRows; i++) //For each element in the array
	{
		totalSum += this->resultArray[i][0]; //Add value to totalSum
	}
	return totalSum; //Return totalSum
}

bool ProtocolColumn::isFilled() const
{
	for (int i = 0; i < this->nrOfRows; i++) //For each element in the array
	{
		if (!this->resultArray[i][1]) //If not the value has bean changed 
		{
			return false;
		}
	}
	return true;
}

bool ProtocolColumn::isFilled(const int value) const
{
	return this->resultArray[value][1];
}

string ProtocolColumn::toString() const
{
	string returnString = "\n"; //ReturnString will hold the final string
	returnString += this->playerName;
	for (int i = 0; i < this->nrOfRows; i++) //For each element in the array
	{
		returnString += "\n";
		returnString += to_string(i + 1); //The face value on the dice
		returnString += "     :  ";
		returnString += to_string(this->resultArray[i][0]); //The result
	}
	returnString += "\n-------------------";
	returnString += "\nSUM =    ";
	returnString += to_string(this->getTotalSum()); //Calling getTotalSum and add it as a string
	returnString += "\n";
	return returnString; //Return the formated string
}

ProtocolColumn::~ProtocolColumn()
{
	this->deallocateRows(); //Calling deallocateRows member function
}