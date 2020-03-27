#include "sort.h"

/**
* Sort ascending in place
* cmpf - relatia dupa care se sorteaza
*/
void sortAsc(MedList* l, CompareFunction cmpF) {
	int i, j;
	for (i = 0; i < len(l); i++)
		for (j = i + 1; j < len(l); j++)
			if (cmpF(getElement(l, i), getElement(l, j)) > 0)
				swapMedicament(&l->elems[i], &l->elems[j]);
}

/**
* Sort descending in place
* cmpf - relatia dupa care se sorteaza
*/
void sortDesc(MedList* l, CompareFunction cmpF)
{
	int i, j;
	for (i = 0; i < len(l); i++)
		for (j = i + 1; j < len(l); j++)
			if (cmpF(getElement(l, i), getElement(l, j)) < 0)
				swapMedicament(&l->elems[i], &l->elems[j]);
}