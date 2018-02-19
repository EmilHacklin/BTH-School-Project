#pragma once
#include "Shape.h"

class HorisontalShape :
	public Shape
{
private:
	int xDirection;
public:
	HorisontalShape(const int xPos = 0, const int yPos = 0, const int width = 0, const int height = 0, const int step = 0);
	HorisontalShape(const HorisontalShape &otherShape);
	HorisontalShape& operator=(const HorisontalShape &otherShape);
	virtual void changeDirection();
	virtual string getDirectionAsString() const;
	virtual string startString() const;
	virtual void move();
	virtual HorisontalShape& clone(HorisontalShape &otherShape) const;
	~HorisontalShape();
};

