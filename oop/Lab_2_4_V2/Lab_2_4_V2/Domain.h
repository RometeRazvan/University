typedef struct {
	char* nrI, * model, * categ;
}Masina;

Masina* newMasina(char* nrI, char* model, char* categ);

char* getNrI(Masina* m);
char* getModel(Masina* m);
char* getCateg(Masina* m);

void distructorMasina(Masina* m);

//typedef void (*destructorLista)(Lista *l);
//typedef void (*destructorMasina)(Masina *m);
