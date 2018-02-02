#pragma once
#include<string>
#include"ProtocolColumn.h"
#include"Dice.h"

using namespace std;

class Yatzee
{
private:
public:
	Yatzee();
	void addPlayer(const string name);
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

