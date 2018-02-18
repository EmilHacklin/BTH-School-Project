#include"Coord.h"
#include<iostream>
using namespace std;
int main()
{
	int x = 50;
	int y = 70;
	
	Coord coord1(x, y);
	cout << "x-koord: " << coord1.getXPos() << " ,  y-koord: " << coord1.getYPos() << endl;
	coord1.changeXPos(5);
	coord1.changeYPos(-10);
	cout << "x-koord: " << coord1.getXPos() << " ,  y-koord: " << coord1.getYPos() << endl;
	coord1.changeXPos(-15);
	coord1.changeYPos(20);
	cout << "x-koord: " << coord1.getXPos() << " ,  y-koord: " << coord1.getYPos() << endl;

	//Ska ge följande utskrift
	//x - koord: 50 , y - koord : 70
	//x - koord : 55, y - koord : 60
	//x - koord : 40, y - koord : 80

	system("pause");
	return 0;
}