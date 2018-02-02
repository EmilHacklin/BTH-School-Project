#pragma once
#include<string>

using namespace std;

class Shape
{
private:
	int x;
	int y;
public:
	Shape(int x = 0, int y = 0);
	string toString() const;
	void move(int distanceX, int distanceY);
	~Shape();
};

