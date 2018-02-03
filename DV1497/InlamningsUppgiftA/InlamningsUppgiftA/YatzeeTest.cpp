#include "Yatzee.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void testingCopyConstructor(Yatzee theYatzee)
{
	theYatzee.addPlayer("Stina");
	theYatzee.toss();

}

void showProtocols(Yatzee &theYatzee)
{
	for (int i = 0; i < theYatzee.getNrOfPlayers(); i++)
	{
		cout << theYatzee.protocolInfoOfCurrentPlayer() << endl;
		theYatzee.nextPlayersTurn();
		cout << endl;
	}
}

void testingTossing(Yatzee &theYatzee, int n = 3)
{
	int value = rand()%6+1;
	for (int round = 1; round <= n; round++)
	{
		theYatzee.toss();
		theYatzee.toss(value);
		theYatzee.toss(value);
		theYatzee.addResult(value);
		theYatzee.nextPlayersTurn();
		value = rand() % 6 + 1;
		theYatzee.toss();
		theYatzee.toss(value);
		theYatzee.toss(value);
		theYatzee.addResult(value);
		theYatzee.nextPlayersTurn();
		value = rand() % 6 + 1;
	}
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	setlocale(LC_ALL, "swedish");
	srand(100);
	Yatzee aYatzee(2);
	
	cout << "--------------------------------------------1----------------------------------------" << endl;	
	cout << "Testar kopieringskonstruktorn på objekt utan några protokoll" << endl;
	
	cout << "Förväntad utskrift:\n";
	cout << "Antalet spelare 2\n\nRune\nLisa\n\n"
		<<"Rune\n1     :  2\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  0\n"
		<< "-------------------\nSUM =    7\n\n"
		<<"Lisa\n"
		<< "1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     :  0\n6     :  6\n"
		<< "-------------------\nSUM =   14\n" << endl;
	
	cout << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();

	cout <<endl << "Din utskrift: " << endl;
	testingCopyConstructor(aYatzee);

	
	aYatzee.addPlayer("Rune");
	aYatzee.addPlayer("Lisa");
	cout << "Antalet spelare: " << aYatzee.getNrOfPlayers() << endl;
	cout << endl;
	for (int i = 0; i < aYatzee.getNrOfPlayers(); i++)
	{
		cout << aYatzee.nameOfCurrentPlayer() << endl;
		aYatzee.nextPlayersTurn();
	}

	cout << endl;
	
	testingTossing(aYatzee, 2);
	
	showProtocols(aYatzee);

	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();
	system("cls");
	cout << "--------------------------------------------2----------------------------------------" << endl;

	cout << "Testar kopieringskonstruktor på objekt innehållande protokoll" << endl;

	cout << "Förväntad utskrift:\n";
	cout << "Rune\n1     :  2\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  0\n"
		<< "-------------------\nSUM =    7\n\n"
		<<"Lisa\n1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
		<< "-------------------\nSUM =   24\n" << endl;
	cout << "Rune\n1     :  2\n2     :  0\n3     : 15\n4     :  0\n5     :  5\n6     :  0\n"
		<< "-------------------\nSUM =   22\n\n"
		<<"Lisa\n1     :  2\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
		<< "-------------------\nSUM =   26\n" << endl;

	
	cout << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();

	cout << endl << "Din utskrift: " << endl;

	testingCopyConstructor(aYatzee);

	Yatzee xYatzee = aYatzee;
	testingTossing(xYatzee);
	testingTossing(aYatzee, 1);
	
	showProtocols(aYatzee);
	showProtocols(xYatzee);
	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();
	system("cls");
	cout << "--------------------------------------------3----------------------------------------" << endl;

	cout << "Testar tilldelningsoperator mellan objekt som inte innehåller protokoll och "
		<< " objekt som innehåller protokoll" << endl;
	
	cout << "Förväntad utskrift:\n";
	cout << "Rune\n1     :  2\n2     :  0\n3     :  0\n4     :  8\n5     :  5\n6     :  0\n"
		<< "-------------------\nSUM =   15\n\n"
		<<"Lisa\n1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
		<< "-------------------\nSUM =   24\n" << endl;
	cout << "Rune\n1     :  2\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  0\n"
		<< "-------------------\nSUM =    7\n\n"
		<<"Lisa\n1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
		<< "-------------------\nSUM =   24\n" << endl;

	
	cout << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();


	cout << "Din utskrift\n";
	Yatzee anotherYatzee;
	anotherYatzee = aYatzee;
	testingTossing(anotherYatzee, 2);
	showProtocols(anotherYatzee);
	showProtocols(aYatzee);
	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();
	system("cls");

	cout << "--------------------------------------------4----------------------------------------" << endl;

	cout << "Testar tilldelningsoperatorn mellan två objekt som innehåller protokoll" << endl;
	
	cout << "Förväntad utskrift:\n";
	cout << "Rune\n1     :  2\n2     :  4\n3     :  0\n4     : 12\n5     :  5\n6     : 12\n"
		<< "-------------------\nSUM =   35\n\n"
		<<"Lisa\n1     :  3\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
		<< "-------------------\nSUM =   27\n" << endl;
	cout << "Rune\n1     :  2\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  0\n"
		<< "-------------------\nSUM =    7\n\n"
		<<"Lisa\n1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
		<< "-------------------\nSUM =   24\n" << endl;


	cout << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();
	anotherYatzee = aYatzee;
	cout << "Din utskrift:\n";
	testingTossing(anotherYatzee, 4);

	showProtocols(anotherYatzee);
	showProtocols(aYatzee);
	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();
	system("cls");

	cout << "--------------------------------------------5----------------------------------------" << endl;

	cout << "Testar tilldelningsoperatorn mellan objekt som innehåller protokoll" 
		<< " och objekt som inte innehåller protokoll" << endl;
	
	cout << "Förväntad utskrift:\n";
	cout << "Katarina\n1     :  0\n2     :  4\n3     :  0\n4     :  0\n5     : 10\n6     :  0\n"
		<< "-------------------\nSUM =   14\n\n"
		<<"Charlotta\n1     :  1\n2     :  0\n3     :  9\n4     :  0\n5     :  0\n6     : 18\n"
		<< "-------------------\nSUM =   28\n" << endl;
	


	cout << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();


	cout << "Din utskrift\n";
	
		
	Yatzee aThirdYatzee;
	aYatzee = aThirdYatzee;

	aYatzee.addPlayer("Katarina");
	aYatzee.addPlayer("Charlotta");
	testingTossing(aYatzee,5);
	
	showProtocols(aYatzee);

	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();
	system("cls");
	cout << "--------------------------------------------6----------------------------------------" << endl;
	
	cout << "Testar tilldelningsoperatorn mellan två objekt som inte innehåller protokoll"<<endl;
	
	cout << "Förväntad utskrift:\n";
	cout << "Allan\n1     :  0\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  6\n"
		<< "-------------------\nSUM =   11\n\n"
		<<"Britta\n1     :  0\n2     :  8\n3     :  0\n4     : 12\n5     :  0\n6     :  0\n"
		<< "-------------------\nSUM =   20\n" << endl;
	cout << "Herbert\n1     :  0\n2     :  0\n3     :  9\n4     :  0\n5     : 15\n6     :  0\n"
		<< "-------------------\nSUM =   24\n\n"
		<<"Hugo\n1     :  3\n2     :  0\n3     :  0\n4     :  0\n5     :  0\n6     :  0\n"
		<< "-------------------\nSUM =    3\n" << endl;
	cout << "Rut\n1     :  0\n2     :  2\n3     :  0\n4     :  0\n5     :  0\n6     :  0\n"
		<< "-------------------\nSUM =    2\n\n"
		<<"Bertil\n1     :  0\n2     :  2\n3     :  0\n4     :  0\n5     :  0\n6     :  0\n"
		<< "-------------------\nSUM =    2\n" << endl;
	
	cout << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();

	Yatzee bYatzee(3);
	Yatzee cYatzee;

	cYatzee = bYatzee;
	
	cYatzee.addPlayer("Allan");
	cYatzee.addPlayer("Britta");
	cYatzee.addPlayer("Herbert");

	testingTossing(cYatzee);
	bYatzee.addPlayer("Bertil");
	bYatzee.addPlayer("Hugo");
	bYatzee.addPlayer("Rut");
	testingTossing(bYatzee,2);

	showProtocols(cYatzee);
	showProtocols(bYatzee);

	cout << "------------------------------------------SLUT---------------------------------------" << endl;

	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();
	return 0;
}