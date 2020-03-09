#include "Domain.h"
#include <stdlib.h>

Masina* newMasina(char* nrI, char* model, char* categ) {
	Masina* m = malloc(sizeof(Masina));
	m->categ = categ;
	m->model = model;
	m->nrI = nrI;
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
	//free(m->categ);
	//free(m->nrI);
	//free(m->model);
	free(m);
}