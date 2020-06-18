#pragma once

#include<string>
#include <vector>

#include "Participant.h"

using namespace std;

class Repository {

private:

	string fileName;
	vector<Participant> repo;

public:

	Repository(string fileName) : fileName{ fileName } {
		loadFromFile();
	}

	void loadFromFile();

	void writeToFile();

	void adaugaRepo(Participant participant);

	void modificaRepo(string nume, Participant participant);

	void stergeRepo(string nume);

	Participant get(string nume);

	vector<Participant> getAll();

};

class TestRepository {
public:

	void testAllRepo() {
		Repository repo{ "test.txt" };

		assert(repo.getAll().size() == 3);
		
		Participant part{ "George", "Maestru", "2400" };

		repo.adaugaRepo(part);

		repo.get("George");

		assert(repo.getAll().size() == 4);

		repo.stergeRepo("George");

		assert(repo.getAll().size() == 3);
		
		repo.writeToFile();

		try { repo.get("George"); }
		catch (...) { assert(true); }


		repo.modificaRepo("Razvan", part);

		repo.get("George");
		try { repo.get("George"); }
		catch (...) { assert(true); }

		Participant part2{ "George", "Maestru", "2300" };

		try {
			repo.adaugaRepo(part2);
		}
		catch (...) { assert(true); }
	}
};