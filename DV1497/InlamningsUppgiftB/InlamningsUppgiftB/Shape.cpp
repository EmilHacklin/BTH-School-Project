#include "Shape.h"

const string Shape::UP = "UP\n";
const string Shape::DOWN = "DOWN\n";
const string Shape::LEFT = "LEFT\n";
const string Shape::RIGHT = "RIGHT\n";

Shape::Shape(const int posX, const int posY, const int width, const int height, const int step):coord(posX, posY), box(width, height)
{
	this->step = step;
}

Shape::
Shape(const Shape & otherShape)
{
}

Shape & Shape::operator=(const Shape & otherShape)
{
	// TODO: insert return statement here
}

void Shape::changeCoord(const int xChange, const int yChange)
{
	this->coord.changeXPos(xChange);
	this->coord.changeYPos(yChange);
}

int Shape::getStep() const
{
	return this->step;
}

void Shape::changeStep(const int change)
{
	if ((this->step + change) >= 0)
	{
		this->step += change;
	}
}

bool Shape::intersectsWith(const Shape & otherShape) const
{
	if ((otherShape.coord.getXPos() < this->coord.getXPos() + this->box.getWidth()) 
		&& (otherShape.coord.getYPos() > this->coord.getYPos() - this->box.getHeight())
		&& (otherShape.coord.getXPos() + otherShape.box.getWidth() > this->coord.getXPos()) 
		&& (otherShape.coord.getYPos() - otherShape.box.getHeight() < this->coord.getYPos()))
	{
		return true;
	}
	return false;
}

string Shape::toString() const
{
	string returnString = this->startString();
	returnString += "Position : X: ";
	returnString += to_string(this->coord.getXPos());
	returnString += "  Y : ";
	returnString += to_string(this->coord.getYPos());
	returnString += "\nDirection : ";
	returnString += this->getDirectionAsString();
	returnString += "Step : ";
	returnString += to_string(this->step);
	returnString += "\nWidth : ";
	returnString += to_string(this->box.getWidth());
	returnString += "  Height : ";
	returnString += to_string(this->box.getHeight());
	return returnString;
}

Shape::~Shape()
{
}