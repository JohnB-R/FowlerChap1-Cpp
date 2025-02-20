#include "StdAfx.h"
#include "Movie.h"

Movie::Movie(string title, int priceCode) {
	_title = title;
	_priceCode = priceCode;
}

int Movie::getPriceCode() {
	return _priceCode;
}

void Movie::setPriceCode(int arg) {
	_priceCode = arg;
}

string Movie::getTitle() {
	return _title;
}

