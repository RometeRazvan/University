#pragma once
#include "Service.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Serv* newService(Distructor f) {
	Serv* s = malloc(sizeof(Serv));
	s->lista = newLista(distructorMasina);
	s->inchirieri = newLista(distructorMasina);
	s->f = f;
	Validator* v = newValidator(valideazaMasina);
	s->validator = v;
	return s;
}

void distructorService(Serv* s) {
	s->f(s->inchirieri);
	s->f(s->lista);
	distructorValidator(s->validator);
	free(s);
}

int getLgLista(Serv* s) {
	return getLg(s->lista);
}

int getLgInc(Serv* s) {
	return getLg(s->inchirieri);
}

Lista* getListaMasini(Serv* s) {
	return s->lista;
}

Lista* getListaInc(Serv* s) {
	return s->inchirieri;
}

int adauga(Serv* s, char* nrI, char* model, char* categ) {
	Masina* m = newMasina(nrI, model, categ);

	if (s->validator->validatorMasina(m) == 0) {
		distructorMasina(m);
		return 0;
	} 

	adaugareE(s->lista, m);
	return 1;
}

int actualizeaza(Serv* s, int poz, char* nrI, char* model, char* categ) {
	Masina* m = newMasina(nrI, model, categ);

	if (s->validator->validatorMasina(m) == 0 
		|| (poz < 0 || poz > getLgLista(s)) ) {
		distructorMasina(m);
		return 0;
	}

	updateE(s->lista, poz, m);
	return 1;
}

int inchiriaza(Serv* s, int poz) {
	if (poz < 0 || poz > getLgLista(s))
		return 0;

	Masina* m = stergereE(s->lista, poz);
	adaugareE(s->inchirieri, m);
	return 1;
}

int returneaza(Serv* s, int poz) {
	if (poz < 0 || poz > getLgInc(s))
		return 0;

	Masina* m = stergereE(s->inchirieri, poz);
	adaugareE(s->lista, m);
	return 1;
}

Lista* filtreaza(Serv* s, char* model, char* categ) {
	Lista* l = newLista(distructorMasina);
	for (int i = 0; i < getLgLista(s); ++i) {
		Masina* m = getMasinaS(s, i);
		if ((strcmp(getModel(m), model) == 0) && (strcmp(getCateg(m), categ) == 0)) {
			Masina* mf = newMasina(getNrI(m), getModel(m), getCateg(m));
			adaugareE(l, mf);
		}
	}
	return l;
}

Masina* getMasinaS(Serv* s, int poz) {
	return getE(s->lista, poz);
}

Masina* getMasinaSI(Serv* s, int poz) {
	return getE(s->inchirieri, poz);
}

Lista* sorteaza(Serv* s, char* modelSauCateg, int cresc) {

	if (strcmp(modelSauCateg, "model") == 0) {
		if (cresc > 0)
			return sortList(s->lista, modelCrescator);
		else return sortList(s->lista, modelDescrescator);
	}
	else if (strcmp(modelSauCateg, "categ") == 0) {
		if (cresc > 0)
			return sortList(s->lista, categCrescator);
		else return sortList(s->lista, categDescrescator);
	}

	Lista* l = newLista(distructorMasina);

	return l;
}