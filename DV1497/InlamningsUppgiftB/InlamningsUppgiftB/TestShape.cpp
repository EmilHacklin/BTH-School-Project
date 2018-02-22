#include"HorisontalShape.h"
#include"VerticalShape.h"
#include<iostream>
int main()
{
	HorisontalShape hs(100, 200, 25, 50, 5);
	cout << hs.toString() << endl << endl;
	hs.move();
	hs.move();
	cout << hs.toString() << endl << endl;
	hs.changeStep(15);
	hs.move();
	cout << hs.toString() << endl << endl;
	hs.changeDirection();
	hs.move();
	cout << hs.toString() << endl << endl;

	VerticalShape vs(80, 160, 20, 40, 4);
	cout << vs.toString() << endl<<endl;
	vs.move();
	vs.move();
	cout << vs.toString() << endl << endl;
	vs.changeStep(17);
	vs.move();
	cout << vs.toString() << endl << endl;
	vs.changeDirection();
	vs.move();
	cout << vs.toString() << endl << endl;
	
	if (hs.intersectsWith(vs))
	{
		cout << "Överlappar varandra" << endl;
	}
	else
	{
		cout << "Överlappar INTE varandra" << endl;
	}
	cout << endl;

	hs.move();
	cout << hs.toString() << endl << endl;
	cout << vs.toString() << endl << endl;
	if (hs.intersectsWith(vs))
	{
		cout << "Överlappar varandra" << endl;
	}
	else
	{
		cout << "Överlappar INTE varandra" << endl;
	}
	
	//Bör ge följande utskrift
	
	//Horisontal :
	//Position : X: 100  Y : 200
	//Direction : RIGHT
	//Step : 5
	//Width : 25  Height : 50

	//Horisontal :
	//Position : X : 110  Y : 200
	//Direction : RIGHT
	//Step : 5
	//Width : 25  Height : 50

	//Horisontal :
	//Position : X : 130  Y : 200
	//Direction : RIGHT
	//Step : 20
	//Width : 25  Height : 50

	//Horisontal :
	//Position : X : 110  Y : 200
	//Direction : LEFT
	//Step : 20
	//Width : 25  Height : 50

	//Vertical :
	//Position : X : 80  Y : 160
	//Direction : DOWN
	//Step : 4
	//Width : 20  Height : 40

	//Vertical :
	//Position : X : 80  Y : 168
	//Direction : DOWN
	//Step : 4
	//Width : 20  Height : 40

	//Vertical :
	//Position : X : 80  Y : 189
	//Direction : DOWN
	//Step : 21
	//Width : 20  Height : 40

	//Vertical :
	//Position : X : 80  Y : 168
	//Direction : UP
	//Step : 21
	//Width : 20  Height : 40

	//Överlappar INTE varandra

	//Horisontal :
	//Position: X: 90  Y : 200
	//Direction : LEFT
	//Step : 20
	//Width : 25  Height : 50

	//Vertical :
	//Position : X : 80  Y : 168
	//Direction : UP
	//Step : 21
	//Width : 20  Height : 40

	//Överlappar varandra

	system("pause");
	return 0;
}