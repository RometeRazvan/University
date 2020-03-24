#pragma once
typedef struct {
	char* nrI, * model, * categ;
}Masina;

/*
	Functie ce creeaza o masina nou
	Preconditii : nrI, model, categ - char*
	Postconditii : Valoarea returnata este de tip Masina*
*/
Masina* newMasina(char* nrI, char* model, char* categ);

/*
	Getter pentru numarul de inmatriculare al masinii
	Preconditii: m - Masina* 
	Poscodnitii : Output - char*
*/
char* getNrI(Masina* m);

/*
	Getter pentru modelul masinii
	Preconditii: m - Masina*
	Poscodnitii : Output - char*
*/
char* getModel(Masina* m);

/*
	Getter pentru categoria masinii
	Preconditii: m - Masina*
	Poscodnitii : Output - char*
*/
char* getCateg(Masina* m);

/*
	Distructor masina
	Preconditii: m - Masina*
	Poscodnitii : %
*/
void distructorMasina(Masina* m);
