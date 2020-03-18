#pragma once
#include "Service.h"

typedef struct {
	Serv* serv;
	Distructor f;
}Ui;

Ui* newUi(Distructor f);

void distructorUi(Ui* ui);

void afiseazaTotUi(Ui* ui);

void adaugaUi(Ui* ui);

void actualizeazaUi(Ui* ui);

void inchiriazaSiReturneazaUi(Ui* ui);

void filtreazaUi(Ui* ui);

void sorteazaUi(Ui* ui);

void run(Ui* ui);
