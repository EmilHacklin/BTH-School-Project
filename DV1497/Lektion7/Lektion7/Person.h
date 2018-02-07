#pragma once
#include<iostream>
#include<string>

using namespace std;

class Person
{
private:
	string name;
	string email;
public:
	Person(string name = "?", string email = "?");
	string getName() const;
	string toString() const;
	virtual string toStringSpec() const = 0;
	virtual ~Person();
};