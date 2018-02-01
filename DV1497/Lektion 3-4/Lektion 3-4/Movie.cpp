#include "Movie.h"


Movie::Movie(string title, unsigned short runtime)
{
	this->title = title;
	this->runtimeInMinutes = runtime;
}

string Movie::getTitle() const
{
	return this->title;
}

unsigned short Movie::getRuntime() const
{
	return this->runtimeInMinutes;
}

bool Movie::setTitle(string title)
{
	this->title = title;
	return true;
}

bool Movie::setRuntime(unsigned short runtime)
{
	this->runtimeInMinutes = runtime;
	return true;
}


Movie::~Movie()
{
}
