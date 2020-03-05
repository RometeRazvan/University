/*
	Struct pentru elementul de masina
	Preconditii - nrI, model categ - char*
	Postconditii - %
*/
typedef struct {
	char* nrI, model, categ;
}Masina;

/*
	Struct pentru lista de masini
	Preconditii - m - masina;
	Posconditi - %
*/
typedef struct {
	Masina masini[1000];
	int max;
}Lista;

Masina newMasina(char* nrI, char* model, char* categ);
Lista newLista();
char* getNrI(Masina m);
char* getModel(Masina m);
char* getCateg(Masina m);
Masina getMasina(int poz);
int getMaxim(Lista l);
int getCurent(Lista l);
void setNrI(Masina m, char* s);
void setModel(Masina m, char* s);
void setCateg(Masina m, char* s);
void setMaxim(Lista l, int max);
void setCurent(Lista l, int curent);
