#pragma once
#include "Domain.h"

typedef struct {
	Masina lsita[1000];
	int lg;
}Lista;

/*
	Functia genereaza o noua lista
	Preconditii - %
	Postconditii - %
*/
Lista newLista();

/*
	Functia returneaza lungimea unei liste
	Preconditii - l - Lista
	Postconditii - %
*/
int getLg(Lista l);

/*
	Functia face o copie unei liste l si returneaza copia respectiva
	Preconditii - l - Lista
	Postconditii - %
*/
Lista copyLista(Lista l);

/*
	Functia adauga o masina in lista
	Preconditii - l - Lista, m - Masina
	Postconditii - %
*/
void adaugaR(Lista* l, Masina m);

/*
	Functia returneaza un element din lista de pe pozitia poz
	Preconditii - l - Lista
	Postconditii - %
*/
Masina getR(Lista l, int poz);

/*
	Functia sterge un element din lista de pe pozitia poz si il returneaza
	Preconditii - l - Lista*
	Postconditii - %
*/
Masina stergeR(Lista* l, int poz);

/*
	Functia inlocuieste o masina din lista de pe pozitia poz
	Preconditii - l - Lista*
	Postconditii - %
*/
void modificaR(Lista* l, int poz, Masina m);