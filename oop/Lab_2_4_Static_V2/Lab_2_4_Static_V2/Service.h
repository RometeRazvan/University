#pragma once
#include "Repository.h"
#include "Sorter.h"

typedef struct {
	Lista masini;
	Lista inchirieri;
}Serv;

Lista getListaM(Serv s);

Lista getListaI(Serv s);

Serv newService();

Masina getSM(Serv s, int poz);

Masina getSI(Serv s, int poz);

int getLgM(Serv s);

int getLgI(Serv s);

void adaugaS(Serv* s, char* nrI, char* model, char* categ);

void stergeS(Serv* s, int poz);

void actualizeazaS(Serv* s, int poz, char* nrI, char* model, char* categ);

void inchiriaza(Serv* s, int poz);

void returneazaS(Serv* s, int poz);

Lista filtreaza(Serv* s, char* model, char* categ);

Lista sorteaza(Serv* s, char* modelSauCateg, int crescSauDesc);