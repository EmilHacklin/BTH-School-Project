#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string>
#include"Uppgifter.h"

using namespace std;

void assignment1();
void assignment2();
void assignment3();
void assignment4();
void assignment5();
void assignment6();
void assignment7();
void assignment8();
void assignment9();
void assignment10();
void assignment11();
void assignment12();
void assignment13();
void assignment14();
void assignment15();
void assignment16();

int main()
{
	//assignment1();
	//assignment2();
	//assignment3();
	//assignment4();
	//assignment5();
	//assignment6();
	//assignment7();
	//assignment8();
	//assignment9();
	assignment10();
	//assignment11();
	//assignment12();
	//assignment13();
	//assignment14();
	//assignment15();
	//assignment16();

	return 0;
}

void assignment1()
{
	assignmentHeader(1);

	const unsigned short CAP = 10;
	unsigned short arr[CAP] = { 0 };
	unsigned int seed = static_cast <unsigned> (time(0));

	srand(seed);
	for (int i = 0; i < CAP; i++)
	{
		arr[i] = rand() % 100 + 1;
		cout << arr[i] << "\n";
	}

	enterToContinue();
}

void assignment2()
{
	assignmentHeader(2);
	
	const short CAP = 20;
	float arr[CAP] = { 0.0 };
	unsigned short answer = 0;
	unsigned int seed = static_cast <unsigned> (time(0));
	
	cout << "How many random numbers do you want?(0-20): ";
	cin >> answer;
	cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');

	srand(seed);
	for (unsigned short i = CAP-1; i > (CAP - answer -1); i--)
	{
		arr[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		cout << arr[i] << endl;
	}

	enterToContinue();
}

void assignment3()
{
	assignmentHeader(3);

	const unsigned short CAP = 5;
	float arr[CAP] = { 0.0 };
	float total = 0.0;

	for (unsigned int i = 0; i < CAP; i++)
	{
		cout << "Enter in float " << i + 1 << ": ";
		cin >> arr[i];
		cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');
		total += arr[i];
	}

	cout << "The average of the numbers you have entered is "
		<< total/CAP << endl;

	enterToContinue();
}

void assignment4()
{
	assignmentHeader(4);

	const unsigned short CAP = 20;
	unsigned int arr[CAP] = { 0 };
	unsigned int seed = static_cast <unsigned> (time(0));
	unsigned int indexLargest = 0;

	srand(seed);
	for (unsigned int i = 0; i < CAP; i++)
	{
		arr[i] = rand() % 100 + 1;
		if (arr[i] > arr[indexLargest])
		{
			indexLargest = i;
		}
	}

	cout << "The largest value is in position "
		<< indexLargest << " of the array and has the value "
		<< arr[indexLargest] << endl;
	

	enterToContinue();
}

void assignment5()
{
	assignmentHeader(5);

	const unsigned short CAP = 15;
	unsigned int arr[CAP] = { 0 };
	unsigned int seed = static_cast <unsigned> (time(0));
	unsigned int  evenTotal, oddTotal;
	evenTotal = oddTotal = 0;

	srand(seed);
	for (unsigned int i = 0; i < CAP; i++)
	{
		arr[i] = rand() % 50;
		if ((i % 2) == 0)
		{
			evenTotal += arr[i];
		}
		else
		{
			oddTotal += arr[i];
		}
	}

	cout << "The sum of all even index positions is "
		<< evenTotal
		<< " and the sum of all odd index positions is "
		<< oddTotal << endl;
	
	enterToContinue();
}

void assignment6()
{
	assignmentHeader(6);

	const unsigned short CAP = 2;
	string nameArr[CAP] = { "" };
	unsigned int phoneArr[CAP] = { 0 };
	string searchName = "";
	bool foundName = false;

	for (unsigned int i = 0; i < CAP; i++)
	{
		cout << "Enter in name number " << i + 1 << ": ";
		getline(cin, nameArr[i]);
		cout << "Enter in name number " << i + 1 
			<< "`s phone number: ";
		cin >> phoneArr[i];
		cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');
	}

	cout << "\n\nWhat name do you want the phone number for?: ";
	getline(cin, searchName);
	do
	{
		for (unsigned int i = 0; i < CAP; i++)
		{
			if (nameArr[i] == searchName)
			{
				cout << "The phone number for " << searchName
					<< " is " << phoneArr[i] << endl;
				foundName = true;
			}
		}
		if (!foundName)
		{
			cout << searchName << " dose not exist in the array, please try again: ";
			getline(cin, searchName);
		}
	} while (!foundName);
	
	
	enterToContinue();
}

void assignment7()
{
	unsigned short capacity = 5, nrOfPersons = 0, increment = 5;
	string *nameArr = new string[capacity];
	unsigned int *phoneArr = new unsigned int[capacity];
	bool foundName = false;
	char choise = ' ';

	do
	{
		assignmentHeader(7);
		printStars(34);
		cout << "\nA) Add person to array\n"
			<< "B) Print out array\n"
			<< "C) Search for persons phone number\n"
			<< "D) Exit program\n";
		printStars(34);
		cout << endl;
		cin >> choise;
		cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');
		switch (choise)
		{
		case 'a':
		case 'A':
		{
			if (nrOfPersons == (capacity - 1)) //If array is full increases the size of the array
			{
				string *tempNameArr = new string[capacity + increment];
				unsigned int *tempPhoneArr = new unsigned int[capacity + increment];

				for (unsigned int i = 0; i < capacity; i++)
				{
					tempNameArr[i] = nameArr[i];
					tempPhoneArr[i] = phoneArr[i];
				}

				delete nameArr;
				delete phoneArr;

				*nameArr = *tempNameArr;
				*phoneArr = *tempPhoneArr;
				capacity += increment;
			}

			cout << "Enter in the name of the person: ";
			getline(cin, nameArr[nrOfPersons]);
			cout << "Enter in " << nameArr[nrOfPersons]
				<< "`s phone number: ";
			cin >> phoneArr[nrOfPersons];
			cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');

			nrOfPersons++;
			clearScreen();
		}break;
		case 'b':
		case 'B':
		{
			for (unsigned int i = 0; i < nrOfPersons; i++)
			{
				cout << "\n" << nameArr[i] << " has the phone number " << phoneArr[i];
			}
			enterToContinue();
		}break;
		case 'c':
		case 'C':
		{
			string searchName = "";
			cout << "\n\nWhat name do you want the phone number for?: ";
			getline(cin, searchName);
			do
			{
				for (unsigned int i = 0; i < capacity; i++)
				{
					if (nameArr[i] == searchName)
					{
						cout << "The phone number for " << searchName
							<< " is " << phoneArr[i] << endl;
						foundName = true;
					}
				}
				if (!foundName)
				{
					cout << searchName << " dose not exist in the array, please try again: ";
					getline(cin, searchName);
				}
			} while (!foundName);
			enterToContinue();
		}break;
		}
	} while ((choise != 'd') && (choise != 'D'));
	
	delete[] nameArr;
	delete[] phoneArr;

	clearScreen();
}

void assignment8()
{
	assignmentHeader(8);

	const unsigned short CAP = 10;
	int numberArr[CAP] = { 0 }, multiplicationArr[CAP] = { 0 };
	int multiplicationFactor = 0;
	unsigned int seed = static_cast <unsigned> (time(0));

	cout << "What is the factor you want to multiply by: ";
	cin >> multiplicationFactor;
	cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');

	cout << "\n*** Number array ****** Multiplication array ***\n" << endl;

	srand(seed);
	for (int i = 0; i < CAP; i++)
	{
		numberArr[i] = rand();
		multiplicationArr[i] = (numberArr[i] * multiplicationFactor);
		cout << setw(12) << numberArr[i] << setw(27) << multiplicationArr[i] << endl;
	}

	enterToContinue();
}

void assignment9()
{
	const unsigned short CAP = 8;
	string phrasesArr[CAP] = { "" }, cookiesArr[CAP] = { "" };
	unsigned short  eatenCookiesArr[CAP] = { 0 };
	unsigned short choice = 0, nrOfCookies = 0;
	unsigned int seed = static_cast <unsigned> (time(0));

	phrasesArr[0] = "Det blir inte alltid som man vill";
	phrasesArr[1] = "I morgon blir det fint väder";
	phrasesArr[2] = "Kasta inte glas i stenhus";
	phrasesArr[3] = "Ät inte den gula snön";
	phrasesArr[4] = "Din bror är din pappas son";
	phrasesArr[5] = "Efter solsken kommer regn";
	phrasesArr[6] = "Gå inte över ån efter vatten";
	phrasesArr[7] = "Skjut inte björnen förrän skinnet är sålt";

	srand(seed);
	do
	{
		assignmentHeader(9);
		cout << "Pick a cookie to eat (1-8): ";
		cin >> choice;
		cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');
		if (choice <= 0 || (choice - 1) > CAP)
		{
			cout << "That cookie dose not exist!" << endl;
		}
		else if (eatenCookiesArr[choice-1] == 0)
		{
			int nr = rand() % 8;
			cout << "Phrase: " << phrasesArr[nr] << endl;
			cookiesArr[nrOfCookies] = phrasesArr[nr];
			nrOfCookies++;
			eatenCookiesArr[choice - 1]++;
			enterToContinue();
		}
		else
		{
			cout << "That cookie is already eaten!\n" 
				<< "You have chosen that cookie " 
				<< eatenCookiesArr[choice-1] << " times" 
				<< endl;
			eatenCookiesArr[choice - 1]++;
		}
	}while(nrOfCookies != 8);


	cout << "You got the phrases in the flowing order" << endl;
	for (unsigned short i = 0; i < CAP; i++)
	{
		cout << cookiesArr[i] << endl;
	}

	enterToContinue();
}

void assignment10()
{
	assignmentHeader(10);

	enterToContinue();
}

void assignment11()
{
	assignmentHeader(11);

	enterToContinue();
}

void assignment12()
{
	assignmentHeader(12);

	enterToContinue();
}

void assignment13()
{
	assignmentHeader(13);



	enterToContinue();
}

void assignment14()
{
	assignmentHeader(14);

	

	enterToContinue();
}

void assignment15()
{
	assignmentHeader(15);



	enterToContinue();
}

void assignment16()
{
	assignmentHeader(15);



	enterToContinue();
}
