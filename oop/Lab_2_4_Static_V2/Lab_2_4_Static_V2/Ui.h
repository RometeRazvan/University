#pragma once
#include "Service.h"

typedef struct {
	Serv s;
}Ui;

Ui newUi();

void adaugaUi(Ui *ui);

void actualizeazaUi(Ui* ui);

void inchiriazaSauReturneazaUi(Ui* ui);

void filtreazaUi(Ui* ui);

void sorteazaui(Ui* ui);

void afiseazaTotUi(Ui* ui);

void runUi(Ui* ui);
