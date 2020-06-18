#include <assert.h>
#include <string>
#include <iostream>

#include "Locatar.h"
#include "TestMyList.h"

using namespace std;

TestMyList::TestMyList() noexcept {}

const void TestMyList::testPush_back() {

	cout << "\nCopii push_back:\n";

	MyList<Locatar> myList{};

	Locatar l1{ "1", "Razvan", "25mp", "Decomandat" };
	Locatar l2{ "2", "Dragos", "26mp", "Open space" };
	Locatar l3{ "3", "Iulius", "27mp", "Balcon" };

	myList.push_back(l1);
	myList.push_back(l2);
	myList.push_back(l3);

	assert(myList.size() == 3);

	assert(myList.at(0).getNume() == "Razvan");
	assert(myList.at(1).getNume() == "Dragos");
	assert(myList.at(2).getNume() == "Iulius");

	try {
		myList.at(4); assert(false);
	}
	catch (const exception&) {
		assert(true);
	}

	cout << "\n";
}

const void TestMyList::testErase() {

	cout << "\nCopii erase:\n";

	MyList<Locatar> myList{};

	Locatar l1{ "1", "Razvan", "25mp", "Decomandat" };
	Locatar l2{ "2", "Dragos", "26mp", "Open space" };
	Locatar l3{ "3", "Iulius", "27mp", "Balcon" };

	myList.push_back(l1);
	myList.push_back(l2);
	myList.push_back(l3);

	myList.erase(1);

	assert(myList.size() == 2);

	assert(myList.at(0).getNume() == "Razvan");
	assert(myList.at(1).getNume() == "Iulius");

	myList.erase(0);

	assert(myList.at(0).getNume() == "Iulius");

	myList.erase(0);

	myList.push_back(l1);
	myList.push_back(l2);
	myList.push_back(l3);

	assert(myList.at(0).getNume() == "Razvan");
	assert(myList.at(1).getNume() == "Dragos");
	assert(myList.at(2).getNume() == "Iulius");

	myList.erase(2);

	assert(myList.size() == 2);

	myList.erase(1);

	MyList<Locatar> myList2 = myList;

	assert(myList2.size() == 1);

	cout << "\n";

}

const void TestMyList::testReplace() {

	cout << "\nCopii replace:\n";

	MyList<Locatar> myList{};

	Locatar l1{ "1", "Razvan", "25mp", "Decomandat" };
	Locatar l2{ "2", "Dragos", "26mp", "Open space" };
	Locatar l3{ "3", "Iulius", "27mp", "Balcon" };

	myList.push_back(l1);
	myList.push_back(l2);
	myList.push_back(l3);

	Locatar l4{ "4", "Dan", "28mp", "Mansarda" };

	myList.replace(1, l4);

	assert(myList.at(1).getNume() == "Dan");

	cout << "\n";

}

const void TestMyList::testAllMyList() {

	testPush_back();
	testErase();
	testReplace();

	cout << "Finalizare teste MyList";

}