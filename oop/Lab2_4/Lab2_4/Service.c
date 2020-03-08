#include "Service.h"
#include <stdio.h>
#include <stdlib.h>
/*
typedef int (*f)(char* a, char* b);

Serv* newServ() {
	Serv* s = malloc(sizeof(Serv));
	s->lista = newLista();
	s->inchirieri = newLista();
	return s;
}

void destructorService(Serv* s) {
	destructorLista(s->inchirieri);
	destructorLista(s->lista);
	free(s);
}

int getLgLista(Serv* s) {
	return getLg(s->lista);
}

Masina* getMasinaS(Serv* s, int poz) {
	return getMasinaR(s->lista, poz);
}
Masina* getMasinaIS(Serv* s, int poz) {
	return getMasinaR(s->inchirieri, poz);
}

int getLgInchirieri(Serv* s) {
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

void returneaza(Serv* s, int poz){
	Masina* m = stergeMasinaR(s->lista, poz);
	adaugareMasinaR(s->inchirieri, m);
}

Lista* filtrare(Serv* s, char* categ, char* model);

Lista* sortare(Serv* s, char* modelSauCateg, char* crescSauDesc);*/