#include"HorisontalShape.h"
#include"VerticalShape.h"
#include<iostream>
#include<crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	locale swedish("swedish");
	locale::global(swedish);
	int capacity = 5;
	int nrOfShapes = 0;
	Shape* * shapes = nullptr;
	
	//Skapa f�r shapes en dynamiskt allokerad array inneh�llande capacity pekare av typen Shape
	shapes = new Shape*[capacity];
	
	//Skapa i tur och ordning f�ljande 4 objekt vilka pekas ut fr�n shapes
	
	//HorisontalShape-objekt med xPos:10, yPos:10, bredd:50, h�jd:50, stegl�ngd:5
	shapes[0] = new HorisontalShape(10, 10, 50, 50, 5);
	nrOfShapes++;
	//VerticalShape-objekt med xPos:30, yPos:30, bredd:40, h�jd:40, stegl�ngd:10
	shapes[1] = new VerticalShape(30, 30, 40, 40, 10);
	nrOfShapes++;
	//HorisontalShape-objekt med xPos:50, yPos:50, bredd:30, h�jd:30, stegl�ngd:8
	shapes[2] = new HorisontalShape(50, 50, 30, 30, 8);
	nrOfShapes++;
	//VerticalShape-objekt med xPos:100, yPos:100, bredd:25, h�jd:25, stegl�ngd:6
	shapes[3] = new VerticalShape(100, 100, 25, 25, 6);
	nrOfShapes++;

	//F�r HorisontalShape-objektet som pekas ut av shapes[0]: �ndra r�relseriktningen
	shapes[0]->changeDirection();
	//F�r VerticalShape-objektet som pekas ut av shapes[1]: �ndra r�relseriktningen
	shapes[1]->changeDirection();

	//Presentera samtliga Shape-objekt
	for (int i = 0; i < nrOfShapes; i++)
	{
		cout << shapes[i]->toString() << endl;
	}
	
	//Flytta samtliga Shape-objekt
	for (int i = 0; i < nrOfShapes; i++)
	{
		shapes[i]->move();
	}

	//Presentera samtliga Shape-objekt
	for (int i = 0; i < nrOfShapes; i++)
	{
		cout << shapes[i]->toString() << endl;
	}
	
	//Kontrollera om objektet som pekas ut av shapes[0] �verlappar objektet som pekas ut av shapes[3]
	if (shapes[0]->intersectsWith(*shapes[3]))
	{//Presentera resultatet
		cout << "\n�verlappar varandra\n" << endl;
	}
	else
	{
		cout << "\n�verlappar INTE varandra\n" << endl;
	}
	

	//Kontrollera om objektet som pekas ut av shapes[0] �verlappar objektet som pekas ut av shapes[1] 
	if (shapes[0]->intersectsWith(*shapes[1]))
	{//Presentera resultatet
		cout << "�verlappar varandra\n" << endl;
	}
	else
	{
		cout << "�verlappar INTE varandra\n" << endl;
	}
	
	//Presentera endast riktningen f�r HorisontalShape-objekten
	//Du ska utg� fr�n att du inte p� f�rhand vet fr�n vilka positioner de pekas ut fr�n pekarna i arrayen shapes
	for (int i = 0; i < nrOfShapes; i++)
	{
		HorisontalShape *horisontalPtr = dynamic_cast<HorisontalShape*>(shapes[i]);
		if (horisontalPtr != nullptr)
		{
			cout << horisontalPtr->getDirectionAsString() << endl;
		}
	}

	Shape* *shapesCopy = nullptr;

	//Skapa f�r shapesCopy en dynamiskt allokerad array inneh�llande capacity pekare av typen Shape
	shapesCopy = new Shape*[capacity];

	//Tillse att shapesCopy pekar ut identiska objekt med de objekt som shapes pekar ut
	//Djupkopieraing ska anv�ndas!
	for (int i = 0; i < nrOfShapes; i++)
	{
		shapesCopy[i] = shapes[i]->clone();
	}

	//Presentera samtliga Shapes-objekt som shapesCopy pekar ut
	for (int i = 0; i < nrOfShapes; i++)
	{
		cout << shapesCopy[i]->toString() << endl;
	}
	
	//Tillse att inga minnesl�ckor finns
	for (int i = 0; i < nrOfShapes; i++)
	{
		delete shapes[i];
	}
	delete shapes;

	for (int i = 0; i < nrOfShapes; i++)
	{
		delete shapesCopy[i];
	}
	delete shapesCopy;

	system("pause");
	return 0;
}
//Ska ge f�ljande utskrift:

//Horisontal:
//Position: X: 10  Y : 10
//Direction : LEFT
//Step : 5
//Width : 50  Height : 50
//
//Vertical :
//Position : X : 30  Y : 30
//Direction : UP
//Step : 10
//Width : 40  Height : 40
//
//Horisontal :
//Position : X : 50  Y : 50
//Direction : RIGHT
//Step : 8
//Width : 30  Height : 30
//
//Vertical :
//Position : X : 100  Y : 100
//Direction : DOWN
//Step : 6
//Width : 25  Height : 25
//
//Horisontal :
//Position : X : 5  Y : 10
//Direction : LEFT
//Step : 5
//Width : 50  Height : 50
//
//Vertical :
//Position : X : 30  Y : 20
//Direction : UP
//Step : 10
//Width : 40  Height : 40
//
//Horisontal :
//Position : X : 58  Y : 50
//Direction : RIGHT
//Step : 8
//Width : 30  Height : 30
//
//Vertical :
//Position : X : 100  Y : 106
//Direction : DOWN
//Step : 6
//Width : 25  Height : 25
//
//
//�verlappar INTE varandra
//
//�verlappar varandra
//
//LEFT
//
//RIGHT
//
//Horisontal :
//Position: X: 5  Y : 10
//Direction : LEFT
//Step : 5
//Width : 50  Height : 50
//
//Vertical :
//Position : X : 30  Y : 20
//Direction : UP
//Step : 10
//Width : 40  Height : 40
//
//Horisontal :
//Position : X : 58  Y : 50
//Direction : RIGHT
//Step : 8
//Width : 30  Height : 30
//
//Vertical :
//Position : X : 100  Y : 106
//Direction : DOWN
//Step : 6
//Width : 25  Height : 25