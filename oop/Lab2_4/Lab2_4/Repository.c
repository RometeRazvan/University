#include "Repository.h"
#include <stdio.h>
#include <stdlib.h>

Lista* newLista() {
	Lista* l = malloc(sizeof(Lista));
	l->capacitate = 2;
	l->lg = 0;
	l->lista = malloc(sizeof(Masina) * l->capacitate);
	return l;
}

void destructorLista(Lista* l) {
	for (int i = 0; i < getLg(l); ++i) {
		destructorMasina(l->lista[i]);
	}
	free(l->lista);
	free(l);
}


int getLg(Lista* l) {
	return l->lg;
}

int getCapac(Lista* l) {
	return l->capacitate;
}

void checkRealloc(Lista* l) {
	if (getCapac(l) == getLg(l)) {
		int nCap = l->capacitate * 2;
		Masina* v = malloc(nCap * sizeof(Masina));
		for (int i = 0; i < l->lg; ++i) {
			v[i] = l->lista[i];
		}
		for (int i = 0; i < getLg(l); ++i) {
			destructorMasina(l->lista[i]);
		}
		free(l->lista);
		l->lista = v;
		l->capacitate = nCap;
	}
}

void adaugareMasinaR(Lista* l, Masina m) {
	checkRealloc(l);
	l->lista[l->lg] = m;
	++l->lg;
}

Masina stergeMasinaR(Lista* l, int poz) {
	Masina m;
	Masina* v = malloc(l->capacitate * sizeof(Masina));
	int val = 0, j = 0;
	for (int i = 0; i < l->lg; ++i) {
		if (i != poz)
			v[i] = l->lista[i];
		else {
			m = l->lista[i];
			val = 1;
		}
	}
	for (int i = 0; i < getLg(l); ++i) {
		destructorMasina(l->lista[i]);
	}
	free(l->lista);
	l->lista = v;
	if (val == 1) {
		--l->lg;
	}
	return m;
}

void updateMasinaR(Lista* l, int poz, Masina m) {
	for (int i = 0; i < l->lg; ++i) {
		if (i == poz)
			l->lista[i] = m;
	}
}

Masina getMasinaR(Lista* l, int poz) {
	Masina m;
	for (int i = 0; i < l->lg; ++i) {
		if (i == poz)
			m = l->lista[i];
	}
	return m;
}