#pragma once
#include "Service.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*int modelCrescator(Masina* a, Masina* b) {
	if (strcmp(getModel(a), getModel(b)) == 1)
		return 1;
	else return 0;
}

int modelDescrescator(Masina* a, Masina* b) {
	if (strcmp(getModel(a), getModel(b)) == 1)
		return 0;
	else return 1;
}

int categCrescator(Masina* a, Masina* b) {
	if (strcmp(getCateg(a), getCateg(b)) == 1)
		return 1;
	else return 0;
}

int categDescrescator(Masina* a, Masina* b) {
	if (strcmp(getCateg(a), getCateg(b)) == 1)
		return 0;
	else return 1;
}

void sorter(Lista* l, sortFunction f) {
	int val = 0;
	while (!val) {
		val = 1;
		for (int i = 0; i < getLg(l) - 1; ++i) {
			if (f(getMasinaR(l, i), getMasinaR(l, i + 1)) == 0) {
				Masina* m = getMasinaR(l, i);
				Masina* m2 = getMasinaR(l, i + 1);
				Masina* m4 = newMasina(getNrI(m), getModel(m), getCateg(m));
				printf("1");
				m = m2;
				m2 = m4;
				distructorMasina(m4);
				val = 0;
			}
		}
	}
}*/

Serv* newService(Distructor f) {
	Serv* s = malloc(sizeof(Serv));
	s->lista = newLista(distructorMasina);
	s->inchirieri = newLista(distructorMasina);
	s->f = f;
	return s;
}

void distructorService(Serv* s) {
	s->f(s->inchirieri);
	s->f(s->lista);
	free(s);
}

int getLgLista(Serv* s) {
	return getLg(s->lista);
}

int getLgInc(Serv* s) {
	return getLg(s->inchirieri);
}

void adauga(Serv* s, char* nrI, char* model, char* categ) {
	Masina* m = newMasina(nrI, model, categ);
	adaugareMasinaR(s->lista, m);
}

void actualizeaza(Serv* s, int poz, char* nrI, char* model, char* categ) {
	Masina* m = newMasina(nrI, model, categ);
	updateMasinaR(s->lista, poz, m);
}

void inchiriaza(Serv* s, int poz) {
	Masina* m = stergeMasinaR(s->lista, poz);
	adaugareMasinaR(s->inchirieri, m);
}

void returneaza(Serv* s, int poz) {
	Masina* m = stergeMasinaR(s->inchirieri, poz);
	adaugareMasinaR(s->lista, m);
}

Lista* filtreaza(Serv* s, char* model, char* categ) {
	Lista* l = newLista(distructorMasina);
	for (int i = 0; i < getLgLista(s); ++i) {
		Masina* m = getMasinaS(s, i);
		if ((strcmp(getModel(m), model) == 0) && (strcmp(getCateg(m), categ) == 0)) {
			Masina* mf = newMasina(getNrI(m), getModel(m), getCateg(m));
			adaugareMasinaR(l, mf);
		}
	}
	return l;
}

/*void sorteaza(Serv* s, char* modelSauCateg, int cresc) {
	if (strcmp(modelSauCateg, "model") == 0) {
		if (cresc == 1)
			sorter(s->lista, modelCrescator);
		else 
			sorter(s->lista, modelDescrescator);
	}
	else {
		if (cresc == 1)
			sorter(s->lista, categCrescator);
		else
			sorter(s->lista, categDescrescator);
	}
}*/

Masina* getMasinaS(Serv* s, int poz) {
	return getMasinaR(s->lista, poz);
}

Masina* getMasinaSI(Serv* s, int poz) {
	return getMasinaR(s->inchirieri, poz);
}