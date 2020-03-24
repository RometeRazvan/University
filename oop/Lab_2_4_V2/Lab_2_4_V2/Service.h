#pragma once
#include "Repository.h"
#include "Validator.h"
#include "Sorter.h"

//#include "Sorter.h"

typedef struct {
	Lista* lista;
	Lista* inchirieri;
	Distructor f;
	Validator* validator;
}Serv;

typedef void* Elem;

typedef int (*sortFunction)(Elem a, Elem b);


/*
	Returneaza lista de Masini
	Preconditii s - Serv*
	Postconditii - %
*/
Lista* getListaMasini(Serv* s);

/*
	Returneaza lista de inchirireri
	Preconditii s - Serv*
	Postconditii - %
*/
Lista* getListaInc(Serv* s);

/*
	Returneaza lungimea listei de masini
	Preconditii s - Serv*
	Postconditii - %
*/
int getLgLista(Serv* s);

/*
	Returneaza lungimea de masini inchiriate
	Preconditii s - Serv*
	Postconditii - %
*/
int getLgInc(Serv* s);
 
/*
	Aloca memorie pentru Service
	Preconditii : f - distructor
	Postonditii - %
 */
Serv* newService(Distructor f);

/*
	Dezaloca memoria folosita de service
	Preconditii  : s - Serv*
	Posctonditii - %	
*/
void distructorService(Serv* s);

/*
	Functia creeaza o masina din parametrii dati si verifica daca o poate adauga in repository, daca da returneaza valoarea 1, daca nu, returneaza valoarea 0
	Preconditii - s - Serv*, model categ nrI - char*
	Posctonditii - %
*/
int adauga(Serv* s, char* nrI, char* model, char* categ);

/*
	Functia creeaza o masina din parametrii dati si verifica daca poate sa inlocuiasca cu aceasta masina de pe pozitia poz in repository, daca da returneaza valoarea 1, daca nu, returneaza valoarea 0
	Preconditii - s - Serv*, model categ nrI - char*
	Posctonditii - %
*/
int actualizeaza(Serv* s, int poz, char* nrI, char* model, char* categ);

/*
	Functia verifica daca masina de pe pozitia poz poate fi inchiriata, daca da, este inchiriata si returneaza valoarea 1, daca nu, returneaza valoarea 0
	Preconditii - s - Serv*, poz - int
	Postconditii - %	
*/
int inchiriaza(Serv* s, int poz);

/*
	Functia verifica daca masina de pe pozitia poz poate fi returnata, daca da, este returnata si functia returneaza valoarea 1, daca nu, functia returneaza valoarea 0
	Preconditii - s - Serv*, poz - int
	Postconditii - %
*/
int returneaza(Serv* s, int poz);
 
/*
	Functia returneaza o lista cu elementele care au modelul identic cu parametrul "model" si categoria identica cu parametrul "categ"
	Preconditii - s - Serv*, model categ - char*
	Postconditii - %
 */
Lista* filtreaza(Serv* s, char* model, char* categ);

/*
	Functia returneaza o lista sortata a masinilor, in functie de parametrii, se sorteaza dupa model sau categorie si ordinea este fie crescatoare, fie descrescatoare
	Preconditii - s - serv*, modelSaucateg - char*, cresc - int
	Postconditii - %
*/
Lista* sorteaza(Serv* s, char* modelSauCateg, int cresc);
 
/*
	Returneaza o masina din lista de masini dupa pozitia poz
	Preconditii - s - serv*, poz - int
	Postconditii - %
 */
Masina* getMasinaS(Serv* s, int poz);

/*
	Returneaza o masina din lista de inchirireri dupa pozitia poz
	Preconditii - s - serv*, poz - int
	Postconditii - %
 */
Masina* getMasinaSI(Serv* s, int poz);