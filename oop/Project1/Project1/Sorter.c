#include "Sorter.h"
#include <string.h>

Lista sortList(Lista l, choose fc) {
	
	Lista nl = copyLista(l);

	int val = 0;
	while (!val) {
		val = 1;
		for (int i = 0; i < getLg(nl) - 1; ++i) {
			if (fc(getR(nl, i), getR(nl, i + 1)) == 0) {
				Masina m = nl.lsita[i];
				nl.lsita[i] = nl.lsita[i + 1];
				nl.lsita[i + 1] = m;
				val = 0;
			}
		}
	}

	return nl;
}

int modelCrescator(Masina a, Masina b) {
	if (strcmp(getModel(a), getModel(b)) < 0)
		return 1;
	return 0;
}

int modelDescrescator(Masina a, Masina b) {
	if (strcmp(getModel(a), getModel(b)) < 0)
		return 0;
	return 1;
}

int categCrescator(Masina a, Masina b) {
	if (strcmp(getCateg(a), getCateg(b)) < 0)
		return 1;
	return 0;
}

int categDescrescator(Masina a, Masina b) {
	if (strcmp(getCateg(a), getCateg(b)) < 0)
		return 0;
	return 1;
}