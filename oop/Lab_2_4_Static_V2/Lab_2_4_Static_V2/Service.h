#pragma once
#include "Repository.h"
#include "Sorter.h"

typedef struct {
	Lista masini;
	Lista inchirieri;
}Serv;

/*
	Returneaza lista de Masini
	Preconditii s - Serv*
	Postconditii - %
*/
Lista getListaM(Serv s);

/*
	Returneaza lista de inchirireri
	Preconditii s - Serv*
	Postconditii - %
*/
Lista getListaI(Serv s);

/*
	Genereaza un service nou si il returneaza
	Preconditii : %
	Postonditii - %
 */
Serv newService();

/*
	Returneaza o masina din lista de masini dupa pozitia poz
	Preconditii - s - serv*, poz - int
	Postconditii - %
 */
Masina getSM(Serv s, int poz);

/*
	Returneaza o masina din lista de inchirireri dupa pozitia poz
	Preconditii - s - serv*, poz - int
	Postconditii - %
 */
Masina getSI(Serv s, int poz);

/*
	Returneaza lungimea listei de masini
	Preconditii s - Serv*
	Postconditii - %
*/
int getLgM(Serv s);

/*
	Returneaza lungimea de masini inchiriate
	Preconditii s - Serv*
	Postconditii - %
*/
int getLgI(Serv s);

/*
	Functia creeaza o masina din parametrii dati o adauga in lista
	Preconditii - s - Serv*, model categ nrI - char*
	Posctonditii - %
*/
void adaugaS(Serv* s, char* nrI, char* model, char* categ);

/*
	Functia sterge masina de pe pozitia poz
	Preconditii s - Serv*
	Postconditii - %
*/
void stergeS(Serv* s, int poz);

/*
	Functia creeaza o masina din parametrii dati si inlocuieste masina de pe pozitia poz cu aceasta
	Preconditii - s - Serv*, model categ nrI - char*
	Posctonditii - %
*/
void actualizeazaS(Serv* s, int poz, char* nrI, char* model, char* categ);


/*
	Functia sterge masina de pe pozitia poz, din vectorul de masini, si o adauga in vectorul de inchirieri
	Preconditii - s - Serv*, poz - int
	Postconditii - %
*/
void inchiriaza(Serv* s, int poz);

/*
	Functia sterge masina de pe pozitia poz. din vectorul de inchirieri, si o adauga in vectorul de masini
	Preconditii - s - Serv*, poz - int
	Postconditii - %
*/
void returneazaS(Serv* s, int poz);

Lista filtreaza(Serv* s, char* model, char* categ);

Lista sorteaza(Serv* s, char* modelSauCateg, int crescSauDesc);