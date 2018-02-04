#include "Yatzee.h"

void Yatzee::copyYatzee(const Yatzee & originalYatzee)
{
	this->capacityForPlayers = originalYatzee.getCapacityForPlayers();
	this->players = new ProtocolColumn*[this->capacityForPlayers]; //Allocate array of ProtocolColumn pointer with space == to capacity for players
	this->nrOfPlayers = originalYatzee.getNrOfPlayers();
	for (int i = 0; i < this->nrOfPlayers; i++) //For each element in players
	{
		this->players[i] = new ProtocolColumn(*originalYatzee.players[i]); //Players element get a copyYatzee of players element from originalYatzee
	}
	this->indexCurrentPlayer = originalYatzee.getIndexCurrentPlayer();
	if (this->nrOfDice != originalYatzee.getNrOfDice()) //If number of dice is not the same as in the original
	{
		delete[] this->dice;
		this->nrOfDice = originalYatzee.getNrOfDice();
		this->dice = new Dice[this->nrOfDice];
	}
	for (int i = 0; i < this->nrOfDice; i++) //For each element in dice
	{
		this->dice[i] = originalYatzee.dice[i]; //Create a new Dice object
	}
	this->nrOfSidesOnDie = this->dice[0].getNrOfSidesOnDie();
}

void Yatzee::deallocatePlayers()
{
	for (int i = 0; i < this->nrOfPlayers; i++) //For each element in the array
	{
		delete this->players[i]; //Delete the elements array
	}
	this->nrOfPlayers = 0;
	this->indexCurrentPlayer = 0;
	delete[] this->players; //Delete the array itself
	this->capacityForPlayers = 0;
}

void Yatzee::expandPlayers()
{
	this->capacityForPlayers += DEFAULTCAPACITYFORPLAYERS;
	ProtocolColumn* *tempPlayers = new ProtocolColumn*[this->capacityForPlayers];
	for (int i = 0; i < this->nrOfPlayers; i++)
	{
		tempPlayers[i] = this->players[i];
	}
	delete[] this->players;
	this->players = tempPlayers;
}

Yatzee::Yatzee(const int capacityForPlayers, const int nrOfDice, const int nrOfSidesOnDie)
{
	this->capacityForPlayers = capacityForPlayers;
	this->players = new ProtocolColumn*[this->capacityForPlayers]; //Allocate array of ProtocolColumn pointer with space == to capacity for players
	this->nrOfPlayers = 0;
	this->indexCurrentPlayer = 0;
	this->nrOfDice = nrOfDice;
	this->nrOfSidesOnDie = nrOfSidesOnDie;
	this->dice = new Dice[this->nrOfDice];
}

Yatzee::Yatzee(const Yatzee & originalYatzee)
{
	this->nrOfDice = originalYatzee.getNrOfDice();
	this->nrOfDice = originalYatzee.getNrOfDice();
	this->dice = new Dice[this->nrOfDice];
	this->copyYatzee(originalYatzee); //Calling the member function copyYatzee
}

Yatzee & Yatzee::operator=(const Yatzee & originalYatzee)
{
	this->deallocatePlayers(); //Calling member function deallocatePlayers
	this->copyYatzee(originalYatzee); //Calling the member function copyYatzee
	return *this; //Returns reference to this
}

void Yatzee::addPlayer(const string playerName)
{
	if (this->nrOfPlayers == this->capacityForPlayers) //If the players array is full  
	{
		this->expandPlayers(); //Calls the member function expand
	}
	this->players[this->nrOfPlayers] = new ProtocolColumn(playerName, this->nrOfSidesOnDie); //Creates a new ProtocolColumn and assignees it to players array
	this->nrOfPlayers++;
}

string Yatzee::protocolInfoOfCurrentPlayer() const
{
	return this->players[this->indexCurrentPlayer]->toString(); //Return toString() of current player
}

int Yatzee::getCurrentPlayerSum() const
{
	return this->players[this->indexCurrentPlayer]->getTotalSum();
}

int Yatzee::getCapacityForPlayers() const
{
	return this->capacityForPlayers;
}

int Yatzee::getNrOfPlayers() const
{
	return this->nrOfPlayers;
}

int Yatzee::getIndexCurrentPlayer() const
{
	return this->indexCurrentPlayer;
}

int Yatzee::getNrOfDice() const
{
	return this->nrOfDice;
}

void Yatzee::toss()
{
	for (int i = 0; i < this->nrOfDice; i++) //For each element of dice
	{
		this->dice[i].toss(); //Toss dice
	}
}

void Yatzee::toss(const int diceValue)
{
	for (int i = 0; i < this->nrOfDice; i++) //For each element of dice
	{
		if (this->dice[i].getCurrentValue() != diceValue) //If the value of the die is not diceValue
		{
			this->dice[i].toss(); //Toss dice
		}
	}
}

string Yatzee::infoOfLatestToss() const
{
	string returnString = "";
	for (int i = 0; i < this->nrOfDice; i++) //For each element of dice
	{
		returnString += to_string(this->dice[i].getCurrentValue()); //Add a string of the value of the die
		returnString += "   ";
	}
	returnString += "\n";
	return returnString; //Return the formated string
}

bool Yatzee::addResult(const int diceValue)
{
	if (!this->players[this->indexCurrentPlayer]->isFilled()) //If the current player´s protocol is not full
	{
		if (diceValue > 0 && diceValue <= this->nrOfSidesOnDie) //If diceValue is a valid number
		{
			int result = 0;
			for (int i = 0; i < this->nrOfDice; i++) //For each element of dice
			{
				if (this->dice[i].getCurrentValue() == diceValue) ////If the value of the die is diceValue
				{
					result += this->dice[i].getCurrentValue(); //Increment result
				}
			}
			return this->players[this->indexCurrentPlayer]->addResult(diceValue, result); //Try adding result to diceValue in the current player protocol
		}
	}
	return false;
}

bool Yatzee::isCurrentPlayerValueFull(int value) const
{
	return this->players[this->indexCurrentPlayer]->isFilled(value);
}

string Yatzee::nameOfCurrentPlayer() const
{
	return this->players[this->indexCurrentPlayer]->getPlayerName(); //Return player name
}

void Yatzee::nextPlayersTurn()
{
	if (this->indexCurrentPlayer != (this->nrOfPlayers - 1)) //If not all players have gone this round
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
	for (int i = 0; i < this->nrOfPlayers; i++) //For each element in players
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
	this->deallocatePlayers(); //Calling deallocatePlayers member function
	delete[] this->dice; //Delete the array dice
	this->nrOfDice = 0;
}
