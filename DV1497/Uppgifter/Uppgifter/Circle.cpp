#include "Circle.h"


Circle::Circle(int posX, int posY, double radius)
	:Shape(posX, posY)
{
	this->radius = radius;
}

void Circle::setRadius(double radius)
{
	this->radius = radius;
}

double Circle::getRadius() const
{
	return this->radius;
}

double Circle::calcArea() const
{
	return (this->radius * this->radius * 3.14159265358979323846);
}

double Circle::calcCircumference() const
{
	return ((this->radius * 2) * 3.14159265358979323846);
}

string Circle::toString() const
{
	return Shape::toString() + "\nRadius: " + to_string(this->radius);
}

Circle::~Circle()
{
}
