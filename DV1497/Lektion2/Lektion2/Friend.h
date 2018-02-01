#pragma once
#include<string>

using namespace std;
//The class shall describe a friend
class Friend
{
private: //Things that is not accesible outside of the class
	string name;
	int birthYear;
public: //Things that is accesible outside of the class
	//Constructors creates/builds a object, must have the same name as the class
	Friend(string name, int birthYear);
	Friend(); //Deafult constructor always hav empty list of parameters
	//Memberfunctions
	string getName(); //Return the name
	int getBirthYear(); //Return the birthYear
	void setName(string name); // A set function
	void setBirthYear(int birthYear); // ...
	string toString(); //Combining name and birthYear to a string that gets returned
};