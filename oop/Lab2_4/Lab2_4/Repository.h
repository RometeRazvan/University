#include "Domain.h"

typedef Elem;

typedef struct {
	Masina* lista;
	int lg;
	int capacitate;
}Lista;

Lista* newLista();

int getLg(Lista* l);

int getCapac(Lista* l);

void checkRealloc(Lista* l);

void adaugareMasinaR(Lista* l, Masina m);

Masina stergeMasinaR(Lista* l, int poz);

void updateMasinaR(Lista* l, int poz, Masina m);

Masina getMasinaR(Lista* l, int poz);

void destructorLista(Lista* l);