#pragma once
#include<string>

using namespace std;

class ProtocolColumn
{
private:
	string name;
	int* *resultArray;
public:
	ProtocolColumn(const string name);
	bool addResult(const int diceValue, const int result);
	string getPlayerName() const;
	int getTotalSum() const;
	bool isFilled() const;
	string toString() const;
	~ProtocolColumn();
};

