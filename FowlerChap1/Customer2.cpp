#include "StdAfx.h"
#include "Customer2.h"

Customer2::Customer2(string name) {
	_name = name;
}

void Customer2::addRental(Rental* arg) {
	_rentals.push_back(arg);
}

string Customer2::getName() {
	return _name;
}

string Customer2::statement() {
	double totalAmount = 0;
	int frequentRenterPoints = 0;
	string result = "Rental Record for " + getName() + "\n";

	for (vector <int>::size_type pos = 0; pos < _rentals.size(); pos++) {
		Rental* each = _rentals[pos];

		//determine amounts for each line
		double thisAmount = 0;
		switch (each->getMovie()->getPriceCode()) {
		case Movie::REGULAR:
			thisAmount += 2;
			if (each->getDaysRented() > 2)
				thisAmount += (each->getDaysRented() - 2) * 1.5;
			break;
		case Movie::NEW_RELEASE:
			thisAmount += each->getDaysRented() * 3;
			break;
		case Movie::CHILDRENS:
			thisAmount += 1.5;
			if (each->getDaysRented() > 3)
				thisAmount += (each->getDaysRented() - 3) * 1.5;
			break;
		}
		

		// add frequent renter points
		frequentRenterPoints++;
		// add bonus for a two day new release rental
		if ((each->getMovie()->getPriceCode() == Movie::NEW_RELEASE) && each->getDaysRented() > 1)
			frequentRenterPoints++;

		// show figures for this rental
		stringstream out;
		out << result << "\t" << each->getMovie()->getTitle() << "\t" << thisAmount << "\n";
		result = out.str();
		totalAmount += thisAmount;
	}

	// add footer lines
	stringstream out;
	out << result << "Amount owed is " << totalAmount << "\n" <<
		"You earned " << frequentRenterPoints << " frequent renter points";
	result = out.str();
	return result;
}

