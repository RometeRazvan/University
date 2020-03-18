#include "TestRepository.h"
#include "Repository.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

Lista* generateList() {
	Masina* m1 = newMasina("CJ 07 TRM", "2010", "SUV");
	Masina* m2 = newMasina("CJ 08 TRM", "2011", "MINI");
	Masina* m3 = newMasina("CJ 09 TRM", "2012", "GOLF");
	Masina* m4 = newMasina("CJ 20 TRM", "2013", "MARE");
	Lista* l = newLista(distructorMasina);
	adaugareMasinaR(l, m1);
	adaugareMasinaR(l, m2);
	adaugareMasinaR(l, m3);
	adaugareMasinaR(l, m4);
	return l;
}

void testLista() {
	Lista* l = newLista(distructorMasina);

	assert(getCapac(l) == 2);
	assert(getLg(l) == 0);

	distructorLista(l);
}

void testAdd() {
	Masina* m1 = newMasina("CJ 07 TRM", "2010", "SUV");
	Masina* m2 = newMasina("CJ 08 TRM", "2011", "MINI");
	Masina* m3 = newMasina("CJ 09 TRM", "2012", "GOLF");
	Masina* m4 = newMasina("CJ 20 TRM", "2013", "MARE");

	Lista *l = newLista(distructorMasina);

	adaugareMasinaR(l, m1);
	adaugareMasinaR(l, m2);

	assert(getLg(l) == 2);

	adaugareMasinaR(l, m3);
	adaugareMasinaR(l, m4);

	assert(getLg(l) == 4);
	assert(getCapac(l) == 4);

	distructorLista(l);
}
void testDelete() {

	Lista* l = generateList();

	Masina* m = stergeMasinaR(l, 2);

	assert(strcmp(getModel(m), "2012") == 0);
	assert(getLg(l) == 3);

	assert(strcmp(getModel(getMasinaR(l,0)), "2010") == 0);
	assert(strcmp(getModel(getMasinaR(l,1)), "2011") == 0);
	assert(strcmp(getModel(getMasinaR(l,2)), "2013") == 0);

	stergeMasinaR(l, 10);

	distructorMasina(m);
	distructorLista(l);

}
void testUpdate() {

	Lista* l = generateList();

	Masina* m = newMasina("CJ 21 TRM", "2014", "SIMAIMARE");

	updateMasinaR(l, 2, m);

	assert(strcmp(getModel(getMasinaR(l, 2)), "2014") == 0);

	distructorLista(l);
}

void testRepositoryAll() {
	testLista();
	testAdd();
	testDelete();
	testUpdate();
	printf("Finalizare testRepo !\n");
}