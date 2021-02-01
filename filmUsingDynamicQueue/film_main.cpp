#include <iostream>
#include <string>
#include "film.h"
#include "film_data.h"
#include "DynamicQueue.h"
#include <fstream>

using namespace std;

int main()
{
	ifstream filmInputFile("films.txt");
	ofstream outFile("lab3.out");

	DynamicQueue <Film> filmQueue;
	Film film;

	while (!filmInputFile.eof())
	{
		filmInputFile >> film;
		filmQueue.enqueue(film);
	}

	filmQueue.dequeue(film);
	filmQueue.dequeue(film);

	film.setFilmCode("F108");
	film.setFilmCategory(Drama);
	film.setFilmRating(PG);
	film.setFilmTitle("random");
	film.setFilmYear("2019");

	filmQueue.enqueue(film);

	film.setFilmCode("F109");
	film.setFilmCategory(Drama);
	film.setFilmRating(R);
	film.setFilmTitle("random123");
	film.setFilmYear("2020");

	filmQueue.enqueue(film);
	
	while (!filmQueue.isEmpty())
	{
		filmQueue.dequeue(film);
		cout << film;
		outFile << film;
	}
	



	cout << endl;
	
	system("pause");

	return 0;
}