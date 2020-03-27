#include <stdio.h>
#include "domain.h"
#include "repo.h"
#include "medicamentService.h"

void adaugaUI(MedList* medicamente) {
	int code, concentration, cantity;
	char name[20];
	printf("Introduce cod medicament: \n");
	scanf_s("%d", &code);
	printf("Introduce nume: \n");
	scanf_s("%20s", name, 20);
	printf("Introduce concentratie: \n");
	scanf_s("%d", &concentration);
	printf("Introduce cantitate: \n");
	scanf_s("%d", &cantity);

	int error = addMed(medicamente, createMed(code, name, concentration, cantity));
	if (error == 1)
		printf("Numele este incorect!\n");
	else if (error == 2)
		printf("Cantitatea este negativa!");
	else if (error == 3)
		printf("Concentratia este negativa!");
}

void actualizareUI(MedList* lista) {
	printf("Introduce id-ul medicamentului: ");
	int code;
	scanf_s("%d", &code);
	printf("\n1. Actualizare nume \n2. Actualizare concentratie\nOptiune: ");
	int optiune;
	scanf_s("%d", &optiune);
	switch (optiune)
	{
	case 1:
		printf("Introduce numele nou: ");
		char name[20];
		scanf_s("%20s", name, 20);
		updateName(lista, code, name);
		break;
	case 2:
		printf("Introduce conentratia noua: ");
		int concentration;
		scanf_s("%d", &concentration);
		updateConcentration(lista, code, concentration);
		break;
	default:
		printf("Optiune gresita!! Nu s-a modificat nimic.\n");
	}

}

void sortareElementeUI(MedList* lista) {

	MedList listaNoua;

	printf("\n1. Sortare dupa nume crescator\n2. Sortare dupa nume descrescator\n3. Sortare dupa cantitate crescator\n4. Sortare dupa cantitate descrescator\n");
	int optiune;
	scanf_s("%d", &optiune);
	switch (optiune)
	{
	case 1:
		listaNoua = sortNameAsc(lista);
		showMedList(&listaNoua);
		break;
	case 2:
		listaNoua = sortNameAsc(lista);
		showMedList(&listaNoua);
		break;
	case 3:
		listaNoua = sortNameAsc(lista);
		showMedList(&listaNoua);
		break;
	case 4:
		listaNoua = sortNameAsc(lista);
		showMedList(&listaNoua);
		break;
	default:
		printf("Optiune gresita!! Nu s-a modificat nimic.\n");
	}
	destroy(&listaNoua);
}

void tiparesteToateUI(MedList* lista) {
	showMedList(lista);
}

void stergereStocUI(MedList* lista) {
	int code;
	printf("Introduce codul medicamentului: \n");
	scanf_s("%d", &code);
	deleteStocks(lista, code);
}

void filtrareElementeUI(MedList* lista) {

	MedList listaNoua = createList();

	printf("\n1. Filtrare dupa cantitate \n2. Filtrare dupa nume\n");
	int optiune;
	scanf_s("%d", &optiune);

	switch (optiune)
	{
	case 1:
		printf("Introduce cantitatea maxima: ");
		int cantity;
		scanf_s("%d", &cantity);
		listaNoua = filterCantity(lista, cantity);
		showMedList(&listaNoua);
		break;
	case 2:
		printf("Introduce numele nou: ");
		char litera[1];
		scanf_s("%1s", litera, 1);
		listaNoua = filterCantity(lista, litera);
		showMedList(&listaNoua);
		break;
	default:
		printf("Optiune gresita!! Nu s-a modificat nimic.\n");
	}
	destroy(&listaNoua);
}

/*
	Show every med from the list
*/
void showMedList(MedList* lista)
{
	printf("Medicamente: \n");
	for (int i = 0; i < len(lista); i++)
		printf("Id:%d, Nume:%s, Concentratie:%d, Cantitate:%d \n", lista->elems[i].code, lista->elems[i].name, lista->elems[i].concentration, lista->elems[i].cantity);
		//printf("id:%d\n", lista->elems[i].code);
}

/*
	Run the UI
*/
void ui_run(MedList* medicamente) {

	int run = 1;
	while (run) {
		printf("1. Adauga \n2. Actualizare \n3. Stergere stoc \n4. Sortare Medicamente \n5. Filtrare \n9. Tipareste tot \n0. Iesire \nComanda: ");
		int cmd = 0;
		scanf_s("%d", &cmd);
		switch (cmd)
		{
		case 1:
			adaugaUI(medicamente);
			break;
		case 2:
			actualizareUI(medicamente);
			break;
		case 3:
			stergereStocUI(medicamente);
			break;
		case 4:
			sortareElementeUI(medicamente);
			break;
		case 5:
			filtrareElementeUI(medicamente);
			break;
		case 9:
			tiparesteToateUI(medicamente);
			break;
		case 0:
			printf("BYE!!\n");
			run = 0;
			break;
		default:
			printf("Comanda invalida!!\n");
		}

		printf("\n");
	}
	destroy(medicamente);
}
