typedef struct {
	char* nrI, *model, *categ;
}Masina;

Masina* newMasina(char* nrI, char* model, char* categ);

Masina newMasinaS(char* nrI, char* model, char* categ);

char* getNrI(Masina *m);
char* getModel(Masina *m);
char* getCateg(Masina *m);

char* getNrI(Masina* m);
char* getModel(Masina* m);
char* getCateg(Masina* m);

char* getNrIS(Masina m);
char* getModelS(Masina m);
char* getCategS(Masina m);

void destructorMasina(Masina* m);

//typedef void (*destructorLista)(Lista *l);
//typedef void (*destructorMasina)(Masina *m);
