#include "Domain.h"
#include <string.h>

Masina newMasina(char* nrI, char* model, char* categ) {
	Masina m; // = { .nrI = "", .model = "", .categ = "" };
	/*char nrI2[30], model2[30], categ2[30];
	strcpy_s(nrI2, strlen(nrI) + 1, nrI);
	strcpy_s(model2, strlen(model) + 1, model);
	strcpy_s(categ2, strlen(categ) + 1, categ);*/
	m.categ = categ;
	m.model = model;
	m.nrI = nrI;
	/*strcpy_s(m.nrI, sizeof(m.nrI) + 1, nrI);
	strcpy_s(m.model, sizeof(m.model) + 1, model);
	strcpy_s(m.categ, sizeof(m.categ) + 1, categ);*/
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