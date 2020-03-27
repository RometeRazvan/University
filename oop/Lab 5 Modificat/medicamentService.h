#pragma once
#include "repo.h"

/*
	Add medicaments in pharmacy
	Returns 0 if the med was succesfuly added
*/
int addMed(MedList* lista, Medicament med);

/*
	Update the name of the med with the scecific code
*/
int updateName(MedList* lista, int code, char* name);

/*
	Update the concentration of the med with the scecific code
*/
int updateConcentration(MedList* lista, int code, int concentration);

/*
	Delete the stock of the med with the spefied code
*/
void deleteStocks(MedList* lista, int code);

/*
	Return a sorted list
*/
MedList sortNameAsc(MedList* lista);

/*
	Sort the meds alphabetically from Z to A
*/
MedList sortNameDesc(MedList* lista);

/*
	Sort the meds by cantity(ascending)
*/
MedList sortCantityAsc(MedList* lista);

/*
	Sort the meds alphabetically(descending)
*/
MedList sortCantityDesc(MedList* lista);

/*
	Remove the meds from the list that have the cantity bigger than the value
*/
MedList filterCantity(MedList* lista, int val);

/*
	Remove the meds from the list that begin with a specific letter
*/
MedList filterName(MedList* lista, char* litera);

/*
	Show every med from the list
*/
void showMedList(MedList* lista);
