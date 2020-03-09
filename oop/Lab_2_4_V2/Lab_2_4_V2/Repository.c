#include "Repository.h"
#include <stdlib.h>

Lista* newLista(Distructor f) {
	Lista* l = malloc(sizeof(Lista));
	l->lista = (ElemT*)malloc(sizeof(ElemT) * 2);
	l->capacitate = 2;
	l->lg = 0;
	l->f = f;
	return l;
}

void distructorLista(Lista* l) {
	for (int i = 0; i < l->lg; ++i) {
		l->f(l->lista[i]);
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
	if (l->lg == l->capacitate) {
		int nCap = 2 * l->capacitate;
		ElemT* v = malloc(sizeof(ElemT) * nCap);
		for (int i = 0; i < l->lg; ++i) {
			v[i] = l->lista[i];
		}
		free(l->lista);
		l->lista = v;
		l->capacitate = nCap;
	}
}

void adaugareMasinaR(Lista* l, ElemT m) {
	checkRealloc(l);
	l->lista[l->lg] = m;
	++l->lg;
}

ElemT stergeMasinaR(Lista* l, int poz) {
	int j = 0, val = 0;
	ElemT *m;
	ElemT* v = malloc(sizeof(ElemT) * l->capacitate);
	for (int i = 0; i < l->lg; ++i) {
		if (i == poz) {
			val = 1;
			m = l->lista[i];
		}
		else { 
			v[j] = l->lista[i]; 
			++j;
		}
	}
	free(l->lista);
	l->lista = v;
	if (val == 1) --l->lg;
	return m;
}

void updateMasinaR(Lista* l, int poz, ElemT m) {
	for (int i = 0; i < l->lg; ++i) {
		if (i == poz) {
			l->f(l->lista[i]);
			l->lista[i] = m;
		}
	}
}

ElemT getMasinaR(Lista* l, int poz) {
	ElemT m = malloc(sizeof(ElemT));
	for (int i = 0; i < l->lg; ++i)
		if (i == poz)
			m = l->lista[i];
	return m;
}