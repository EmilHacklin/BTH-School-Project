#pragma once
#include "Shape.h"

class Circle :
	public Shape
{
private:
	double radius;
public:
	Circle(int posX = 0, int posY = 0, double radius = 0.0);
	void setRadius(double radius);
	double getRadius() const;
	virtual double calcArea() const;
	virtual double calcCircumference() const;
	string toString() const;
	~Circle();
};

