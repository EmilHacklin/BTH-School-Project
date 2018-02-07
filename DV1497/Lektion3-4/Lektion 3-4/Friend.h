#pragma once
#include<string>

using namespace std;
// klassen ska beskriva en vän
class Friend
{
private: // sådant som inte är tillgängligt utifrån
	string name;
	int birthYear;
public: // sådant som är tillgängligt utfrån via ett objekt
	// konstruktorer skapar/bygger ett objekt, har samma namn som klassen
	//Friend(string name, int birthYear);
	//Friend(); // default konstrukton har tom parameterlista

	Friend(string name = "?", int birthYear = 0);

	// destruktor
	~Friend();


	// medlemsfunktion
	string getName() const; // en sk. get-funktion, const innebär att funktionen inta kan ändra objektet

	void setName(string name); // en sk. set-funktion
	void setBirthYear(int birthYear); //...
	int age(int year) const;
	// fler medlemsfunktioner
	string toString() const; // sätta samman namn och ålder till en "snygg" sträng som returneras

	// operatoröverlagring
	bool operator==(const Friend &other) const;

	// tillför operatorn < vilken ska baseras på endast födelseåret
	bool operator<(const Friend &other) const;

};