#pragma once

#include "domain.h"

typedef struct {
	Medicament* elems;
	int lenght;
	int capacity;
}MedList;

/*
	Create an empty list of meds
*/
MedList createList();

/*
	return the lenght of the list
*/
int len(MedList* l);

/*
  Allocate more memory if needed
*/
void ensureCapacity(MedList* list);

/*
	Add a new med to the list
*/
void add(MedList* lista, Medicament med);

/*
	Deallocate a list
*/
void destroy(MedList* lista);

/*
	Verify if the med is already in the list
	Return 1 if med is already in the list
	Return 0 if med is not in the list
*/
int alreadyInList(MedList* lista, Medicament med);

/*
	return a med from the list with a specific index
*/
Medicament getElement(MedList* l, int index);

/*
	return a copy of a list
*/
MedList cpyList(MedList* list);


