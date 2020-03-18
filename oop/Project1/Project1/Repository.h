#pragma once
#include "Domain.h"

typedef struct {
	Masina lsita[1000];
	int lg;
}Lista;

Lista newLista();

int getLg(Lista l);

Lista copyLista(Lista l);

void adaugaR(Lista *l, Masina m);

Masina getR(Lista l, int poz);

Masina stergeR(Lista *l, int poz);

void modificaR(Lista *l, int poz, Masina m);