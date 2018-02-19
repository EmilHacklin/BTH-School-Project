#include "Coord.h"

Coord::Coord(const int xPos, const int yPos)
{
	this->xPos = xPos;
	this->yPos = yPos;
}

Coord::Coord(const Coord & otherCoord)
{
	this->xPos = otherCoord.xPos;
	this->yPos = otherCoord.yPos;
}

Coord & Coord::operator=(const Coord & otherCoord)
{
	this->xPos = otherCoord.xPos;
	this->yPos = otherCoord.yPos;
	return *this;
}

int Coord::getXPos() const
{
	return this->xPos;
}

int Coord::getYPos() const
{
	return this->yPos;
}

void Coord::changeXPos(const int change)
{
	this->xPos += change;
}

void Coord::changeYPos(const int change)
{
	this->yPos += change;
}

Coord::~Coord()
{
}