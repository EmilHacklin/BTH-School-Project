#include "Shape.h"


Shape::Shape(int x, int y)
{
	this->x = x;
	this->y = y;
}

string Shape::toString() const
{
	return "PosX: " + to_string(this->x) 
		+ "\nPosY: " + to_string(this->y);
}

void Shape::move(int distanceX, int distanceY)
{
	this->x += distanceX;
	this->y += distanceY;
}

Shape::~Shape()
{
}
