#pragma once

typedef struct {
	char* nrI, * model, * categ;
}Masina;

Masina newMasina(char* nrI, char* model, char* categ);

char* getNrI(Masina m);

char* getModel(Masina m);

char* getCateg(Masina m);