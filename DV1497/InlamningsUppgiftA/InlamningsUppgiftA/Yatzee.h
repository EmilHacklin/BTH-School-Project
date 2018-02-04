#pragma once
#include<string>
#include"ProtocolColumn.h"
#include"Dice.h"

using namespace std;

const int DEFAULTCAPACITYFORPLAYERS = 3;
const int DEFAULTNROFDICE = 5;

class Yatzee
{
private:
	ProtocolColumn* *players;
	int capacityForPlayers;
	int nrOfPlayers;
	int indexCurrentPlayer;
	Dice* dice;
	int nrOfDice;
	int nrOfSidesOnDie;
	void copyYatzee(const Yatzee &originalYatzee); //Copes Yatzee
	void deallocatePlayers(); //Deallocate players
	void expandPlayers();
public:
	Yatzee(const int capacityForPlayers = DEFAULTCAPACITYFORPLAYERS, const int nrOfDice = DEFAULTNROFDICE, const int nrOfSidesOnDie = DEFAULTNROFSIDESONDIE);
	Yatzee(const Yatzee &originalYatzee);
	Yatzee& operator=(const Yatzee &originalYatzee);
	void addPlayer(const string playerName);
	string protocolInfoOfCurrentPlayer() const;
	int getCurrentPlayerSum() const;
	int getCapacityForPlayers() const;
	int getNrOfPlayers() const;
	int getIndexCurrentPlayer() const;
	int getNrOfDice() const;
	void toss();
	void toss(const int diceValue);
	string infoOfLatestToss() const;
	bool addResult(const int diceValue);
	bool isCurrentPlayerValueFull(const int value) const;
	string nameOfCurrentPlayer() const;
	void nextPlayersTurn();
	bool areAllPlayersDone() const;
	~Yatzee();
};