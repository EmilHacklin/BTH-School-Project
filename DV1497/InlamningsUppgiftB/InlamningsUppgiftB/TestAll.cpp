#include"HorisontalShape.h"
#include"VerticalShape.h"
#include<iostream>
#include<crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int capacity = 5;
	int nrOfShapes = 0;
	Shape* * shapes = nullptr;
	
	//Skapa för shapes en dynamiskt allokerad array innehållande capacity pekare av typen Shape
	
	//Skapa i tur och ordning följande 4 objekt vilka pekas ut från shapes
	
	//HorisontalShape-objekt med xPos:10, yPos:10, bredd:50, höjd:50, steglängd:5
	//VerticalShape-objekt med xPos:30, yPos:30, bredd:40, höjd:40, steglängd:10
	//HorisontalShape-objekt med xPos:50, yPos:50, bredd:30, höjd:30, steglängd:8
	//VerticalShape-objekt med xPos:100, yPos:100, bredd:25, höjd:25, steglängd:6

	//För HorisontalShape-objektet som pekas ut av shapes[0]: ändra rörelseriktningen
	//För VerticalShape-objektet som pekas ut av shapes[1]: ändra rörelseriktningen

	//Presentera samtliga Shape-objekt
	
	//Flytta samtliga Shape-objekt

	//Presentera samtliga Shape-objekt
	
	//Kontrollera om objektet som pekas ut av shapes[0] överlappar objektet som pekas ut av shapes[3]
	//Presentera resultatet

	//Kontrollera om objektet som pekas ut av shapes[0] överlappar objektet som pekas ut av shapes[1] 
	//Presentera resultatet
	
	//Presentera endast riktningen för HorisontalShape-objekten
	//Du ska utgå från att du inte på förhand vet från vilka positioner de pekas ut från pekarna i arrayen shapes
	
	
	Shape* *shapesCopy = nullptr;

	//Skapa för shapesCopy en dynamiskt allokerad array innehållande capacity pekare av typen Shape

	//Tillse att shapesCopy pekar ut identiska objekt med de objekt som shapes pekar ut
	//Djupkopieraing ska användas!

	//Presentera samtliga Shapes-objekt som shapesCopy pekar ut
	
	//Tillse att inga minnesläckor finns

	system("pause");
	return 0;
}
//Ska ge följande utskrift:

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
//Överlappar INTE varandra
//
//Överlappar varandra
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