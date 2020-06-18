#include <string>
#include <iostream>
#include <assert.h>
#include <vector>

#include "TestRepository.h"

using ::string;
using ::iostream;
using ::vector;

TestRepository::TestRepository() noexcept {}

Repository createReposioty() {

	Locatar l1{ "1", "Razvan", "25mp", "Decomandat" };
	Locatar l2{ "2", "Dragos", "26mp", "Open space" };
	Locatar l3{ "3", "Iulius", "27mp", "Balcon" };

	Repository repo{};

	repo.adaugaRepo(l1);
	repo.adaugaRepo(l2);
	repo.adaugaRepo(l3);

	return repo;

}

const void TestRepository::testAdaugare() {

	cout << "\nCopii adaugare :\n";

	Locatar l1{ "1", "Razvan", "25mp", "Decomandat" };
	Locatar l2{ "2", "Dragos", "26mp", "Open space" };
	Locatar l3{ "3", "Iulius", "27mp", "Balcon" };

	Repository repo{};

	repo.adaugaRepo(l1);
	repo.adaugaRepo(l2);
	repo.adaugaRepo(l3);

	assert(repo.getSize() == 3);

	assert(repo.get("Razvan").getApartament() == "1");
	assert(repo.get("Dragos").getApartament() == "2");
	assert(repo.get("Iulius").getApartament() == "3");

	try {
		repo.adaugaRepo(l1);
	} catch (const RepoException&) {
		assert(true);
	}

	try {
		repo.get("Dan");
	} catch (const RepoException& re) {
		assert(re.getMesaj() == "\nNu s-a gasit locatarul Dan\n");
	}

	for (IteratorList<Locatar> it = repo.begin(); it != repo.end(); ++it) {
		Locatar &l = *it;

		cout << l.getNume() << "\n";
	}

	cout << "\n";

}

const void TestRepository::testStergere() {

	cout << "\nCopii stergere:\n";

	Repository repo = createReposioty();

	repo.stergeRepo("Razvan");

	assert(repo.getSize() == 2);

	try {
		repo.stergeRepo("Razvan");
	} catch (const RepoException&) {
		assert(true);
	}

	cout << "\n";

}

const void TestRepository::testModificare() {

	cout << "\nCopii modifica:\n";

	Repository repo = createReposioty();

	Locatar l{ "10", "Dan", "26mp", "Decomandat" };

	repo.modificaRepo(l, "Razvan");

	try {
		repo.modificaRepo(l, "Razvan");
	} catch (const RepoException&) {
		assert(true);
	}

	assert(repo.get("Dan").getApartament() == "10");
	assert(repo.get("Dan").getSuprafata() == "26mp");
	assert(repo.get("Dan").getTip() == "Decomandat");

	cout << "\n";

}

const void TestRepository::testGetAll() {

	cout << "\nCopii getAll:\n";

	Repository repo = createReposioty();

	assert(repo.getByApartament("1").getNume() == "Razvan");

	try { repo.getByApartament("1234"); assert(false); }
	catch (const RepoException&) { assert(true); }

	assert(repo.getAll().size() == 3);
	assert(repo.getAllCopies().size() == 3);

	repo.begin();
	repo.end();

	cout << "\n";

}

const void TestRepository::testCos() {

	cout << "\nCopii cos:\n";

	Repository repo = createReposioty();

	Cos cos{};

	cos.adaugaCos(repo.get("Razvan"));
	cos.adaugaCos(repo.get("Iulius"));

	try { cos.adaugaCos(repo.get("Razvan")); assert(false); }
	catch (const RepoException&) { assert(true); }

	assert(cos.size() == 2);

	cos.golesteCos();

	assert(cos.size() == 0);

	cos.genereazaCos(3, repo);

	assert(cos.size() == 3);

	cos.golesteCos();

	try { cos.genereazaCos(10, repo); assert(false); }
	catch (const RepoException&) { assert(true); }

	try { repo.getById(1000); assert(false); }
	catch (const RepoException&) { assert(true); }

	cos.begin();
	cos.end();

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