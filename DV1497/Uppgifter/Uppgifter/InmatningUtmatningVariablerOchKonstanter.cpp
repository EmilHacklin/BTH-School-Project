#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
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

int main()
{
	assignment1();
	assignment2();
	assignment3();
	assignment4();
	assignment5();
	assignment6();
	assignment7();
	assignment8();
	assignment9();
	assignment10();
	assignment11();
	assignment12();
	assignment13();
	assignment14();
	assignment15();

	return 0;
}

void assignment1()
{
	assignmentHeader(1);

	cout << "2.5" << endl << "5" << endl;

	enterToContinue();
}

void assignment2()
{
	assignmentHeader(2);

	string firstName, lastName = "";

	cout << "Your first name?: ";
	cin >> firstName;
	cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');

	cout << "Your last name?: ";
	cin >> lastName;
	cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');

	cout << "Hello " << firstName << " " << lastName
		<< " and welcome to the programing course!" << endl;

	enterToContinue();
}

void assignment3()
{
	assignmentHeader(3);
	
	string personalIdentityNr = "";
	float wight = 0;
	unsigned short age = 0;
	bool serchFound = 0;
	string streetAdress = "";
	unsigned int nrOfCars = 0;
	char answer = 0;

	cout << "string\nfloat\nunsigned short\nbool"
		<< "\nstring\nunsigned int\nchar" << endl;

	enterToContinue();
}

void assignment4()
{
	assignmentHeader(4);

	string text;

	cout << "Wright some text please: ";
	getline(cin, text);
	cout << "\nThat is a prompt" << endl;

	enterToContinue();
}

void assignment5()
{
	assignmentHeader(5);

	int nr = 5;

	cout << "The number is " << nr << endl;
	nr = 10;
	cout << "Now the number is " << nr << ", so yes!" << endl;

	enterToContinue();
}

void assignment6()
{
	assignmentHeader(6);

	cout << "No that is why it is a constant" << endl;

	enterToContinue();
}

void assignment7()
{
	assignmentHeader(7);

	cout << "Constants is named with ALLCAPS " 
		<< "with _ between words.\n"
		<< "While variables are named in lowercase " 
		<< "then the first letter in every " 
		<< "new word in uppercase" << endl;

	enterToContinue();
}

void assignment8()
{
	assignmentHeader(8);

	cout << "personalIdentityNr\nwight\nage\n" <<
		"serchFound\nstreetAdress\nnrOfCars\nanswer" << endl;

	enterToContinue();
}

void assignment9()
{
	string arranger, address, date, guest = "";
	float time = 0;
	unsigned int nrOfStars = 0;

	assignmentHeader(9);

	cout << "Welcome to the invitation program\n\n" <<
		"Name of the one that is arranger: ";
	getline(cin, arranger);

	cout << "Address for the event: ";
	getline(cin, address);

	cout << "Date of the event: ";
	getline(cin, date);

	cout << "Time of the event (hh.mm): ";
	cin >> time;
	cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');

	cout << "\n\nName of guest: ";
	getline(cin, guest);

	nrOfStars = (address.length() + date.length() + 44); //44 is the length of the rest sentence and time 
	printStars(nrOfStars);

	cout << setprecision(4) << fixed 
		<< showpoint << right;
	cout << "\nHello " << guest << "!\n\n"
		<< "You are invited to a party at "
		<< address << " the " << date << " at "
		<< time << "\n\nSincerely\n" << arranger 
		<< endl;
	
	printStars(nrOfStars);

	enterToContinue();
}

void assignment10()
{
	assignmentHeader(10);

	cout << "A pointer is a address to memory that points out a value" << endl;

	enterToContinue();
}

void assignment11()
{
	assignmentHeader(11);

	cout << "if, for, public, int" << endl;

	enterToContinue();
}

void assignment12()
{
	assignmentHeader(12);

	cout << "a) Lacking ;\n" 
		<< "b) == is not the same as \"=\"\n"
		<< "c) the sign has a space in between" << endl;

	enterToContinue();
}

void assignment13()
{
	assignmentHeader(13);

	int nr1, nr2, nr3 = 0;
	bool change = false;

	for (int i = 1; i <= 3; i++)
	{
		cout << "Enter a number: ";
		if (i == 1)
		{
			cin >> nr1;
		}
		else if (i == 2)
		{
			cin >> nr2;
		}
		else
		{
			cin >> nr3;
		}
		cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');
	}

	do
	{
		change = false;
		if (nr1 < nr2)
		{
			int temp = nr1;
			nr1 = nr2;
			nr2 = temp;
			change = true;
		}
		else if (nr2 < nr3)
		{
			int temp = nr1;
			nr1 = nr2;
			nr2 = temp;
			change = true;
		}
	} while (change);

	cout << nr1 << " is the biggest number followed by "
		<< nr2 << " and lastly " << nr3 << endl;

	enterToContinue();
}

void assignment14()
{
	assignmentHeader(14);

	string name1, name2 = "";
	unsigned short age1, age2 = 0;
	ofstream outputFile("InmatningUtmatningVariablerOchKonstanter.txt");
	
	cout << "Wright a name: ";
	getline(cin, name1);
	cout << "Wright a age: ";
	cin >> age1;
	cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');

	cout << "Wright a name: ";
	getline(cin, name2);
	cout << "Wright a age: ";
	cin >> age2;
	cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');

	outputFile << name1 << "\n" << age1 << "\n"
		<< name2 << "\n" << age2 << endl;
	outputFile.close();

	enterToContinue();
}

void assignment15()
{
	assignmentHeader(15);
	
	string name1, name2 = "";
	unsigned short age1, age2 = 0;
	ifstream inputFile("InmatningUtmatningVariablerOchKonstanter.txt");

	getline(inputFile, name1);
	inputFile >> age1;
	inputFile.ignore((std::numeric_limits<streamsize>::max)(), '\n');

	getline(inputFile, name2);
	inputFile >> age2;
	inputFile.ignore((std::numeric_limits<streamsize>::max)(), '\n');

	inputFile.close();

	cout << name1 << " is " << age1 << " old\n"
		<< name2 << " is " << age2 << " old" << endl;

	enterToContinue();
}
