#include "medicamentService.h"
#include "domain.h"
#include "validate.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
	Add medicaments in pharmacy
	Return 0 if the med was succesfuly added
*/
int addMed(MedList* lista, Medicament med) {
	int succ = validateMed(med);
	if (succ) {
		destroyMed(&med);
		return succ;
	}
	if (alreadyInList(lista, med)) {
		for (int i = 0; i < len(lista); i++)
			if (getCode(med) == getCode(lista->elems[i]))
				setCantity(&lista->elems[i], getCantity(med));
		destroyMed(&med);
	}
	else add(lista, med);
	return 0;
}

/*
	Update the name of the med with the scecific code
*/
int updateName(MedList* lista, int code, char* name)
{
	Medicament med = createMed(0, " ", 0, 0);
	for (int i = 0; i < len(lista); i++)
		if (getCode(lista->elems[i]) == code) {

			cpyMedicament(&med, lista->elems[i]);
			setName(&med, name);
			int valid = validateMed(med);
			if (valid) {
				destroyMed(&med);
				return valid;
			}
			cpyMedicament(&lista->elems[i], med);
		}
	destroyMed(&med);
	return 0;
}

/*
	Update the concentration of the med with the scecific code
*/
int updateConcentration(MedList* lista, int code, int concentration)
{
	Medicament med = createMed(0, " ", 0, 0);;
	for (int i = 0; i < len(lista); i++)
		if (getCode(lista->elems[i]) == code) {

			cpyMedicament(&med, lista->elems[i]);
			setConcentration(&med, concentration);
			int valid = validateMed(med);
			if (valid) {
				destroyMed(&med);
				return valid;
			}
			cpyMedicament(&lista->elems[i], med);
		}
	destroyMed(&med);
	return 0;
}

/*
	Delete the stock of the med with the spefied code
*/
void deleteStocks(MedList* lista, int code)
{
	for (int i = 0; i < len(lista); i++)
		if (getCode(lista->elems[i]) == code)
			setCantity(&lista->elems[i], 0);
}


/*
	Return a sorted list
*/
MedList sortNameAsc(MedList* lista)
{
	MedList l = cpyList(lista);
	sortAsc(&l, cmpName);
	return l;
}

/*
	Return a sorted descending list
*/
MedList sortNameDesc(MedList* lista)
{
	MedList l = cpyList(lista);
	sortDesc(&l, cmpName);
	return l;
}

/*
	Sort the meds by cantity(ascending)
*/
MedList sortCantityAsc(MedList* lista)
{
	MedList l = cpyList(lista);
	sortAsc(&l, cmpCantity);
	return l;
}

/*
	Sort the meds alphabetically(descending)
*/
MedList sortCantityDesc(MedList* lista)
{
	MedList l = cpyList(lista);
	sortDesc(&l, cmpCantity);
	return l;
}

/*
	Remove the meds from the list that have the cantity bigger than the value
*/
MedList filterCantity(MedList* l, int val)
{
	MedList lista = cpyList(l);
	int i = 0;
	while (i < len(&lista)) {
		if (getCantity(getElement(&lista, i)) > val) {
			for (int j = i; j < len(&lista); j++)
				cpyMedicament(&lista.elems[i], getElement(&lista, j));
			lista.lenght--;
			destroyMed(&lista.elems[len(&lista)]);
		}
		else i++;
	}
	return lista;
}

/*
	Remove the meds from the list that begin with a specific letter
*/
MedList filterName(MedList* l, char* litera)
{
	MedList lista = cpyList(l);
	int i = 0;
	while (i < len(&lista)) {
		if (getName(getElement(&lista, i))[0] != litera[0]) {
			for (int j = i; j < len(&lista) - 1; j++)
				cpyMedicament(&lista.elems[j], getElement(&lista, j + 1));
			lista.lenght--;
			destroyMed(&lista.elems[len(&lista)]);
		}
		else i++;
	}
	return lista;
}
