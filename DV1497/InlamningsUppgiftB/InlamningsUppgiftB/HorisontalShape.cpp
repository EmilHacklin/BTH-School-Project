#include "HorisontalShape.h"

HorisontalShape::HorisontalShape(const int xPos, const int yPos, const int width, const int height, const int step):
	Shape(xPos, yPos, width, height, step)
{
	this->xDirection = 1;
}

HorisontalShape::HorisontalShape(const HorisontalShape & otherShape)
{
}

HorisontalShape & HorisontalShape::operator=(const HorisontalShape & otherShape)
{
	// TODO: insert return statement here
}

void HorisontalShape::changeDirection()
{
	if (this->xDirection == 1)
	{
		this->xDirection = -1;
	}
	else
	{
		this->xDirection = 1;
	}
}

string HorisontalShape::getDirectionAsString() const
{
	if (this->xDirection == 1)
	{
		return this->RIGHT;
	}
	else
	{
		return this->LEFT;
	}
}

string HorisontalShape::startString() const
{
	return "\nHorisontal :\n";
}

void HorisontalShape::move()
{
	if (this->xDirection == 1)
	{
		this->changeCoord(this->getStep(), 0);
	}
	else
	{
		this->changeCoord(-this->getStep(),0);
	}
}

HorisontalShape::~HorisontalShape()
{
}