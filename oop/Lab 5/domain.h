#pragma once

typedef struct{
	int code;
	char* name;
	int concentration;
	int cantity;
}Medicament;

/*
	Create new Medicament
*/
Medicament createMed(int code, char* name, int concentration, int cantity);

/*
	Set a new cantity to a medicamet
*/
void setCantity(Medicament* med, int cantity);

/*
	Return the cantity of a medicament
*/
int getCantity(Medicament med);

/*
	Return the code of a medicament
*/
int getCode(Medicament med);

/*
	Set a new name to a medicamet
*/
void setName(Medicament* med, char* name);

/*
	Return the name of a medicament
*/
char* getName(Medicament med);

/*
	Set a new concentration to a medicamet
*/
void setConcentration(Medicament* med, int concentration);

/*
	Return the concentration of a medicament
*/
int getConcentration(Medicament med);

/*
	Compare the names of two medicaments
	Return 1 if med1.name > med2.name
	Return 0 if names are equal
	Return -1 if med1.name < med2.name
*/
int cmpName(Medicament med1, Medicament med2);

/*
	Compare the canities of two medicaments
	Return 1 if med1.cantity > med2.cantity
	Return 0 if cantities are equal
	Return -1 if med1.cantity < med2.cantity
*/
int cmpCantity(Medicament med1, Medicament med2);

/*
	The first medicament gets identical with the second medicament
*/
void cpyMedicament(Medicament* med1, Medicament med2);

/*
	The medicaments get each other's characteristics
*/
void swapMedicament(Medicament* med1, Medicament* med2);

/*
	Dealocate memory occupied by medicine
*/
void destroyMed(Medicament* med);