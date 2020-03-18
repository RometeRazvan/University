#include "Domain.h"
#include <stdlib.h>
#include <string.h>

Masina* newMasina(char* nrI, char* model, char* categ) {
	Masina* m = malloc(sizeof(Masina));

	int lgNrI = strlen(nrI) + 1;
	m->nrI = malloc(lgNrI);
	strcpy_s(m->nrI, lgNrI, nrI);

	int lgModel = strlen(model) + 1;
	m->model = malloc(lgModel);
	strcpy_s(m->model, lgModel, model);

	int lgCateg = strlen(categ) + 1;
	m->categ = malloc(lgCateg);
	strcpy_s(m->categ, lgCateg, categ);

	return m;
}

char* getNrI(Masina* m) {
	return m->nrI;
}

char* getModel(Masina* m) {
	return m->model;
}

char* getCateg(Masina* m) {
	return m->categ;
}

void distructorMasina(Masina* m) {
	free(m->categ);
	free(m->nrI);
	free(m->model);
	free(m);
}