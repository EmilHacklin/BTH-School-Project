#include "VerticalShape.h"

VerticalShape::VerticalShape(const int xPos, const int yPos, const int width, const int height, const int step):
	Shape(xPos, yPos, width, height, step)
{
	this->yDirection = 1;
}

VerticalShape::VerticalShape(const VerticalShape & otherShape):
	Shape(otherShape)
{
	this->yDirection = otherShape.yDirection;
}

VerticalShape & VerticalShape::operator=(const VerticalShape & otherShape)
{
	if (this != &otherShape)
	{
		Shape::operator=(otherShape);
		this->yDirection = otherShape.yDirection;
	}
	return *this;
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

VerticalShape* VerticalShape::clone() const
{
	return new VerticalShape(*this);
}

VerticalShape::~VerticalShape()
{
}