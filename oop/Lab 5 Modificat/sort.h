#pragma once

#include "repo.h"

/*
   Type of the function for comparing 2 elements
   return 0 if equal, 1 if o1>o2, -1 else
*/
typedef int(*CompareFunction)(Medicament o1, Medicament o2);

/**
* Sort ascending in place
* cmpf - relatia dupa care se sorteaza
*/
void sortAsc(MedList* l, CompareFunction cmpF);

/**
* Sort descending in place
* cmpf - relatia dupa care se sorteaza
*/
void sortDesc(MedList* l, CompareFunction cmpF);