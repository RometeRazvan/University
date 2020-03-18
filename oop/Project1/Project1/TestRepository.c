#include "TestRepository.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>


Lista generateLista() {
	Lista l = newLista();

	Masina m1 = { .nrI = "VS 11 TRM", .model = "2011", .categ = "Duster1" };
	Masina m2 = { .nrI = "VS 12 TRM", .model = "2012", .categ = "Duster2" };
	Masina m3 = { .nrI = "VS 13 TRM", .model = "2013", .categ = "Duster3" };
	Masina m4 = { .nrI = "VS 14 TRM", .model = "2014", .categ = "Duster4" };

	adaugaR(&l, m1);
	adaugaR(&l, m2);
	adaugaR(&l, m3);
	adaugaR(&l, m4);

	return l;
}

void testCreateLista() {
	Lista l = newLista();

	assert(getLg(l) == 0);
}

void testAdauga() {

	Masina m = { .nrI = "", .model = "", .categ = "" };

	Masina m1 = { .nrI = "VS 11 TRM", .model = "2011", .categ = "Duster1" };
	Masina m2 = { .nrI = "VS 12 TRM", .model = "2012", .categ = "Duster2" };
	Masina m3 = { .nrI = "VS 13 TRM", .model = "2013", .categ = "Duster3" };
	Masina m4 = { .nrI = "VS 14 TRM", .model = "2014", .categ = "Duster4" };

	Lista l = newLista();

	adaugaR(&l, m1);
	assert(getLg(l) == 1);

	m = getR(l, 0);
	assert(strcmp(getModel(m), "2011") == 0);

	adaugaR(&l, m2);
	assert(getLg(l) == 2);

	m = getR(l, 1);
	assert(strcmp(getModel(m), "2012") == 0);

	adaugaR(&l, m3);
	assert(getLg(l) == 3);

	m = getR(l, 2);
	assert(strcmp(getModel(m), "2013") == 0);

	adaugaR(&l, m4);
	assert(getLg(l) == 4);

	m = getR(l, 3);
	assert(strcmp(getModel(m), "2014") == 0);
}

void testCopy() {

	Lista l = generateLista();

	Lista nl = copyLista(l);

	assert(getLg(nl) == 4);

	assert(strcmp(getModel(getR(nl, 0)), "2011") == 0);
	assert(strcmp(getModel(getR(nl, 1)), "2012") == 0);
	assert(strcmp(getModel(getR(nl, 2)), "2013") == 0);
	assert(strcmp(getModel(getR(nl, 3)), "2014") == 0);

}

void testSterge() {

	Masina m = { .nrI = "", .model = "", .categ = "" };

	Lista l = generateLista();

	m = stergeR(&l, 2);

	assert(strcmp(getModel(m), "2013") == 0);
	assert(getLg(l) == 3);

	stergeR(&l, 0);
	stergeR(&l, 0);
	stergeR(&l, 0);

	assert(getLg(l) == 0);
}

void testModifica() {

	Masina m = newMasina("VS 15 TRM", "2015", "Duster5");

	Lista l = generateLista();

	modificaR(&l, 3, m);

	m = getR(l, 3);

	assert(strcmp(getModel(m), "2015") == 0);
}

void testRepositoryAll() {

	testCreateLista();
	testAdauga();
	testCopy();
	testSterge();
	testModifica();

	printf("Finalizare testeRepositoryAll !\n");
}