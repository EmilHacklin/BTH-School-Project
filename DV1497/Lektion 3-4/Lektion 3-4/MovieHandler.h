#pragma once
#include<string>
#include "Movie.h"

using namespace std;

class MovieHandler
{
private:
	unsigned short capacity;
	Movie* movies;
	unsigned short nrOfMovies;
	void expandArray();
	short searchMovie(string title);
public:
	MovieHandler();
	bool addMovie(string title, unsigned short runtime);
	string* movieTitles() const;
	unsigned short getNumberOfMovies() const;
	bool deleteMovie(string title);
	bool deleteMovie(unsigned short index);
	~MovieHandler();
};

