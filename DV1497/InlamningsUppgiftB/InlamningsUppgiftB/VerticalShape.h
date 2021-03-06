#pragma once
#include "Shape.h"

class VerticalShape :
	public Shape
{
private:
	int yDirection;
public:
	VerticalShape(const int xPos = 0, const int yPos = 0, const int width = 0, const int height = 0, const int step = 0);
	VerticalShape(const VerticalShape &otherShape);
	VerticalShape& operator=(const VerticalShape &otherShape);
	virtual void changeDirection();
	virtual string getDirectionAsString() const;
	virtual string startString() const;
	virtual void move();
	virtual VerticalShape* clone() const;
	~VerticalShape();
};

