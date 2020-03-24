#include "Ui.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Ui newUi() {

	Ui ui;
	ui.s = newService();
	return ui;
}

void adaugaUi(Ui *ui) {

	char* nrI, * model, * categ;

	nrI = malloc(sizeof(char) * 20);
	model = malloc(sizeof(char) * 20);
	categ = malloc(sizeof(char) * 20);

	printf("Numarul de inmatriculare este: ");
	scanf_s("%s", nrI, 20);

	printf("Modelul este: ");
	scanf_s("%s", model, 20);

	printf("Categoria este: ");
	scanf_s("%s", categ, 20);

	adaugaS(&ui->s, nrI, model, categ);
}

void actualizeazaUi(Ui *ui) {

	int id = -1;
	char* nrI, * model, * categ;

	nrI = malloc(sizeof(char) * 20);
	model = malloc(sizeof(char) * 20);
	categ = malloc(sizeof(char) * 20);

	printf("Id-ul masinii este : ");
	scanf_s("%d", &id);

	printf("Numarul de inmatriculare este: ");
	scanf_s("%s", nrI, 20);

	printf("Modelul este: ");
	scanf_s("%s", model, 20);

	printf("Categoria este: ");
	scanf_s("%s", categ, 20);

	actualizeazaS(&ui->s, id, nrI, model, categ);

}

void inchiriazaSauReturneazaUi(Ui *ui) {

	char* menu = "\n1 - Inchiriaza\n2 - Returneaza\n";
	int comanda = -1;

	printf("%s\n", menu);

	printf("Comanda este: ");
	scanf_s("%d", &comanda);

	if (comanda == 1) {
		int id = -1;
		printf("Id-ul masinii este: ");
		scanf_s("%d", &id);
		inchiriaza(&ui->s, id);
	}
	else if (comanda == 2) {
		int id = -1;
		printf("Id-ul masinii este: ");
		scanf_s("%d", &id);
		returneazaS(&ui->s, id);
	}
	else printf("Comanda INVALIDA!!!!!");

}

void filtreazaUi(Ui *ui) {

	char model[20], categ[20];

	printf("Modelul este: ");
	scanf_s("%s", model, 20);

	printf("Categoria este: ");
	scanf_s("%s", categ, 20);

	Lista l = filtreaza(&ui->s, model, categ);

	for (int i = 0; i < getLg(l); ++i) {
		Masina m = getR(l, i);
		printf("%s %s %s\n", getNrI(m), getModel(m), getCateg(m));
	}

}

void sorteazaui(Ui *ui) {

	printf("\nmodel - Dupa model\ncateg - Dupa categorie");

	char model[20];
	
	printf("\nComanda este: ");
	scanf_s("%s", model, 20);

	printf("\n1 - Crescator\n-1 - Descrescator");

	int comanda2 = -1;

	printf("\nComanda este: ");
	scanf_s("%d", &comanda2);

	if (strcmp(model, "model") != 0 && strcmp(model, "categ") != 0) {
		printf("GRESIT!!!");
		return;
	}

	Lista l = sorteaza(&ui->s, model, comanda2);

	for (int i = 0; i < getLg(l); ++i) {
		Masina m = getR(l, i);
		printf("%s %s %s\n", getNrI(m), getModel(m), getCateg(m));
	}

}

void afiseazaTotUi(Ui *ui) {

	char* menu = "1 - Afiseaza service\n2 - Afiseaza inchirieri\n";
	
	int comanda;

	printf("%s", menu);

	scanf("%d", &comanda);

	if (comanda == 1) {
		Lista l = getListaM(ui->s);

		for (int i = 0; i < getLg(l); ++i) {
			Masina m = getR(l, i);
			printf("%d %s %s %s\n", i, getNrI(m), getModel(m), getCateg(m));
		}
	}
	else {
		Lista l = getListaI(ui->s);

		for (int i = 0; i < getLg(l); ++i) {
			Masina m = getR(l, i);
			printf("%d %s %s %s\n", i, getNrI(m), getModel(m), getCateg(m));
		}
	}

}

void runUi(Ui *ui) {

	char* menu = "\n1 - Afiseaza masini\n2 - Adauga masina\n3 - Actualizeaza masina\n4 - Inchiriaza sau returneaza masina\n5 - Filtreaza masini\n6 - Sorteaza masini\n0 - Opreste aplicatia\n";

	int val = 1;

	printf("%s", menu);

	while (val) {

		printf("\nComanda este: ");

		int comanda = 0;

		scanf("%d", &comanda);

		switch (comanda) {

		default:
			break;

		case 1:
			afiseazaTotUi(ui);
			break;

		case 2:
			adaugaUi(ui);
			break;

		case 3:
			actualizeazaUi(ui);
			break;

		case 4:
			inchiriazaSauReturneazaUi(ui);
			break;

		case 5:
			filtreazaUi(ui);
			break;
			
		case 6:
			sorteazaui(ui);
			break;

		case 0:
			val = 0;
			break;
		}
	}

}