#include "Sorter.h"
#include <string.h>
#include <stdlib.h>

Lista* sortList(Lista* l, choose fc) {

	Lista* nl = newLista(distructorMasina);
	int* check = malloc(sizeof(int) * (getLg(l) + 1));
	int n = 0, lg = getLg(l);

	for (int i = 0; i < lg; ++i) {
		check[i] = 1;
	}

	while (n != lg) {

		for (int i = 0; i < lg; ++i) {
			if (check[i] == 1) {

				int val = 1;

				for (int j = 0; j < lg; ++j) {

					if(check[j] == 1 && i != j)

						if (fc(getMasinaR(l, i), getMasinaR(l, j)) != 1) {

							val = 0;
							break;							
						}
				}

				if (val == 1) {

					check[i] = 0;

					Masina* m = getMasinaR(l, i);
					Masina* nm = newMasina(getNrI(m), getModel(m), getCateg(m));
					adaugareMasinaR(nl, nm);

					++n;
				}
			}
		}

	}

	free(check);

	return nl;

}

int modelCrescator(Masina* a, Masina* b) {
	if (strcmp(getModel(a), getModel(b)) <= 0)
		return 1;
	return 0;
}

int modelDescrescator(Masina* a, Masina* b) {
	if (strcmp(getModel(a), getModel(b)) < 0)
		return 0;
	return 1;
}

int categCrescator(Masina* a, Masina* b) {
	if (strcmp(getCateg(a), getCateg(b)) <= 0)
		return 1;
	return 0;
}

int categDescrescator(Masina* a, Masina* b) {
	if (strcmp(getCateg(a), getCateg(b)) < 0)
		return 0;
	return 1;
}