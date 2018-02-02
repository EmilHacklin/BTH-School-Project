#include "Rectangle.h"

Rectangle::Rectangle(int posX, int posY, double height, double whidth)
	:Shape(posX, posY)
{
	this->height = height;
	this->width = whidth;
}

void Rectangle::setHeight(double height)
{
	this->height = height;
}

void Rectangle::setWidht(double width)
{
	this->width = width;
}

double Rectangle::getHeight() const
{
	return this->height;
}

double Rectangle::getWhidth() const
{
	return this->width;
}

double Rectangle::calcArea() const
{
	return (this->height * this->width);
}

double Rectangle::calcCircumference() const
{
	return ((this->height * 2) + (this->width * 2));
}

string Rectangle::toString() const
{
	return Shape::toString() + "\nHeight: " + to_string(this->height)
		+ "\nWidth" + to_string(this->width);
}

Rectangle::~Rectangle()
{
}
