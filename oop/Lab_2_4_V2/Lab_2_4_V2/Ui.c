#include "Ui.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* 0
void adaugaMasina(Ui* ui) {
	char* nrI, * model, * categ;
	printf("Numarul de inmatriculare al masinii: ");
	scanf("%s", nrI);
	printf("Modelul masinii: ");
	scanf("%s", model);
	printf("Categoria masinii: ");
	scanf("%s", categ);
	adauga(ui->serv, nrI, model, categ);
}

void run(Ui* ui) {

	printf("Meniu aplicatie\n");
		char* menu = "1 - Afiseaza masini\n2 - Adauga masina\n3 - Sterge masina\n4 - Actualizeaza masina";

}

Ui* newUi(Distructor f) {
	Ui* ui = malloc(sizeof(Ui));
	ui->f = f;
	ui->serv = newService(distructorLista);
	return ui;
}

void distructorUi(Ui* ui) {
	ui->f(ui->serv);
	free(ui);
}*/