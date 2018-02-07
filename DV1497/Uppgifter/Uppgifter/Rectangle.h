#pragma once
#include "Shape.h"
class Rectangle :
	public Shape
{
private:
	double height;
	double width;
public:
	Rectangle(int posX = 0, int posY = 0, double height = 0.0, double whidth = 0.0);
	void setHeight(double height);
	void setWidht(double width);
	double getHeight() const;
	double getWhidth() const;
	virtual double calcArea() const;
	virtual double calcCircumference() const;
	string toString() const;
	~Rectangle();
};

