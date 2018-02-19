#include "VerticalShape.h"

VerticalShape::VerticalShape(const int xPos, const int yPos, const int width, const int height, const int step):
	Shape(xPos, yPos, width, height, step)
{
	this->yDirection = 1;
}

VerticalShape::VerticalShape(const VerticalShape & otherShape)
{
}

VerticalShape & VerticalShape::operator=(const VerticalShape & otherShape)
{
	// TODO: insert return statement here
}

void VerticalShape::changeDirection()
{
	if (this->yDirection == 1)
	{
		this->yDirection = -1;
	}
	else
	{
		this->yDirection = 1;
	}
}

string VerticalShape::getDirectionAsString() const
{
	if (this->yDirection == 1)
	{
		return this->DOWN;
	}
	else
	{
		return this->UP;
	}
}

string VerticalShape::startString() const
{
	return "\nVertical :\n";
}

void VerticalShape::move()
{
	if (this->yDirection == 1)
	{
		this->changeCoord(0, this->getStep());
	}
	else
	{
		this->changeCoord(0, -this->getStep());
	}
}

VerticalShape::~VerticalShape()
{
}