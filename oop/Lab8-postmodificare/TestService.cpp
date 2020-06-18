#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <map>

#include "TestService.h"

using namespace std;

Service generateService() {
	Service serv{};

	serv.adaugareService("13", "Razvan", "25mp", "Balcon");
	serv.adaugareService("14", "Dragos", "26mp", "Decomandat");
	serv.adaugareService("15", "Iulius", "27mp", "Open Space");

	assert(serv.getLg() == 3);

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

	serv.beginCos();
	serv.endCos();

	serv.beginRepo();
	serv.endRepo();

	cout << "\n";

}

const void TestService::testFiltreaza() {

	cout << "\nCopii filtrare:\n";

	Service serv {};

	serv.adaugareService("14", "Dragos", "26mp", "Balcon");
	serv.adaugareService("13", "Razvan", "25mp", "Balcon");
	serv.adaugareService("15", "Iulius", "25mp", "Open Space");

	MyList<Locatar> vec = serv.filtreaza("suprafata", "25mp");

	assert(vec.size() == 2);

	assert(vec.at(0).getNume() == "Iulius");
	assert(vec.at(1).getNume() == "Razvan");

	vec = serv.filtreaza("tip", "Balcon");

	assert(vec.size() == 2);

	assert(vec.at(0).getNume() == "Dragos");
	assert(vec.at(1).getNume() == "Razvan");

	cout << "\n";

}

const void TestService::testSorteaza() {

	cout << "\nCopii sortare:\n";

	Service serv{};

	serv.adaugareService("13", "Razvan", "25mp", "Balcon");
	serv.adaugareService("14", "Dragos", "26mp", "Open Space");
	serv.adaugareService("15", "Iulius", "27mp", "Balcon");

	serv.sorteaza("nume"); 
	MyList<Locatar> vec = serv.getList();

	assert(vec.at(0).getNume() == "Dragos");
	assert(vec.at(1).getNume() == "Iulius");
	assert(vec.at(2).getNume() == "Razvan");

	serv.sorteaza("suprafata"); vec = serv.getList();

	assert(vec.at(0).getSuprafata() == "25mp");
	assert(vec.at(1).getSuprafata() == "26mp");
	assert(vec.at(2).getSuprafata() == "27mp");

	serv.sorteaza("tip + suprafata"); vec = serv.getList();

	assert(vec.at(0).getTip() == "Balcon");
	assert(vec.at(1).getTip() == "Balcon");
	assert(vec.at(2).getTip() == "Open Space");

	cout << "\n";
 }

const void TestService::testMap() {

	cout << "\nCopii testMap:\n";

	Service serv{};

	serv.adaugareService("13", "Razvan", "25mp", "Balcon");
	serv.adaugareService("14", "Dragos", "26mp", "Open Space");
	serv.adaugareService("15", "Iulius", "27mp", "Balcon");
	serv.adaugareService("16", "Dan", "25mp", "Balcon");
	serv.adaugareService("17", "Andrei", "26mp", "Open Space");
	serv.adaugareService("18", "Vasile", "27mp", "Mansarda");

	vector<pair<string, int>> myMap = serv.makeMap();

	assert(myMap.at(0).second == 3);
	assert(myMap.at(1).second == 1);
	assert(myMap.at(2).second == 2);

	cout << "\n";
}

const void  TestService::testCos() {

	cout << "\nCopii testCos:\n";
	
	Service serv = generateService();

	serv.adaugaCos("13");
	serv.adaugaCos("15");

	assert(serv.size() == 2);

	serv.golesteCos();

	assert(serv.size() == 0);

	serv.genereazaCos(3);

	assert(serv.size() == 3);

	serv.genereazaCos(3);

	assert(serv.size() == 3);

	cout << "\n";
}

const void TestService::testAllService() {

	testAdaugaService();
	testStergeService();
	testModificareService();
	testGetAll();
	testFiltreaza();
	testSorteaza();
	testMap();
	testCos();

	cout << "Finalizare testAll Service !!!\n";
}