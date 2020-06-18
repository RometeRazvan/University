#pragma once

#include <vector>
#include <string>
#include <assert.h>

#include "Repository.h"

class Service {
private:
	Repository repo;
public:

	Service(Repository repo) : repo{ repo } {}

	vector<Melodie>& getAll() {
		return repo.getAll();
	}

	Melodie getById(const int id) {
		return repo.getById(id);
	}

	int getSize() {
		return repo.getSize();
	}

	int getNrArtist(string artist) {
		int i = 0;

		for (auto& m : repo.getAll()) {
			if (m.getArtist() == artist)
				++i;
		}

		return i;
	}

	int getNrGen(string gen) {
		int i = 0;

		for (auto& m : repo.getAll()) {
			if (m.getGen() == gen)
				++i;
		}

		return i;
	}

	int getMaxId() {
		int max = 0;

		for (auto& m : repo.getAll()) {
			if (m.getId() > max)
				max = m.getId();
		}

		return max;
	}

	bool add(string titlu, string artist, string gen) {
		if (gen != "Pop" && gen != "Rock" && gen != "Folk" && gen != "Disco")
			return false;
		
		Melodie m{ getMaxId() + 1, titlu, artist, gen };

		repo.add(m);

		return true;
	}

	void deleteById(int id) {
		repo.deleteById(id);
	}
};

class TestServiec {
public:
	void TestAllServiec() {
		Repository repo{ "test.csv" };

		Service serv{ repo };

		assert(serv.getAll().size() == 4);
		
		assert(serv.getSize() == 4);

		assert(serv.getById(1).getArtist() == "Razvan");
		try {
			serv.getById(10); assert(false);
		}
		catch (...) { assert(true); }

		assert(serv.getNrArtist("Razvan") == 1);
		assert(serv.getNrGen("Pop") == 2);

		assert(serv.add("asd", "Asd", "sad") == false);
		assert(serv.add("asd", "Asd", "Pop") == true);

		serv.deleteById(serv.getMaxId());

		assert(serv.getSize() == 4);
	}
};