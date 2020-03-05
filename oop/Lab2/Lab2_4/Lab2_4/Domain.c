#include "Domain.h"
#include <string.h>

Masina newMasina(char* nrI2, char* model2, char* categ2) {
	Masina m;
	m.nrI = nrI2;
	m.model = model2;
	m.categ = categ2;
	return m;
}

Lista newLista() {
	Lista l;
	l.max = 1;
	return l;
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

void setNrI(Masina m, char* s) {
	m.nrI = s;
}

void setModel(Masina m, char* s) {
	m.model = s;
}

void setCateg(Masina m, char* s) {
	m.categ = s;
}

void setMax(Lista l, int max) {
	l.max = max;
}