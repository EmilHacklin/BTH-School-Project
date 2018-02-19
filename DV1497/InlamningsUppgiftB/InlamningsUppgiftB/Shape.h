#pragma once
#include<string>
#include"Coord.h"
#include"Box.h"
using namespace std;

class Shape
{
private:
	int step;
public:
	static const string UP;
	static const string DOWN;
	static const string LEFT;
	static const string RIGHT;
	Coord coord;
	Box box;
	Shape(const int xPos = 0, const int yPos = 0, const int width = 0, const int height = 0, const int step = 0);
	Shape(const Shape &otherShape);
	Shape& operator=(const Shape &otherShape);
	void changeCoord(const int xChange, const int yChange);
	int getStep() const;
	void changeStep(const int change);
	bool intersectsWith(const Shape &otherShape) const;
	string toString() const;
	virtual void changeDirection() = 0;
	virtual string getDirectionAsString() const = 0;
	virtual string startString() const = 0;
	virtual void move() = 0;
	virtual Shape* clone() const = 0;
	~Shape();
};

