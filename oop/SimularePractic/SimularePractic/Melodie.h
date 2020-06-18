#pragma once

#include <string>
#include <assert.h>

using namespace std;

class Melodie {
private:
	int id;
	string titlu, artist, gen;
public:

	Melodie(int id, string titlu, string artist, string gen) : id{id}, titlu{titlu}, artist{artist}, gen{gen} {}

	int getId() {
		return id;
	}

	string getTilu() {
		return titlu;
	}

	string getArtist() {
		return artist;
	}

	string getGen() {
		return gen;
	}
};

class TestMelodie {

public:

	void testAllMelodie() {

		Melodie m1{ 1, "Elefant", "Razvan", "Pop" };

		assert(m1.getId() == 1);
		assert(m1.getTilu() == "Elefant");
		assert(m1.getArtist() == "Razvan");
		assert(m1.getGen() == "Pop");

	}
};