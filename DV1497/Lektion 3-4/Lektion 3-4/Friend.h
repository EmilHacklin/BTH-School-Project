#pragma once
#include<string>

using namespace std;
// klassen ska beskriva en v�n
class Friend
{
private: // s�dant som inte �r tillg�ngligt utifr�n
	string name;
	int birthYear;
public: // s�dant som �r tillg�ngligt utfr�n via ett objekt
	// konstruktorer skapar/bygger ett objekt, har samma namn som klassen
	//Friend(string name, int birthYear);
	//Friend(); // default konstrukton har tom parameterlista

	Friend(string name = "?", int birthYear = 0);

	// destruktor
	~Friend();


	// medlemsfunktion
	string getName() const; // en sk. get-funktion, const inneb�r att funktionen inta kan �ndra objektet

	void setName(string name); // en sk. set-funktion
	void setBirthYear(int birthYear); //...
	int age(int year) const;
	// fler medlemsfunktioner
	string toString() const; // s�tta samman namn och �lder till en "snygg" str�ng som returneras

	// operator�verlagring
	bool operator==(const Friend &other) const;

	// tillf�r operatorn < vilken ska baseras p� endast f�delse�ret
	bool operator<(const Friend &other) const;

};