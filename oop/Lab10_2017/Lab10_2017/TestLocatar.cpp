#include <string>
#include <iostream>
#include <assert.h>

#include "TestLocatar.h"

using std::string;
using std::cout;

TestLocatar::TestLocatar() noexcept {}

const void TestLocatar::testCreateAndGetters() {

	Locatar l{ "13", "Razvan", "25mp", "open space" };

	assert(l.getApartament() == "13");
	assert(l.getNume() == "Razvan");
	assert(l.getSuprafata() == "25mp");
	assert(l.getTip() == "open space");

	Locatar l2{ l };

}

const void TestLocatar::testAllLocatar() {
	testCreateAndGetters();

	cout << "Finalizare teste Locatar !!!\n";
}