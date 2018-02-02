#pragma once
#include <cstdlib>
#include <ctime>

class Dice
{
private:
	int value;
	int sides;
public:
	Dice(const int sides = 6);
	void toss();
	int getCurrentValue() const;
	~Dice();
};

