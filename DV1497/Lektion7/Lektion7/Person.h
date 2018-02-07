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
	virtual string toString() const;
	virtual ~Person();
};