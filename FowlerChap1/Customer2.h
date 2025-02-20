#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "Rental.h"

using namespace std;

//From book: 'Refactoring' by Martin Fowler
//This is the original code before refactoring begins

class Customer2
{
	string _name;
	vector<Rental *> _rentals;

public:
	Customer2(string name);
	void addRental(Rental* arg);
	string getName();
	void calcAmount(Rental* each, double& thisAmount);
	string statement();
};
