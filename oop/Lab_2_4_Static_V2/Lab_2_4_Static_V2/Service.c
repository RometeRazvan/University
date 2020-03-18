#include "Service.h"
#include <stdio.h>

Serv newService() {
	Serv s;
	s.masini = newLista();
	s.inchirieri = newLista();
	return s;
}

Lista getListaM(Serv s) {
	return s.masini;
}

Lista getListaI(Serv s) {
	return s.inchirieri;
}

Masina getSM(Serv s, int poz) {
	return getR(s.masini, poz);
}

Masina getSI(Serv s, int poz) {
	return getR(s.inchirieri, poz);
}

int getLgM(Serv s) {
	return getLg(s.masini);
}

int getLgI(Serv s) {
	return getLg(s.inchirieri);
}

void adaugaS(Serv* s, char* nrI, char* model, char* categ) {
	//printf("%d\n", getLg(s->masini));
	Masina m = newMasina(nrI, model, categ);
	adaugaR(&s->masini, m);
	//printf("%d\n", getLg(s->masini));
}

void stergeS(Serv* s, int poz) {
	stergeR(&s->masini, poz);
}

void actualizeazaS(Serv* s, int poz, char* nrI, char* model, char* categ) {
	Masina m = newMasina(nrI, model, categ);
	modificaR(&s->masini, poz, m);
}

void inchiriaza(Serv* s, int poz) {
	Masina m = stergeR(&s->masini, poz);
	adaugaR(&s->inchirieri, m);
}

void returneazaS(Serv* s, int poz) {
	Masina m = stergeR(&s->inchirieri, poz);
	adaugaR(&s->masini, m);
}

Lista filtreaza(Serv* s, char* model, char* categ) {
	Lista l = newLista();

	for (int i = 0; i < getLgM(*s); ++i) {
		if ((strcmp(model, getModel(getSM(*s, i))) == 0)
			&& (strcmp(categ, getCateg(getSM(*s, i))) == 0))
			adaugaR(&l, getSM(*s, i));
	}

	return l;
}

Lista sorteaza(Serv* s, char* modelSauCateg, int crescSauDesc) {
	if (strcmp(modelSauCateg, "model") == 0) {
		if (crescSauDesc > 0)
			return sortList(s->masini, modelCrescator);
		else return sortList(s->masini, modelDescrescator);
	}
	else if (strcmp(modelSauCateg, "categ") == 0) {
		if (crescSauDesc > 0)
			return sortList(s->masini, categCrescator);
		else return sortList(s->masini, categDescrescator);
	}

	Lista l = newLista();

	return l;
}