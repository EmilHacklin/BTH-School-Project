#include "Yatzee.h"

void Yatzee::copyYatzee(const Yatzee & originalYatzee)
{
	this->capacityForPlayers = originalYatzee.capacityForPlayers;
	this->players = new ProtocolColumn*[this->capacityForPlayers]; //Allocate array of ProtocolColumn pointer with space == to capacity for players
	for (int i = 0; i < originalYatzee.getNrOfPlayers(); i++) //For each element in players
	{
		this->players[i] = originalYatzee.players[i]; //Players element get a copyYatzee of players element from originalYatzee
	}
	this->numberOfPlayers = originalYatzee.getNrOfPlayers();
	this->indexCurrentPlayer = originalYatzee.indexCurrentPlayer;
	this->numberOfDice = originalYatzee.numberOfDice;
	this->numberOfSidesOnDie = originalYatzee.numberOfSidesOnDie;
	this->dice = new Dice*[this->numberOfDice];
	for (int i = 0; i < this->numberOfDice; i++) //For each element in dice
	{
		this->dice[i] = originalYatzee.dice[i]; //Create a new Dice object
	}
}

void Yatzee::deallocate()
{
	for (int i = 0; i < this->numberOfPlayers; i++) //For each element in the array
	{
		delete this->players[i]; //Delete the elements array
	}
	this->numberOfPlayers = 0;
	this->indexCurrentPlayer = 0;
	delete[] this->players; //Delete the array itself
	this->capacityForPlayers = 0;
	for (int i = 0; i < this->numberOfDice; i++) //For each element in the array
	{
		delete this->dice[i]; //Delete the elements array
	}
	this->numberOfDice = 0;
	delete[] this->dice; //Delete the array itself
}

void Yatzee::expandPlayers()
{
	this->capacityForPlayers += DEFAULTCAPACITYFORPLAYERS;
	ProtocolColumn* *tempPlayers = new ProtocolColumn*[this->capacityForPlayers];
	for (int i = 0; i < this->numberOfPlayers; i++)
	{
		tempPlayers[i] = this->players[i];
	}
	delete[] this->players;
	this->players = tempPlayers;
}

Yatzee::Yatzee(const int capacityForPlayers, const int numberOfDice, const int numberOfSidesOnDie)
{
	this->capacityForPlayers = capacityForPlayers;
	this->players = new ProtocolColumn*[this->capacityForPlayers]; //Allocate array of ProtocolColumn pointer with space == to capacity for players
	this->numberOfPlayers = 0;
	this->indexCurrentPlayer = 0;
	this->numberOfDice = numberOfDice;
	this->numberOfSidesOnDie = numberOfSidesOnDie;
	this->dice = new Dice*[this->numberOfDice];
	for (int i = 0; i < this->numberOfDice; i++) //For each element in dice
	{
		this->dice[i] = new Dice(this->numberOfSidesOnDie); //Create a new Dice object
	}
}

Yatzee::Yatzee(const Yatzee & originalYatzee)
{
	this->copyYatzee(originalYatzee); //Calling the member function copyYatzee
}

Yatzee & Yatzee::operator=(const Yatzee & originalYatzee)
{
	this->deallocate(); //Calling member function deallocate
	this->copyYatzee(originalYatzee); //Calling the member function copyYatzee
	return *this; //Returns reference to  this
}

void Yatzee::addPlayer(const string playerName)
{
	if (this->numberOfPlayers == this->capacityForPlayers) //If the players array is full  
	{
		this->expandPlayers(); //Calls the member function expand
	}
	this->players[this->numberOfPlayers] = new ProtocolColumn(playerName, this->numberOfSidesOnDie); //Creates a new ProtocolColumn and assignees it to players array
	this->numberOfPlayers++;
}

string Yatzee::protocolInfoOfCurrentPlayer() const
{
	return this->players[this->indexCurrentPlayer]->toString(); //Return toString() of current player
}

int Yatzee::getNrOfPlayers() const
{
	return this->numberOfPlayers;
}

void Yatzee::toss()
{
	for (int i = 0; i < this->numberOfDice; i++) //For each element of dice
	{
		this->dice[i]->toss(); //Toss dice
	}
}

void Yatzee::toss(const int diceValue)
{
	for (int i = 0; i < this->numberOfDice; i++) //For each element of dice
	{
		if (this->dice[i]->getCurrentValue() != diceValue) //If the value of the die is not diceValue
		{
			this->dice[i]->toss(); //Toss dice
		}
	}
}

string Yatzee::infoOfLatestToss() const
{
	string returnString = "";
	for (int i = 0; i < this->numberOfDice; i++) //For each element of dice
	{
		returnString += to_string(this->dice[i]->getCurrentValue()); //Add a string of the value of the die
		returnString += "   ";
	}
	returnString += "\n";
	return returnString; //Return the formated string
}

bool Yatzee::addResult(const int diceValue)
{
	if (!this->players[this->indexCurrentPlayer]->isFilled()) //If the current player´s protocol is not full
	{
		if (diceValue > 0 && diceValue <= this->numberOfSidesOnDie) //If diceValue is a valid number
		{
			int result = 0;
			for (int i = 0; i < this->numberOfDice; i++) //For each element of dice
			{
				if (this->dice[i]->getCurrentValue() == diceValue) ////If the value of the die is diceValue
				{
					result += this->dice[i]->getCurrentValue(); //Increment result
				}
			}
			return this->players[this->indexCurrentPlayer]->addResult(diceValue, result); //Try adding result to diceValue in the current player protocol
		}
	}
	return false;
}

string Yatzee::nameOfCurrentPlayer() const
{
	return this->players[this->indexCurrentPlayer]->getPlayerName(); //Return player name
}

void Yatzee::nextPlayersTurn()
{
	if (this->indexCurrentPlayer != (this->numberOfPlayers - 1)) //If not all players have gone this round
	{
		this->indexCurrentPlayer++; //Next player´s turn
	}
	else //All players have gone this round
	{
		this->indexCurrentPlayer = 0; //Reset index current player to the beginning
	}
}

bool Yatzee::areAllPlayersDone() const
{
	for (int i = 0; i < this->numberOfPlayers; i++) //For each element in players
	{
		if (!this->players[i]->isFilled()) //If players protocol is not full
		{
			return false;
		}
	}
	return true;
}

Yatzee::~Yatzee()
{
	this->deallocate(); //Calling deallocate member function
}
