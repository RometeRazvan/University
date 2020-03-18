#include "Repository.h"
#include <stdio.h>

Lista newLista() {
	Lista l;
	l.lg = 0;
	return l;
}

int getLg(Lista l) {
	return l.lg;
}

Lista copyLista(Lista l) {
	Lista nl = newLista();
	for (int i = 0; i < l.lg; ++i)
		nl.lsita[nl.lg++] = l.lsita[i];
	return nl;
}

void adaugaR(Lista *l, Masina m) {
	l->lsita[l->lg++] = m;
}

Masina getR(Lista l, int poz) {
	for (int i = 0; i < l.lg; ++i)
		if (i == poz)
			return l.lsita[i];

	Masina m = { .nrI = "", .model = "", .categ = "" };

	return m;
}

Masina stergeR(Lista *l, int poz) {
	Masina m = { .nrI = "", .model = "", .categ = "" };
	int val = 0;

	for (int i = 0; i < l->lg; ++i) {
		if (i == poz) {
			val = 1;
			m = l->lsita[i];
		}
	}

	if (val == 1) {
		if (poz != l->lg - 1) {
			for (int i = poz; i < l->lg - 1; ++i)
				l->lsita[i] = l->lsita[i + 1];
		}
		--l->lg;
	}

	return m;
}

void modificaR(Lista *l, int poz, Masina m) {
	for (int i = 0; i < l->lg; ++i) {
		if (i == poz) {
			l->lsita[i] = m;
		}
	}
}