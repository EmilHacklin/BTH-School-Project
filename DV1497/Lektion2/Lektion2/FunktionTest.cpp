#include<iostream>
#include<string>

using namespace std;

//Funktionsprototyper/funktionsdeklarationer

void userInputToArray(string arr[], int arrCap, int &nrOf); 
/*arrCap is a value parameter and will countain a copy of the argument.
nrOf is a refrence parameter and will be a alias to the argument.*/

int find(string arr[], string toFind, int arrCap); 
/* Serch string toFind in the array arr and return the position/index
,if toFind dose not exist return -1.*/

int posOfSmallest(string arr[], int nrOf);
/*Return the position of the smalest string (alfabetical order),-1 if nrOf is 0.
Srings can be compaird with < and >*/

void swapContent(string &first, string &second);
/*swaps the content of the strings*/

/*Överlagring/overloading
Multiple functions with diffrent parameter lists, depended on data type , number and the order (int, string) (string, int)
ex.*/
void add(int first, int second); //add two integers and displays the awnser
void add(string first, string second); // add two strings and displays the result
void add(int first, int second, int third); //...
void add(int nuOf, string aWord); // aWord gets added togheter nuOf times

/*default argument, a value for the parameter that will be used if the parameter is left blank
must be given from right to left in the parameterlist*/
void show(string what = "?", int nrOfTimes = 5);

const int CAP = 10; //Capacity for the capitals list

int main()
{
	string capitals[CAP]; //String array of size CAP
	int capacity = 5;
	string *countries = new string[capacity]; //Pointer to array of size capacity
	int nrOfCapitals = 0;
	int nrOfCountries = 0;

	cout << "Capitals to be added" << endl;
	userInputToArray(capitals, CAP, nrOfCapitals);
	cout << "The number of capitals added is " << nrOfCapitals << endl;

	cout << "Countries to be added" << endl;
	userInputToArray(countries, capacity, nrOfCountries);
	cout << "The number of countries added is " << nrOfCountries << endl;

	delete[] countries;
	getchar();
	return 0;
}

/*The user inputs strings and ends the program by inputing "?".
Strings are placed in the array in the order they are typed.*/
void userInputToArray(string arr[], int arrCap, int & nrOf)
{
	cout << "Input and exit with \"?\"" << endl;
	getline(cin, arr[nrOf]);
	while (arr[nrOf] != "?" && nrOf < arrCap-1) // strings can be compaird with !=, ==, >, etc
	{
		nrOf++;
		getline(cin, arr[nrOf]);
	}
	if (nrOf == arrCap - 1) // if nrOf == arrCap -1 then the list is full
	{
		nrOf++;
	}
}

int find(string arr[], string toFind, int arrCap)
{
	for (int i = 0; i < arrCap, i++;)
	{
		if (arr[i] == toFind)
		{
			return i;
		}
	}
	return -1;
}

int posOfSmallest(string arr[], int nrOf)
{
	if (nrOf == 0)
	{
		return -1;
	}
	else
	{
		int pos;
		for (int i = 0; i < nrOf, i++;)
		{

		}
	}
}

void swapContent(string & first, string & second)
{
	string temp;
	temp = first;
	first = second;
	second = temp;
}

void add(int first, int second)
{
	cout << first + second << endl;
}

void add(string first, string second)
{
	cout << first << second << endl;
}

void add(int first, int second, int third)
{
	cout << first + second + third << endl;
}

void add(int nuOf, string aWord)
{
	for (int i = 0; i < nuOf, i++;)
	{
		cout << aWord;
	}
	cout << endl;
}

void show(string what, int nrOfTimes)
{
	for (int i = 0; i < nrOfTimes, i++;)
	{
		cout << what;
	}
}