#pragma once

#include "Customer2.h"
#include "Movie.h"
#include "Rental.h"

class CustomerTest
{
public:
	void assertEquals(string a, string b);

	void testStatementForRegularMovie();
	void testStatementForNewReleaseMovie();
	void testStatementForChildrensMovie();
	void testStatementForManyMovies();
};
