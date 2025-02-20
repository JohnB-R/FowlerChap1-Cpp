#include "StdAfx.h"
#include "CustomerTest.h"

void CustomerTest::assertEquals(string a, string b) {
	if (a == b) {
		cout << "y" << endl;
	} else {
		cout << "n" << endl;
		cout << "Expected <" << a << ">, but got <" << b << ">." << endl;
	}
}

void CustomerTest::testStatementForRegularMovie() {
	Customer2* pCustomer2 = new Customer2("Sallie");
	Movie* pMovie1 = new Movie("Gone with the Wind", Movie::REGULAR);
	Rental* pRental1 = new Rental(pMovie1, 3); // 3 day rental
	pCustomer2->addRental(pRental1);
	string expected = "Rental Record for Sallie\n\tGone with the Wind\t3.5\nAmount owed is 3.5\nYou earned 1 frequent renter points";
	string statement = pCustomer2->statement();
	assertEquals(expected, statement);
}

void CustomerTest::testStatementForNewReleaseMovie() {
	Customer2* pCustomer2 = new Customer2("Sallie");
	Movie* pMovie1 = new Movie("Star Wars", Movie::NEW_RELEASE);
	Rental* pRental1 = new Rental(pMovie1, 3); // 3 day rental
	pCustomer2->addRental(pRental1);
	string expected = "Rental Record for Sallie\n\tStar Wars\t9\nAmount owed is 9\nYou earned 2 frequent renter points";
	string statement = pCustomer2->statement();
	assertEquals(expected, statement);
}

void CustomerTest::testStatementForChildrensMovie() {
	Customer2* pCustomer2 = new Customer2("Sallie");
	Movie* pMovie1 = new Movie("Madagascar", Movie::CHILDRENS);
	Rental* pRental1 = new Rental(pMovie1, 3); // 3 day rental
	pCustomer2->addRental(pRental1);
	string expected = "Rental Record for Sallie\n\tMadagascar\t1.5\nAmount owed is 1.5\nYou earned 1 frequent renter points";
	string statement = pCustomer2->statement();
	assertEquals(expected, statement);
}

void CustomerTest::testStatementForManyMovies() {
	Customer2* pCustomer1 = new Customer2("David");
	Movie* pMovie1 = new Movie("Madagascar", Movie::CHILDRENS);
	Rental* pRental1 = new Rental(pMovie1, 6); // 6 day rental
	Movie* pMovie2 = new Movie("Star Wars", Movie::NEW_RELEASE);
	Rental* pRental2 = new Rental(pMovie2, 2); // 2 day rental
	Movie* pMovie3 = new Movie("Gone with the Wind", Movie::REGULAR);
	Rental* pRental3 = new Rental(pMovie3, 8); // 8 day rental
	pCustomer1->addRental(pRental1);
	pCustomer1->addRental(pRental2);
	pCustomer1->addRental(pRental3);
	string expected = "Rental Record for David\n\tMadagascar\t6\n\tStar Wars\t6\n\tGone with the Wind\t11\nAmount owed is 23\nYou earned 4 frequent renter points";
	string statement = pCustomer1->statement();
	assertEquals(expected, statement);
}

int main() {
	CustomerTest* ptest = new CustomerTest();
	
	ptest->testStatementForRegularMovie();
	ptest->testStatementForNewReleaseMovie();
	ptest->testStatementForChildrensMovie();
	ptest->testStatementForManyMovies();

	//char ch;
	//cin.get(ch);
}