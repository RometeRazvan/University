#include "Repository.h"
#include "TestRepository.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Lista* generateLista() {
	Masina *m = newMasina("CJ 04 TRM", "Electric", "SUV");
	Masina *m2 = newMasina("CJ 04 TRM", "Electric2", "SUV");

	Lista* l = newLista();

	adaugareMasinaR(l, *m2);
	adaugareMasinaR(l, *m2);
	adaugareMasinaR(l, *m);
	adaugareMasinaR(l, *m2);
	adaugareMasinaR(l, *m2);

	free(m);
	free(m2);

	return l;
}

void testAdd() {
	Masina *m = newMasina("CJ 04 TRM", "Electric", "SUV");
	Masina *m2 = newMasina("CJ 04 TRM", "Electric2", "SUV");

	Lista* l = newLista();

	adaugareMasinaR(l, *m2);
	assert(getLg(l) == 1);

	adaugareMasinaR(l, *m2);
	adaugareMasinaR(l, *m);
	adaugareMasinaR(l, *m2);
	assert(getLg(l) == 4);


	adaugareMasinaR(l, *m2);
	assert(getCapac(l) == 8);
	
	free(m);
	free(m2);
}

void testDelete() {
	Lista* l = generateLista();

	Masina m3 = stergeMasinaR(l, 2);
	assert(strcmp(getModel(&m3), "Electric") == 0);
	assert(getLg(l) == 4);
}

void testUpdate() {
	Masina* m = newMasina("CJ 04 TRM", "Electric", "SUV");
	Masina* m2 = newMasina("CJ 04 TRM", "Electric2", "SUV");

	Lista* l = newLista();

	adaugareMasinaR(l, *m2);
	adaugareMasinaR(l, *m2);
	adaugareMasinaR(l, *m2);
	adaugareMasinaR(l, *m2);
	adaugareMasinaR(l, *m2);

	updateMasinaR(l, 2, *m);
	Masina m3 = getMasinaR(l,2);
	assert(strcmp(getModel(&m3), "Electric") == 0);

	free(m);
	free(m2);
}

void testLista() {
	Lista* l = newLista();

	assert(getLg(l) == 0);
	assert(getCapac(l) == 2);

	destructorLista(l);
}

void testRepositoryAll() {
	testLista();
	testAdd();
	testDelete();
	testUpdate();

	printf("Finalizare testRepository !\n");
}