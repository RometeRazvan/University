#pragma once

#include <vector>
#include <string>
#include <assert.h>

#include "Melodie.h"

class TableItem : public Melodie {
private:
	int nrAutor, nrGen;
public:
	TableItem(int id, string titlu, string artist, string gen, int nr1, int nr2) : Melodie(id, titlu, artist, gen), nrAutor{nr1}, nrGen{nr2} {}

	int getNrAutor() {
		return nrAutor;
	}

	int getNrGen() {
		return nrGen;
	}
};

class TestTableItem {
public:

	void testAllItem() {
		TableItem ta{ 1, "Tigru", "Razvan", "Pop", 2, 3 };

		assert(ta.getId() == 1);
		assert(ta.getArtist() == "Razvan");
		assert(ta.getTilu() == "Tigru");
		assert(ta.getGen() == "Pop");
		assert(ta.getNrAutor() == 2);
		assert(ta.getNrGen() == 3);
	}

};