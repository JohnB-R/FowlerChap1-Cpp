#pragma once
#include <string>
#include "Movie.h"

using namespace std;

/**
 * The rental class represents a customer renting a movie.
 */
class Rental
{
	Movie* _movie;
	int _daysRented;
	
public:
	Rental(Movie *movie, int daysRented);
	int getDaysRented();
	Movie* getMovie();
};
