#pragma once
#include<string>

using namespace std;

class Movie
{
private:
	string title;
	unsigned short runtimeInMinutes;
public:
	Movie(string title = "", unsigned short runtime = 0);
	string getTitle() const;
	unsigned short getRuntime() const;
	bool setTitle(string title);
	bool setRuntime(unsigned short runtime);
	~Movie();
};

