#include "Repository.h"

typedef struct {
	Lista* lista;
	Lista* inchirieri;
}Serv;

int getLgLista(Serv *s);

int getLgInchirieri(Serv *s);

Masina* getMasinaS(Serv* s, int poz);

Masina* getMasinaIS(Serv* s, int poz);

Serv* newServ();

void destructorService(Serv*s);

typedef int (*f)(char* a, char* b);

void adauga(Serv* s, char* nrI, char* model, char* categ);

void actualizeaza(Serv* s, int poz, char* nrI, char* model, char* categ);

void inchiriaza(Serv* s, int poz);

void returneaza(Serv* s, int poz);

Lista* filtrare(Serv* s, char* categ, char* model);

Lista* sortare(Serv* s, char* modelSauCateg, char* crescSauDesc);