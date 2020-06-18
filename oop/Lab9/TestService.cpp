#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <map>
#include <stack>

#include "TestService.h"

using namespace std;

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

	serv.beginCos();
	serv.endCos();

	serv.beginRepo();
	serv.endRepo();

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

const void TestService::testMap() {

	cout << "\nCopii testMap:\n";

	Service serv{};

	serv.adaugareService("13", "Razvan", "25mp", "Balcon");
	serv.adaugareService("14", "Dragos", "26mp", "Open Space");
	serv.adaugareService("15", "Iulius", "27mp", "Balcon");
	serv.adaugareService("16", "Dan", "25mp", "Balcon");
	serv.adaugareService("17", "Andrei", "26mp", "Open Space");
	serv.adaugareService("18", "Vasile", "27mp", "Mansarda");

	map<string, int> myMap = serv.makeMap();

	assert(myMap["Balcon"] == 3);
	assert(myMap["Open Space"] == 2);
	assert(myMap["Mansarda"] == 1);

	cout << "\n";
}

const void  TestService::testCos() {

	cout << "\nCopii testCos:\n";

	Service serv = generateService();

	serv.adaugaCos("13");
	serv.adaugaCos("14");

	assert(serv.size() == 2);

	serv.golesteCos();

	assert(serv.size() == 0);

	serv.genereazaCos(3);

	assert(serv.size() == 3);

	serv.genereazaCos(3);

	assert(serv.size() == 3);

	cout << "\n";
}

const void TestService::testUndo() {
	
	cout << "\nCopii testUndo:\n";

	Service serv{};
	stack<unique_ptr<ActiuneUndo>> actiuniUndo;

	serv.adaugareService("13", "Razvan", "25mp", "Balcon");
	actiuniUndo.push(make_unique<UndoAdauga>("Razvan", serv));

	Locatar l1{ "20", "Dan", "26mp", "Balcon" };
	Locatar l2 = serv.get("Razvan");
	serv.modificareService(l1, "Razvan");
	actiuniUndo.push(make_unique<UndoModifica>(l2, "Dan", serv));

	serv.adaugareService("14", "Dragos", "26mp", "Decomandat");
	actiuniUndo.push(make_unique<UndoAdauga>("Dragos", serv));
	
	actiuniUndo.push(make_unique<UndoSterge>("20", "Dan", "26mp", "Balcon", serv));
	serv.stergereService("Dan");

	serv.adaugareService("15", "Iulius", "27mp", "Open Space");
	actiuniUndo.push(make_unique<UndoAdauga>("Iulius", serv));

	assert(serv.getLg() == 2);

	actiuniUndo.top()->doUndo(); actiuniUndo.pop();

	try { serv.get("Iulius"); assert(false); }
	catch (const RepoException&) { assert(true); }

	assert(serv.getLg() == 1);

	try { serv.get("Dan"); assert(false); }
	catch (const RepoException&) { assert(true); }
	actiuniUndo.top()->doUndo(); actiuniUndo.pop();
	serv.get("Dan");
	assert(serv.getLg() == 2);

	actiuniUndo.top()->doUndo(); actiuniUndo.pop();
	try { serv.get("Dragos"); assert(false); }
	catch (const RepoException&) { assert(true); }
	assert(serv.getLg() == 1);

	try { serv.get("Razvan"); assert(false); }
	catch (const RepoException&) { assert(true); }
	actiuniUndo.top()->doUndo(); actiuniUndo.pop();
	serv.get("Razvan");

	actiuniUndo.top()->doUndo(); actiuniUndo.pop();
	assert(serv.getLg() == 0);

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
	testUndo();

	cout << "Finalizare testAll Service !!!\n";
}