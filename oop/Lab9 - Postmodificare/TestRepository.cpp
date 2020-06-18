#include <string>
#include <iostream>
#include <assert.h>
#include <vector>

#include "TestRepository.h"
#include "IRepository.h"
#include "FileRepository.h"
#include "RandomRepository.h"
#include "Cos.h"

using ::string;
using ::iostream;
using ::vector;

TestRepository::TestRepository() noexcept {}

void regenerateRepo(IRepository* repo) {

	Locatar l1{ "1", "Razvan", "25mp", "Decomandat" };
	Locatar l2{ "2", "Dragos", "26mp", "Open space" };
	Locatar l3{ "3", "Iulius", "27mp", "Balcon" };

	repo->adaugaRepo(l1);
	repo->adaugaRepo(l2);
	repo->adaugaRepo(l3);
}

IRepository* createReposioty() {

	Locatar l1{ "1", "Razvan", "25mp", "Decomandat" };
	Locatar l2{ "2", "Dragos", "26mp", "Open space" };
	Locatar l3{ "3", "Iulius", "27mp", "Balcon" };

	IRepository* repo = new Repository();

	repo->adaugaRepo(l1);
	repo->adaugaRepo(l2);
	repo->adaugaRepo(l3);

	return repo;

}

IRepository* prob1Repo() {
	RandomRepository* repo = new RandomRepository(0);

	Locatar l1{ "1", "Razvan", "25mp", "Decomandat" };
	Locatar l2{ "2", "Dragos", "26mp", "Open space" };
	Locatar l3{ "3", "Iulius", "27mp", "Balcon" };

	repo->adaugaRepo(l1);
	repo->adaugaRepo(l2);
	repo->adaugaRepo(l3);

	repo->setProb(1);

	return repo;
}

IRepository* prob0Repo() {
	RandomRepository* repo = new RandomRepository(0);

	Locatar l1{ "1", "Razvan", "25mp", "Decomandat" };
	Locatar l2{ "2", "Dragos", "26mp", "Open space" };
	Locatar l3{ "3", "Iulius", "27mp", "Balcon" };

	repo->adaugaRepo(l1);
	repo->adaugaRepo(l2);
	repo->adaugaRepo(l3);

	return repo;
}

const void TestRepository::testAdaugare() {

	cout << "\nCopii adaugare :\n";

	Locatar l1{ "1", "Razvan", "25mp", "Decomandat" };
	Locatar l2{ "2", "Dragos", "26mp", "Open space" };
	Locatar l3{ "3", "Iulius", "27mp", "Balcon" };

	IRepository *repo = new Repository();

	repo->adaugaRepo(l1);
	repo->adaugaRepo(l2);
	repo->adaugaRepo(l3);

	assert(repo->getSize() == 3);

	assert(repo->get("Razvan").getApartament() == "1");
	assert(repo->get("Dragos").getApartament() == "2");
	assert(repo->get("Iulius").getApartament() == "3");

	try {
		repo->adaugaRepo(l1);
	} catch (const RepoException&) {
		assert(true);
	}

	try {
		repo->get("Dan");
	} catch (const RepoException& re) {
		assert(re.getMesaj() == "\nNu s-a gasit locatarul Dan\n");
	}

	for (IteratorList<Locatar> it = repo->begin(); it != repo->end(); ++it) {
		Locatar &l = *it;

		cout << l.getNume() << "\n";
	}

	IRepository* repo2 = new FileRepository("test.csv");

	assert(repo2->getSize() == 3);

	assert(repo2->get("Razvan").getApartament() == "1");
	assert(repo2->get("Dragos").getApartament() == "2");
	assert(repo2->get("Iulius").getApartament() == "3");

	try {repo2->adaugaRepo(l1);}
	catch (const RepoException&) {assert(true);}

	try {repo2->get("Dan");}
	catch (const RepoException& re) {assert(re.getMesaj() == "\nNu s-a gasit locatarul Dan\n");}

	IRepository* repo3 = new RandomRepository(1);

	try { repo3->adaugaRepo(l1); }
	catch (const RepoException&) { assert(true); }

	IRepository* repo4 = new RandomRepository(0);

	repo4->adaugaRepo(l1);
	repo4->adaugaRepo(l2);
	repo4->adaugaRepo(l3);

	assert(repo4->getSize() == 3);

	assert(repo4->get("Razvan").getApartament() == "1");
	assert(repo4->get("Dragos").getApartament() == "2");
	assert(repo4->get("Iulius").getApartament() == "3");

	try { repo4->adaugaRepo(l1); }
	catch (const RepoException&) { assert(true); }

	try { repo4->get("Dan"); }
	catch (const RepoException& re) { assert(re.getMesaj() == "\nNu s-a gasit locatarul Dan\n"); }


	cout << "\n";

}

const void TestRepository::testStergere() {

	cout << "\nCopii stergere:\n";

	IRepository* repo = createReposioty();

	repo->stergeRepo("Razvan");

	assert(repo->getSize() == 2);

	try {repo->stergeRepo("Razvan");} 
	catch (const RepoException&) {assert(true);}

	IRepository* repo2 = new FileRepository("test.csv");

	repo2->stergeRepo("Razvan");

	assert(repo2->getSize() == 2);

	try {repo2->stergeRepo("Razvan");}
	catch (const RepoException&) {assert(true);}

	repo2->stergeRepo("Iulius");
	repo2->stergeRepo("Dragos");

	regenerateRepo(repo2);

	IRepository* repo3 = new RandomRepository(1);
	IRepository* repo4 = new RandomRepository(0);

	repo3 = prob1Repo();
	repo4 = prob0Repo();

	try { repo3->stergeRepo("Razvan"); assert(false); }
	catch (const RepoException&) { assert(true); }

	repo4->stergeRepo("Razvan");

	assert(repo4->getSize() == 2);

	try { repo4->stergeRepo("Razvan"); }
	catch (const RepoException&) { assert(true); }

	cout << "\n";

}

const void TestRepository::testModificare() {

	cout << "\nCopii modifica:\n";

	IRepository* repo = createReposioty();

	Locatar l{ "10", "Dan", "26mp", "Decomandat" };

	repo->modificaRepo(l, "Razvan");

	try {repo->modificaRepo(l, "Razvan");} 
	catch (const RepoException&) {assert(true);}

	assert(repo->get("Dan").getApartament() == "10");
	assert(repo->get("Dan").getSuprafata() == "26mp");
	assert(repo->get("Dan").getTip() == "Decomandat");

	IRepository* repo2 = new FileRepository("test.csv");

	repo2->modificaRepo(l, "Razvan");

	try {repo2->modificaRepo(l, "Razvan");}
	catch (const RepoException&) {assert(true);}

	assert(repo2->get("Dan").getApartament() == "10");
	assert(repo2->get("Dan").getSuprafata() == "26mp");
	assert(repo2->get("Dan").getTip() == "Decomandat");

	repo2->stergeRepo("Dan");
	repo2->stergeRepo("Iulius");
	repo2->stergeRepo("Dragos");

	regenerateRepo(repo2);

	IRepository* repo3 = new RandomRepository(1);
	IRepository* repo4 = new RandomRepository(0);

	repo3 = prob1Repo();
	repo4 = prob0Repo();

	try { repo3->modificaRepo(l, "Razvan"); }
	catch (const RepoException&) { assert(true); }

	repo4->modificaRepo(l, "Razvan");

	try { repo4->modificaRepo(l, "Razvan"); }
	catch (const RepoException&) { assert(true); }

	assert(repo4->get("Dan").getApartament() == "10");
	assert(repo4->get("Dan").getSuprafata() == "26mp");
	assert(repo4->get("Dan").getTip() == "Decomandat");

	cout << "\n";

}

const void TestRepository::testGetAll() {

	cout << "\nCopii getAll:\n";

	IRepository* repo = createReposioty();

	assert(repo->getByApartament("1").getNume() == "Razvan");

	try { repo->getByApartament("1234"); assert(false); }
	catch (const RepoException&) { assert(true); }

	assert(repo->getAll().size() == 3);
	assert(repo->getAllCopies().size() == 3);

	repo->begin();
	repo->end();

	IRepository* repo2 = new FileRepository("test.csv");

	assert(repo2->getByApartament("1").getNume() == "Razvan");

	try { repo2->getByApartament("1234"); assert(false); }
	catch (const RepoException&) { assert(true); }

	assert(repo2->getAll().size() == 3);
	assert(repo2->getAllCopies().size() == 3);

	repo2->begin();
	repo2->end();

	IRepository* repo3 = new RandomRepository(1);
	IRepository* repo4 = new RandomRepository(0);

	repo3 = prob1Repo();
	repo4 = prob0Repo();

	assert(repo4->getByApartament("1").getNume() == "Razvan");

	try { repo4->getByApartament("1234"); assert(false); }
	catch (const RepoException&) { assert(true); }

	assert(repo4->getAll().size() == 3);
	assert(repo4->getAllCopies().size() == 3);

	repo4->begin();
	repo4->end();

	cout << "\n";

}

const void TestRepository::testCos() {

	cout << "\nCopii cos:\n";

	IRepository* repo = createReposioty();

	Cos cos{};

	cos.adaugaCos(repo->get("Razvan"));
	cos.adaugaCos(repo->get("Iulius"));

	try { cos.adaugaCos(repo->get("Razvan")); assert(false); }
	catch (const RepoException&) { assert(true); }

	assert(cos.size() == 2);

	cos.golesteCos();

	assert(cos.size() == 0);

	cos.genereazaCos(3, repo);

	assert(cos.size() == 3);

	cos.golesteCos();

	try { cos.genereazaCos(10, repo); assert(false); }
	catch (const RepoException&) { assert(true); }

	try { repo->getById(1000); assert(false); }
	catch (const RepoException&) { assert(true); }

	cos.begin();
	cos.end();
	cos.getCos();

	IRepository* repo2 = new FileRepository("test.csv");

	Cos cos2{};

	cos2.adaugaCos(repo2->get("Razvan"));
	cos2.adaugaCos(repo2->get("Iulius"));

	try { cos2.adaugaCos(repo2->get("Razvan")); assert(false); }
	catch (const RepoException&) { assert(true); }

	assert(cos2.size() == 2);

	cos2.golesteCos();

	assert(cos2.size() == 0);

	cos2.genereazaCos(3, repo2);

	assert(cos2.size() == 3);

	cos2.golesteCos();

	try { cos2.genereazaCos(10, repo2); assert(false); }
	catch (const RepoException&) { assert(true); }

	try { repo2->getById(1000); assert(false); }
	catch (const RepoException&) { assert(true); }

	cos2.begin();
	cos2.end();
	cos2.getCos();

	IRepository* repo3 = new RandomRepository(1);
	IRepository* repo4 = new RandomRepository(0);

	repo3 = prob1Repo();
	repo4 = prob0Repo();

	Cos cos3{};

	cos3.adaugaCos(repo4->get("Razvan"));
	cos3.adaugaCos(repo4->get("Iulius"));

	try { cos3.adaugaCos(repo4->get("Razvan")); assert(false); }
	catch (const RepoException&) { assert(true); }

	assert(cos3.size() == 2);

	cos3.golesteCos();

	assert(cos3.size() == 0);

	cos3.genereazaCos(3, repo4);

	assert(cos3.size() == 3);

	cos3.golesteCos();

	try { cos3.genereazaCos(10, repo4); assert(false); }
	catch (const RepoException&) { assert(true); }

	try { repo4->getById(1000); assert(false); }
	catch (const RepoException&) { assert(true); }

	cos3.begin();
	cos3.end();
	cos3.getCos();

	cout << "\n";

}

const void TestRepository::testAllRepository() {
	testAdaugare();
	testStergere();
	testModificare();
	testGetAll();
	testCos();

	cout << "Finalizare testAll Repository !!!\n";
}