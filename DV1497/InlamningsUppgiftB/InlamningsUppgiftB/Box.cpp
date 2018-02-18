#include "Box.h"

Box::Box(const int width, const int height)
{
	this->width = width;
	this->height = height;
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