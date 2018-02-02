#include<iostream>
#include"Circle.h"
#include"Rectangle.h"

using namespace std;

int main()
{
	Shape s;
	cout << "s is a shape object that has:\n" << s.toString() << endl;

	s.move(100, 200);
	cout << "s is a shape object that has:\n" << s.toString() << endl;
	cin.get();
	
	Circle c;
	cout << "c is a circle object that has:\n" << c.toString()
		<< "\nArea: " << c.calcArea() 
		<< "\nCircumference: " << c.calcCircumference() << endl;

	c.move(100, 200);
	cout << "c is a circle object that has:\n" << c.toString()
		<< "\nArea: " << c.calcArea()
		<< "\nCircumference: " << c.calcCircumference() << endl;

	c.setRadius(5.0);
	cout << "c is a circle object that has:\n" << c.toString()
		<< "\nArea: " << c.calcArea()
		<< "\nCircumference: " << c.calcCircumference() << endl;
	cin.get();

	Rectangle r;
	cout << "r is a Rectangle object that has:\n" << r.toString()
		<< "\nArea: " << r.calcArea()
		<< "\nCircumference: " << r.calcCircumference() << endl;

	r.move(100, 200);
	cout << "r is a Rectangle object that has:\n" << r.toString()
		<< "\nArea: " << r.calcArea()
		<< "\nCircumference: " << r.calcCircumference() << endl;

	r.setHeight(10.1);
	cout << "r is a Rectangle object that has:\n" << r.toString()
		<< "\nArea: " << r.calcArea()
		<< "\nCircumference: " << r.calcCircumference() << endl;

	r.setWidht(4.3);
	cout << "r is a Rectangle object that has:\n" << r.toString()
		<< "\nArea: " << r.calcArea()
		<< "\nCircumference: " << r.calcCircumference() << endl;
	cin.get();

	Shape s2(10, 20);
	cout << "s2 is a shape object that has:\n" << s.toString() << endl;
	cin.get();

	Circle c2(10, 20, 5.3);
	cout << "c is a circle object that has:\n" << c.toString()
		<< "\nArea: " << c.calcArea()
		<< "\nCircumference: " << c.calcCircumference() << endl;
	cin.get();

	Rectangle r2(10, 20, 6.4, 8.7);
	cout << "r is a Rectangle object that has:\n" << r.toString()
		<< "\nArea: " << r.calcArea()
		<< "\nCircumference: " << r.calcCircumference() << endl;
	cin.get();
	return 0;
}