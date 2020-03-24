#pragma once
#include "Domain.h"

typedef void* ElemT;
typedef void(*Distructor)(ElemT);

typedef struct {
	ElemT* lista;
	int lg;
	int capacitate;
	Distructor f;
}Lista;

/*
	Functia aloca memorie pentru o noua lista
	Preconditii - f - distructor
	Postconditii - %
*/
Lista* newLista(Distructor f);

/*
	Functia returneaza lungimea unei liste
	Preconditii - l - Lista*
	Postconditii - %	
*/
int getLg(Lista* l);

/*
	Functia returneaza capacitatea unei liste
	Preconditii - l - Lista*
	Postconditii - %
*/
int getCapac(Lista* l);
 /*
	Functia verifica daca a fost atinsa capacitatea listei, caz in care, se dubleaza spatiul alocat in memorie pentru lista
	Preconditii - l - Lista*
	Postconditii - %	
*/
void checkRealloc(Lista* l);

/*
	Functia adauga un element in lista
	Preconditii - l - Lista*
	Postconditii - % 
*/
void adaugareMasinaR(Lista* l, ElemT m);

/*
	Functia sterge un element din lista de pe pozitia poz si il returneaza
	Preconditii - l - Lista*
	Postconditii - % 
*/
ElemT stergeMasinaR(Lista* l, int poz);

/*
	Functia inlocuieste un element din lista de pe pozitia poz
	Preconditii - l - Lista*
	Postconditii - %
*/
void updateMasinaR(Lista* l, int poz, ElemT m);

/*
	Functia returneaza un element din lista de pe pozitia poz
	Preconditii - l - Lista*
	Postconditii - %
*/
ElemT getMasinaR(Lista* l, int poz);
 
/*
	Functie de distructor pentru lista 
	Preconditii - l - Lista*
	Postconditii - %
 */
void distructorLista(Lista* l);