#include "MovieHandler.h"



void MovieHandler::expandArray()
{
	Movie* tempArray = new Movie[(this->capacity+10)];
	for (unsigned short i = 0; i < this->capacity; i++)
	{
		tempArray[i].setTitle(this->movies[i].getTitle());
		tempArray[i].setRuntime(this->movies[i].getRuntime());
	}
	delete[] this->movies;
	this->movies = tempArray;
}

short MovieHandler::searchMovie(string title)
{
	bool found = false;
	unsigned short index = 0;

	while (!found && index < this->nrOfMovies)
	{
		if (this->movies[index].getTitle() == title)
		{
			found = true;
		}
		else
		{
			index++;
		}
	}

	if (found)
	{
		return index;
	}
	else
	{
		return -1;
	}
}

MovieHandler::MovieHandler()
{
	this->capacity = 10;
	this->movies = new Movie[this->capacity];
	this->nrOfMovies = 0;
}

bool MovieHandler::addMovie(string title, unsigned short runtime)
{
	if (this->nrOfMovies == this->capacity)
	{
		this->expandArray();
	}
	if (!this->movies[this->nrOfMovies].setTitle(title))
	{
		return false;
	}
	else if (!this->movies[this->nrOfMovies].setRuntime(runtime))
	{
		this->movies[this->nrOfMovies].setTitle("");
		return false;
	}
	else
	{
		this->nrOfMovies++;
		return true;
	}
}

string* MovieHandler::movieTitles() const
{
	string *titles = new string[this->nrOfMovies];

	for (unsigned short i = 0; i < this->nrOfMovies; i++)
	{
		titles[i] = this->movies[i].getTitle();
		titles[i] += ": runtime of ";
		titles[i] += to_string(this->movies[i].getRuntime());
		titles[i] += " minutes";
	}

	return titles;
}

unsigned short MovieHandler::getNumberOfMovies() const
{
	return this->nrOfMovies;
}

bool MovieHandler::deleteMovie(string title)
{
	short index = this->searchMovie(title);

	if (index >= 0)
	{
		this->nrOfMovies--;
		this->movies[index].setTitle(this->movies[this->nrOfMovies].getTitle());
		this->movies[index].setRuntime(this->movies[this->nrOfMovies].getRuntime());
		this->movies[this->nrOfMovies].setTitle("");
		this->movies[this->nrOfMovies].setRuntime(0);
		return true;
	}
	else
	{
		return false;
	}

}

bool MovieHandler::deleteMovie(unsigned short index)
{
	if (index < this->nrOfMovies)
	{
		this->nrOfMovies--;
		this->movies[index].setTitle(this->movies[nrOfMovies].getTitle());
		this->movies[index].setRuntime(this->movies[nrOfMovies].getRuntime());
		this->movies[nrOfMovies].setTitle("");
		this->movies[nrOfMovies].setRuntime(0);
		return true;
	}
	else
	{
		return false;
	}

}


MovieHandler::~MovieHandler()
{
	delete[] this->movies;
}
