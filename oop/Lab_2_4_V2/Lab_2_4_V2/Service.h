#pragma once
#include "Repository.h"
//#include "Validator.h"

//#include "Sorter.h"

typedef struct {
	Lista* lista;
	Lista* inchirieri;
	Distructor f;
	//Validator validator;
}Serv;

typedef void* Elem;

typedef int (*sortFunction)(Elem a, Elem b);

int getLgLista(Serv* s);

int getLgInc(Serv* s);

Serv* newService(Distructor f);

void distructorService(Serv* s);

void adauga(Serv* s, char* nrI, char* model, char* categ);

void actualizeaza(Serv* s, int poz, char* nrI, char* model, char* categ);

void inchiriaza(Serv* s, int poz);

void returneaza(Serv* s, int poz);

Lista* filtreaza(Serv* s, char* model, char* categ);

void sorteaza(Serv* s, char* modelSauCateg, int cresc);

Masina* getMasinaS(Serv* s, int poz);

Masina* getMasinaSI(Serv* s, int poz);