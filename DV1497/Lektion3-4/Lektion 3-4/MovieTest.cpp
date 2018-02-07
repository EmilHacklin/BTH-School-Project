#include<iostream>
#include<string>
#include"MovieHandler.h"

using namespace std;

int main()
{
	MovieHandler movieLibrary;
	string *titles;

	movieLibrary.addMovie("1", 53);
	movieLibrary.addMovie("2", 22);
	titles = movieLibrary.movieTitles();
	for (unsigned short i = 0; i < movieLibrary.getNumberOfMovies(); i++)
	{
		cout << titles[i] << endl;
	}
	delete[] titles;
	getchar();

	movieLibrary.deleteMovie("1");
	titles = movieLibrary.movieTitles();
	for (unsigned short i = 0; i < movieLibrary.getNumberOfMovies(); i++)
	{
		cout << titles[i] << endl;
	}
	delete[] titles;
	getchar();
	
	movieLibrary.addMovie("3", 22);
	movieLibrary.addMovie("4", 22);
	movieLibrary.addMovie("5", 22);
	movieLibrary.addMovie("6", 22);
	movieLibrary.addMovie("7", 22);
	movieLibrary.addMovie("8", 22);
	movieLibrary.addMovie("9", 22);
	movieLibrary.addMovie("10", 22);
	movieLibrary.addMovie("11", 22);
	movieLibrary.addMovie("12", 22);
	movieLibrary.deleteMovie(5);
	titles = movieLibrary.movieTitles();
	for (unsigned short i = 0; i < movieLibrary.getNumberOfMovies(); i++)
	{
		cout << titles[i] << endl;
	}
	delete[] titles;
	getchar();

	movieLibrary.addMovie("13", 22);
	movieLibrary.addMovie("expand", 22);
	titles = movieLibrary.movieTitles();
	for (unsigned short i = 0; i < movieLibrary.getNumberOfMovies(); i++)
	{
		cout << titles[i] << endl;
	}
	delete[] titles;
	getchar();
	return 0;
}