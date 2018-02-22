#include "Box.h"

Box::Box(const int width, const int height)
{
	this->width = width;
	this->height = height;
}

Box::Box(const Box & otherBox)
{
	this->width = otherBox.width;
	this->height = otherBox.height;
}

Box & Box::operator=(const Box & otherBox)
{
	this->width = otherBox.width;
	this->height = otherBox.height;
	return *this;
}

int Box::getWidth() const
{
	return this->width;
}

int Box::getHeight() const
{
	return this->height;
}

Box::~Box()
{
}