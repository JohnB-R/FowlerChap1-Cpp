#pragma once

#include <string>
using namespace std;
class Movie
{
	string _title;
	int _priceCode;
	
public:

	static const int CHILDRENS = 2;
	static const int NEW_RELEASE = 1;
	static const int REGULAR = 0;
	
	Movie(string title, int priceCode);
	int getPriceCode();
	void setPriceCode(int arg);
	string getTitle();
};
