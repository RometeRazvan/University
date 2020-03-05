#include "Domain.h"

Masina newMasina(char* nrI, char* model, char* categ) {
	Masina m;
	m.nrI = nrI;
	m.model = model;
	m.categ = categ;
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