#pragma once
#include<string>
#include"ProtocolColumn.h"
#include"Dice.h"

using namespace std;

const int DEFAULTCAPACITYFORPLAYERS = 3;
const int DEFAULTNUMBEROFDICE = 5;
const int DEFAULTNUMBEROFSIDESONDIE = 6;

class Yatzee
{
private:
	ProtocolColumn * *players;
	int capacityForPlayers;
	int numberOfPlayers;
	int indexCurrentPlayer;
	Dice* *dice;
	int numberOfDice;
	int numberOfSidesOnDie;
	int numberOfReRolls;
	void copyYatzee(const Yatzee &originalYatzee); //Copes Yatzee
	void deallocate(); //Deallocate Yatzee
	void expandPlayers();
public:
	Yatzee(const int capacityForPlayers = DEFAULTCAPACITYFORPLAYERS, const int numberOfDice = DEFAULTNUMBEROFDICE, const int numberOfSidesOnDie = DEFAULTNUMBEROFSIDESONDIE);
	Yatzee(const Yatzee &originalYatzee);
	Yatzee& operator=(const Yatzee &originalYatzee);
	void addPlayer(const string playerName);
	string protocolInfoOfCurrentPlayer() const;
	int getNrOfPlayers() const;
	void toss();
	void toss(const int diceValue);
	string infoOfLatestToss() const;
	bool addResult(const int diceValue);
	string nameOfCurrentPlayer() const;
	void nextPlayersTurn();
	bool areAllPlayersDone() const;
	~Yatzee();
};

