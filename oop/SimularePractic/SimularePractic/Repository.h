#pragma once

#include <vector>
#include <string>
#include <fstream>

#include "Melodie.h"

using namespace std;

class Repository {
private:
	string fileName;
	vector<Melodie> repo;
public:

	const void writeToFile() {
		ofstream fout(fileName);

		for (auto& m : repo) {
			string id = to_string(m.getId());
			
			fout << id + ";" + m.getTilu() + ";" + m.getArtist() + ";" + m.getGen() + ";\n";
		}
	}

	const void loadFromTable() {
		ifstream fin(fileName);

		if (!fin.is_open())
			throw exception("Nu s-a putut deschide fisierul !!!");

		string tmp;
		vector<string> vec;
		string line;

		while (getline(fin, line)) {
			vec.clear();
			tmp = "";

			for (auto& c : line) {
				if (c != ';')
					tmp += c;
				else {
					vec.push_back(tmp);
					tmp = "";
				}
			}

			Melodie m{ stoi(vec.at(0)), vec.at(1), vec.at(2), vec.at(3) };

			repo.push_back(m);
		}
	}

	Repository(string fileName) : fileName{ fileName } {
		loadFromTable();
	}

	int getSize() {
		return repo.size();
	}

	Melodie getById(const int id) {
		for (vector<Melodie>::iterator it = repo.begin(); it != repo.end(); ++it) {
			Melodie m = *it;

			if (m.getId() == id)
				return m;
		}

		throw exception("Nu s-a gasit elementul !!!");
	}

	vector<Melodie>& getAll() {
		return repo;
	}

	void add(Melodie m) {
		repo.push_back(m);

		writeToFile();
	}

	void deleteById(int id) {
		for (int i = 0; i < repo.size(); ++i) {
			if (repo.at(i).getId() == id)
				repo.erase(repo.begin() + i);
		}

		writeToFile();
	}
};

class TestRepo {
public:

	void testAllRepo() {
		Repository repo{ "test.csv" };

		assert(repo.getSize() == 4);

		assert(repo.getById(1).getArtist() == "Razvan");
		assert(repo.getById(2).getArtist() == "Dragos");
		assert(repo.getById(3).getArtist() == "Iulius");
		assert(repo.getById(4).getArtist() == "Dan");
		try {
			repo.getById(10);
			assert(false);
		}
		catch (...) {
			assert(true);
		}

		assert(repo.getAll().size() == 4);

		repo.writeToFile();

		Melodie m1{ 5,"asd", "asd", "Pop" };

		repo.add(m1);

		assert(repo.getById(5).getArtist() == "asd");

		repo.deleteById(5);

		try {
			assert(repo.getById(5).getArtist() == "asd");
			assert(false);
		}
		catch (...) {
			assert(true);
		}
	}
};