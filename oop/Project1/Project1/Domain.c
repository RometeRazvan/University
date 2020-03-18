#include "Domain.h"

Masina newMasina(char* nrI, char* model, char* categ) {
	Masina m;
	m.categ = categ;
	m.model = model;
	m.nrI = nrI;
	return m;
}

char* getNrI(Masina m) {
	return m.nrI;
}

char* getModel(Masina m) {
	return m.model;
}

char* getCateg(Masina m) {
	return m.categ;
}