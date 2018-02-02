#include "ProtocolColumn.h"
#include <iostream>

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	setlocale(LC_ALL, "swedish");
	ProtocolColumn aProtocol("Kalle");
	aProtocol.addResult(1, 5);

	cout << "-------------------------------------------1-----------------------------------------------" << endl;
	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();

	cout << "Förväntat resultat: " << endl
		<< "Kalle" << endl
		<< "1     :  5" << endl
		<< "2     :  0" << endl
		<< "3     :  0" << endl
		<< "4     :  0" << endl
		<< "5     :  0" << endl
		<< "6     :  0" << endl
		<< "-------------------" << endl
		<< "SUM =    5" << endl;



	cout << endl << "Ditt resultat: " << endl;


	cout << aProtocol.toString() << endl;

	cout << "-------------------------------------------2-----------------------------------------------" << endl;
	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();


	cout << "Förväntat resultat: " << endl
		<< "Korrekt retur på addResult(...)" << endl;
	cout << endl << "Ditt resultat: " << endl;
	if (!aProtocol.addResult(1, 3))
	{
		cout << "Korrekt retur på addResult(...)" << endl;
	}
	else
	{
		cout << "FEL retur på addResult(...)" << endl;
	}

	cout << "-------------------------------------------3-----------------------------------------------" << endl;
	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();

	cout << "Förväntat resultat: " << endl
		<< "Kalle" << endl
		<< "1     :  5" << endl
		<< "2     :  0" << endl
		<< "3     :  0" << endl
		<< "4     :  0" << endl
		<< "5     :  0" << endl
		<< "6     :  0" << endl
		<< "-------------------" << endl
		<< "SUM =    5" << endl;



	cout << endl << "Ditt resultat: " << endl;


	cout << aProtocol.toString() << endl;
	cout << "-------------------------------------------4-----------------------------------------------" << endl;
	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();


	for (int i = 2; i <= 6; i++)
	{
		if (i != 4)
		{
			if (i % 2 == 0)
			{
				aProtocol.addResult(i, i * 3);
			}
			else
			{
				aProtocol.addResult(i, i * 2);
			}
			if (i == 5)
			{
				aProtocol.addResult(5, 25);
			}
		}
	}


	cout << "Förväntat resultat: " << endl
		<< "Kalle" << endl
		<< "1     :  5" << endl
		<< "2     :  6" << endl
		<< "3     :  6" << endl
		<< "4     :  0" << endl
		<< "5     : 10" << endl
		<< "6     : 18" << endl
		<< "-------------------" << endl
		<< "SUM =   45" << endl;



	cout << endl << "Ditt resultat: " << endl;


	cout << aProtocol.toString() << endl;

	cout << "-------------------------------------------5-----------------------------------------------" << endl;

	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();


	cout << "Förväntat resultat: " << endl
		<< "Korrekt retur på isFilled(...)" << endl;
	cout << endl << "Ditt resultat: " << endl;
	if (!aProtocol.isFilled())
	{
		cout << "Korrekt retur på isFilled(...)" << endl;
	}
	else
	{
		cout << "FEL retur på isFilled(...)" << endl;
	}

	cout << "-------------------------------------------6-----------------------------------------------" << endl;

	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();


	cout << "Förväntat resultat: " << endl
		<< "Korrekt retur på getSum()" << endl;
	cout << endl << "Ditt resultat: " << endl;
	if (aProtocol.getTotalSum() == 45)
	{
		cout << "Korrekt retur på getSum()" << endl;
	}
	else
	{
		cout << "FEL retur på getSum()" << endl;
	}

	cout << "-------------------------------------------7-----------------------------------------------" << endl;

	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();

	aProtocol.addResult(4, 20);
	cout << "Förväntat resultat: " << endl
		<< "Kalle" << endl
		<< "1     :  5" << endl
		<< "2     :  6" << endl
		<< "3     :  6" << endl
		<< "4     : 20" << endl
		<< "5     : 10" << endl
		<< "6     : 18" << endl
		<< "-------------------" << endl
		<< "SUM =   65" << endl;



	cout << endl << "Ditt resultat: " << endl;


	cout << aProtocol.toString() << endl;

	cout << "-------------------------------------------8-----------------------------------------------" << endl;
	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();

	ProtocolColumn anotherProtocol("Pelle");
	anotherProtocol.addResult(6, 12);
	anotherProtocol.addResult(2, 0);
	anotherProtocol.addResult(1, 3);
	anotherProtocol.addResult(5, 10);
	anotherProtocol.addResult(3, 9);
	anotherProtocol.addResult(4, 20);


	cout << "Förväntat resultat: " << endl
		<< "Korrekt retur på isFilled()" << endl;
	cout << endl << "Ditt resultat: " << endl;

	if (anotherProtocol.isFilled())
	{
		cout << "Korrekt retur på isFilled()" << endl;
	}
	else
	{
		cout << "FEL retur på isFilled()" << endl;
	}

	cout << "-------------------------------------------9-----------------------------------------------" << endl;
	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();


	cout << "Förväntat resultat: " << endl
		<< "Korrekt retur på getSum()" << endl;
	cout << endl << "Ditt resultat: " << endl;

	if (aProtocol.getTotalSum() > anotherProtocol.getTotalSum())
	{
		cout << "Korrekt retur på getSum()" << endl;
	}
	else
	{
		cout << "FEL retur på getSum()" << endl;
	}

	cout << "-------------------------------------------10----------------------------------------------" << endl;
	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();

	cout << "Förväntat resultat: " << endl
		<< "Korrekt retur på getPlayerName()" << endl;
	cout << endl << "Ditt resultat: " << endl;

	if (aProtocol.getPlayerName() == "Kalle" && anotherProtocol.getPlayerName() == "Pelle")
	{
		cout << "Korrekt retur på getPlayerName()" << endl;
	}
	else
	{
		cout << "FEL retur på getPlayerName()" << endl;
	}

	cout << "-----------------------------------------SLUT----------------------------------------------" << endl;
	cout << endl << "Tryck på en tangent för att fortsätta: " << endl;
	getchar();

	return 0;
}