#include "Ui.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Ui* newUi(Distructor f) {
	Ui* ui = malloc(sizeof(Ui));
	ui->f = f;
	ui->serv = newService(distructorLista);
	return ui;
}

void distructorUi(Ui* ui) {
	ui->f(ui->serv);
	free(ui);
}

void afiseazaTotUi(Ui* ui) {

	char* menu = "1 - Afiseaza service\n2 - Afiseaza inchirieri\n";

	int comanda;

	printf("%s", menu);

	scanf_s("%d", &comanda);

	if (comanda == 1) {
		Lista* l = getListaMasini(ui->serv);

		for (int i = 0; i < getLg(l); ++i) {
			Masina* m = getMasinaR(l, i);
			printf("%d %s %s %s\n", i, getNrI(m), getModel(m), getCateg(m));
		}
	}
	else {
		Lista* l = getListaInc(ui->serv);

		for (int i = 0; i < getLg(l); ++i) {
			Masina* m = getMasinaR(l, i);
			printf("%d %s %s %s\n", i, getNrI(m), getModel(m), getCateg(m));
		}
	}

}

void adaugaUi(Ui* ui) {

	char nrI[20], model[20], categ[20];

	printf("Numarul de inmatriculare este: ");
	scanf_s("%s", nrI, 20);

	printf("Modelul este: ");
	scanf_s("%s", model, 20);

	printf("Categoria este: ");
	scanf_s("%s", categ, 20);

	if (adauga(ui->serv, nrI, model, categ) == 1) {
		printf("Masina a fost adaugata!");
	}
	else printf("Eroare la adaugarea masinii !");

}

void actualizeazaUi(Ui* ui) {

	int id = -1;
	char nrI[20], model[20], categ[20];

	printf("Id-ul masinii este : ");
	scanf_s("%d", &id);

	printf("Numarul de inmatriculare este: ");
	scanf_s("%s", nrI, 20);

	printf("Modelul este: ");
	scanf_s("%s", model, 20);

	printf("Categoria este: ");
	scanf_s("%s", categ, 20);

	if (actualizeaza(ui->serv, id, nrI, model, categ) == 1) {
		printf("Masina a fost actualizata!");
	}
	else printf("Eroare la actualizarea masinii !");

}

void inchiriazaSiReturneazaUi(Ui* ui) {

	char* menu = "\n1 - Inchiriaza\n2 - Returneaza\n";
	int comanda = -1;

	printf("%s\n", menu);

	printf("Comanda este: ");
	scanf_s("%d", &comanda);

	if (comanda == 1) {
		int id = -1;
		printf("Id-ul masinii este: ");
		scanf_s("%d", &id);
		if (inchiriaza(ui->serv, id) == 0)
			printf("ID invalid");
	}
	else if (comanda == 2) {
		int id = -1;
		printf("Id-ul masinii este: ");
		scanf_s("%d", &id);
		if (returneaza(ui->serv, id) == 0)
			printf("Id invalid");
	}
	else printf("Comanda INVALIDA!!!!!");

}

void filtreazaUi(Ui* ui) {

	char model[20], categ[20];

	printf("Modelul este: ");
	scanf_s("%s", model, 20);

	printf("Categoria este: ");
	scanf_s("%s", categ, 20);

	Lista* l = filtreaza(ui->serv, model, categ);

	for (int i = 0; i < getLg(l); ++i) {
		Masina* m = getMasinaR(l, i);
		printf("%s %s %s\n", getNrI(m), getModel(m), getCateg(m));
	}

	distructorLista(l);
}

void sorteazaUi(Ui* ui) {

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

	Lista *l = sorteaza(ui->serv, model, comanda2);

	for (int i = 0; i < getLg(l); ++i) {
		Masina* m = getMasinaR(l, i);
		printf("%s %s %s\n", getNrI(m), getModel(m), getCateg(m));
	}

	distructorLista(l);
}

void run(Ui* ui) {

	char* menu = "\n1 - Afiseaza masini\n2 - Adauga masina\n3 - Actualizeaza masina\n4 - Inchiriaza sau returneaza masina\n5 - Filtreaza masini\n6 - Sorteaza masini\n0 - Opreste aplicatia\n";

	int val = 1;

	printf("%s", menu);

	while (val) {

		printf("\nComanda este: ");

		int comanda = 0;

		scanf_s("%d", &comanda);

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
			inchiriazaSiReturneazaUi(ui);
			break;

		case 5:
			filtreazaUi(ui);
			break;

		case 6:
			sorteazaUi(ui);
			break;

		case 0:
			val = 0;
			break;
		}
	}

}