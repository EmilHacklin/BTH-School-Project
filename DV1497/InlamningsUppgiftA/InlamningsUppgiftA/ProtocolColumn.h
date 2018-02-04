#pragma once
#include<string>

using namespace std;

const int DEFAULTNROFROWS = 6; //Default number or rows

class ProtocolColumn
{
private:
	string playerName;
	int nrOfRows;
	int* *resultArray; //Double pointer of int will be used for a int* array 
	void copyProtocolColumn(const ProtocolColumn &originalProtocolColumn); //Copes ProtocolColumn
	void deallocateRows(); //Deallocate ProtocolColumn
public:
	ProtocolColumn(const string playerName = "?", const int nrOfRows = DEFAULTNROFROWS); //? and default number of rows is the default argument for the constructor
	ProtocolColumn(const ProtocolColumn &originalProtocolColumn);
	ProtocolColumn& operator=(const ProtocolColumn &originalProtocolColumn);
	bool addResult(const int diceValue, const int result);
	string getPlayerName() const;
	int getNrOfRows() const;
	int getTotalSum() const;
	bool isFilled() const;
	bool isFilled(const int value) const;
	string toString() const;
	~ProtocolColumn();
};