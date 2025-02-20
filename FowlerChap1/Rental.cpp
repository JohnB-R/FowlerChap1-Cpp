#include "StdAfx.h"
#include "Rental.h"

Rental::Rental(Movie *movie, int daysRented) {
	_movie = movie;
	_daysRented = daysRented;
}

int Rental::getDaysRented() {
	return _daysRented;
}

Movie* Rental::getMovie() {
	return _movie;
}
