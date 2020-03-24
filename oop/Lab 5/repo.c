#include "repo.h"
#include "validate.h"
#include <malloc.h>

/*
	Create an empty list of meds
*/
MedList createList()
{
	MedList lista;
	lista.lenght = 0;
	lista.capacity = 2;
	lista.elems = (Medicament*)malloc(lista.capacity * sizeof(Medicament));;
	return lista;
}

/*
	return the lenght of the list
*/
int len(MedList* l) {
	return l->lenght;
}

/*
  Allocate more memory if needed
*/
void ensureCapacity(MedList* list)
{
	if (len(list) < list->capacity)
		return;
	int newCapacity = list->capacity * 2;
	Medicament* newElems = (Medicament*)malloc(newCapacity * sizeof(Medicament));
	if (newElems) {
		for (int i = 0; i < len(list); i++)
			newElems[i] = list->elems[i];
		free(list->elems);
		list->elems = newElems;
		list->capacity = newCapacity;
	}
}


/*
	Add a new med to the list
*/
void add(MedList* lista, Medicament med)
{
	ensureCapacity(lista);
	lista->elems[len(lista)] = med;
	lista->lenght++;
}

/*
	Deallocate a list
*/
void destroy(MedList* lista)
{
	for (int i = len(lista) - 1; i >= 0; i--) {
		destroyMed(&lista->elems[i]);
	}
	free(lista->elems);
	lista->elems = NULL;
	lista->lenght = 0;
	lista->capacity = 0;
}

/*
	Verify if the med is already in the list
	Return 1 if med is already in the list
	Return 0 if med is not in the list
*/
int alreadyInList(MedList* lista, Medicament med)
{
	for (int i = 0; i < len(lista); i++)
		if (getCode(med) == getCode(lista->elems[i]))
			return 1;
	return 0;
}

/*
	return a med from the list with a specific index
*/
Medicament getElement(MedList* l, int index)
{
	return l->elems[index];
}

/*
	returns a copy of a list
*/
MedList cpyList(MedList* list)
{
	MedList newList = createList();
	for (int i = 0; i < len(list); i++)
		if (getCantity(getElement(list, i)) != 0) {
			Medicament med = createMed(getCode(list->elems[i]), getName(list->elems[i]), getConcentration(list->elems[i]), getCantity(list->elems[i]));
			add(&newList, med);
		}
	return newList;
}





