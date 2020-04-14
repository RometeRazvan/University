#include <string>
#include <vector>
#include <cassert>
#include <iostream>

#include "TestService.h"

using std::string;
using std::iostream;
using std::vector;

Service generateService() {
	Service serv{};

	serv.adaugareService("13", "Razvan", "25mp", "Balcon");
	serv.adaugareService("14", "Dragos", "26mp", "Decomandat");
	serv.adaugareService("15", "Iulius", "27mp", "Open Space");

	return serv;
}

TestService::TestService() noexcept {}

const void TestService::testAdaugaService() {

	cout << "\nCopii adugare: \n";

	Service serv{};

	serv.adaugareService("13", "Razvan", "25mp", "Balcon");
	serv.adaugareService("14", "Dragos", "26mp", "Decomandat");
	serv.adaugareService("15", "iulius", "27mp", "Open Space");

	assert( serv.getLg() == 3);

	cout << "\n";
}

const void TestService::testStergeService() {

	cout << "Copii stergere:\n";

	Service serv = generateService();

	serv.stergereService("Razvan");

	try {
		serv.get("Razvan");
	} catch (const RepoException&) {
		assert(true);
	}

	assert(serv.getLg() == 2);

	cout << "\n";

}

const void TestService::testModificareService() {

	cout << "\nCopii modificare:\n";

	Service serv = generateService();

	Locatar l{ "16", "Dan", "30mp", "Acoperis" };

	serv.modificareService(l, "Razvan");

	assert(serv.getLg() == 3);

	try {
		serv.get("Razvan");
	} catch (const RepoException&) {
		assert(true);
	}

	Locatar l2 = serv.get("Dan");

	assert(l2.getApartament() == "16");
	assert(l2.getNume() == "Dan");
	assert(l2.getSuprafata() == "30mp");
	assert(l2.getTip() == "Acoperis");

	cout << "\n";

}

const void TestService::testGetAll() {

	cout << "\nCopii getAll:\n";

	Service serv = generateService();

	assert(serv.getAll().size() == 3);
	assert(serv.getAllCopies().size() == 3);

	cout << "\n";

}

const void TestService::testFiltreaza() {

	cout << "\nCopii filtrare:\n";

	Service serv {};

	serv.adaugareService("13", "Razvan", "25mp", "Balcon");
	serv.adaugareService("14", "Dragos", "26mp", "Balcon");
	serv.adaugareService("15", "Iulius", "25mp", "Open Space");

	MyList<Locatar> vec = serv.filtreaza("suprafata", "25mp");

	assert(vec.size() == 2);

	assert(vec.at(0).getNume() == "Razvan");
	assert(vec.at(1).getNume() == "Iulius");

	vec = serv.filtreaza("tip", "Balcon");

	assert(vec.size() == 2);

	assert(vec.at(0).getNume() == "Razvan");
	assert(vec.at(1).getNume() == "Dragos");

	cout << "\n";

}

const void TestService::testSorteaza() {

	cout << "\nCopii sortare:\n";

	Service serv{};

	serv.adaugareService("13", "Razvan", "25mp", "Balcon");
	serv.adaugareService("14", "Dragos", "26mp", "Open Space");
	serv.adaugareService("15", "Iulius", "27mp", "Balcon");

	serv.sorteaza("nume"); 
	MyList<Locatar> vec = serv.getAll();

	assert(vec.at(0).getNume() == "Dragos");
	assert(vec.at(1).getNume() == "Iulius");
	assert(vec.at(2).getNume() == "Razvan");

	serv.sorteaza("suprafata"); vec = serv.getAll();

	assert(vec.at(0).getSuprafata() == "25mp");
	assert(vec.at(1).getSuprafata() == "26mp");
	assert(vec.at(2).getSuprafata() == "27mp");

	serv.sorteaza("tip + suprafata"); vec = serv.getAll();

	assert(vec.at(0).getTip() == "Balcon");
	assert(vec.at(1).getTip() == "Balcon");
	assert(vec.at(2).getTip() == "Open Space");

	cout << "\n";
 }

const void TestService::testAllService() {

	testAdaugaService();
	testStergeService();
	testModificareService();
	testGetAll();
	testFiltreaza();
	testSorteaza();

	cout << "Finalizare testAll Service !!!\n";
}