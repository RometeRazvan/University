#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "domain.h"


/*
	Create new Medicament
*/
Medicament createMed(int code, char* name, int concentration, int cantity) {
	Medicament med;
	med.code = code;
	size_t nrC = strlen(name) + 1;
	med.name = malloc(sizeof(char) * nrC);
	strcpy_s(med.name, nrC, name);
	med.concentration = concentration;
	med.cantity = cantity;
	return med;
}

/*
	Set a new cantity to a medicamet
*/
void setCantity(Medicament* med, int cantity)
{
	med->cantity = cantity;
}

/*
	Return the cantity of a medicament
*/
int getCantity(Medicament med)
{
	return med.cantity;
}

/*
	Return the code of a medicament
*/
int getCode(Medicament med)
{
	return med.code;
}

/*
	Set a new name to a medicamet
*/
void setName(Medicament* med, char* name)
{
	free(med->name);
	size_t nrC = strlen(name) + 1;
	med->name = malloc(sizeof(char) * nrC);
	strcpy_s(med->name, nrC, name);
}

/*
	Return the name of a medicament
*/
char* getName(Medicament med)
{
	return med.name;
}

/*
	Set a new concentration to a medicamet
*/
void setConcentration(Medicament* med, int concentration)
{
	med->concentration = concentration;
}

/*
	Return the concentration of a medicament
*/
int getConcentration(Medicament med)
{
	return med.concentration;
}

/*
	Compare the names of two medicaments
	Return 1 if med1.name > med2.name
	Return 0 if names are equal
	Return -1 if med1.name < med2.name
*/
int cmpName(Medicament med1, Medicament med2)
{
	return strcmp(getName(med1), getName(med2));
}

/*
	Compare the canities of two medicaments
	Return 1 if med1.cantity > med2.cantity
	Return 0 if cantities are equal
	Return -1 if med1.cantity < med2.cantity
*/
int cmpCantity(Medicament med1, Medicament med2)
{
	if (med1.cantity == med2.cantity)
		return 0;
	if (med1.cantity > med2.cantity)
		return 1;
	return -1;
}

/*
	The first medicament gets identical with the second medicament
*/
void cpyMedicament(Medicament* med1, Medicament med2) {
	med1->code = med2.code;
	setName(med1, getName(med2));
	med1->cantity = med2.cantity;
	med1->concentration = med2.concentration;
}

/*
	The medicaments get each other's characteristics
*/
void swapMedicament(Medicament* med1, Medicament* med2)
{
	Medicament aux = createMed(0, "", 0, 0);
	cpyMedicament(&aux, *med1);
	cpyMedicament(med1, *med2);
	cpyMedicament(med2, aux);
	destroyMed(&aux);
}

/*
	Dealocate memory occupied by medicine
*/
void destroyMed(Medicament* med)
{
	free(med->name);
	//mark that med is destroyed, avoid accidental use after destroy
	med->name = NULL;
	med->code = -1;
	med->cantity = -1;
	med->concentration = -1;
}
