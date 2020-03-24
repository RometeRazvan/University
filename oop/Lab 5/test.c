#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "test.h"
#include "domain.h"
#include "repo.h"
#include "medicamentService.h"


void testCreeareMed() {
	char name[20] = "Paracetamol";
	Medicament med = createMed(0, name, 10, 15);
	assert(med.code == 0);
	assert(strcmp(getName(med), "Paracetamol") == 0);
	assert(getConcentration(med) == 10);
	assert(getCantity(med) == 15);
	destroyMed(&med);
}

void testCreeareLista() {
	MedList lista = createList();
	assert(lista.lenght == 0);
	destroy(&lista);
}

void testAdaugareMedicament() {
	MedList lista = createList();
	assert(addMed(&lista, createMed(0, "Paracetamol", 10, 15)) == 0);
	assert(lista.lenght == 1);
	assert(lista.elems[0].code == 0);
	assert(addMed(&lista, createMed(1, "Agocalmin", 2, -5)) == 3);//test pentru validare
	assert(addMed(&lista, createMed(2, "Nurofen", 100, 20)) == 0);

	//test pentru modificarea cantitatii in caz ca deja exista produsul
	assert(addMed(&lista, createMed(0, "Paracetamol", 10, 10)) == 0);
	assert(getCantity(lista.elems[0]) == 10);

	//test obtinere element din lista
	assert(getCode(getElement(&lista, 0)) == 0);

	//test reallocation
	assert(addMed(&lista, createMed(3, "Teraflu", 44, 30)) == 0);

	//test distrugere lista
	destroy(&lista);
	assert(len(&lista) == 0);
}

void testActualizareMedicament() {
	Medicament med1 = createMed(0, "Paracetamol", 10, 15);
	MedList lista = createList();
	assert(addMed(&lista, med1) == 0);
	assert(lista.lenght == 1);
	//nume
	assert(updateName(&lista, 0, "Marcel") == 0);
	assert(strcmp(lista.elems[0].name, "Marcel") == 0);
	assert(updateName(&lista, 0, "") == 1);// validare
	//concentratie
	assert(updateConcentration(&lista, 0, 12) == 0);
	assert(lista.elems[0].concentration == 12);
	assert(updateConcentration(&lista, 0, -1) == 2);//validare
	destroy(&lista);
}

void testStergerestoc() {
	MedList lista = createList();
	assert(addMed(&lista, createMed(0, "Paracetamol", 10, 15)) == 0);
	assert(lista.lenght == 1);
	deleteStocks(&lista, 0);
	assert(lista.elems[0].cantity == 0);
	destroy(&lista);
}

void testComparareElemente() {
	Medicament med1 = createMed(0, "Abc", 10, 15);
	Medicament med2 = createMed(2, "Nurofen", 100, 20);
	assert(cmpName(med1, med2) == -1);
	assert(cmpCantity(med1, med2) == -1);
	assert(cmpCantity(med2, med1) == 1);
	setCantity(&med1, 20);
	assert(cmpCantity(med1, med2) == 0);
	destroyMed(&med1);
	destroyMed(&med2);
}

void testSortareNume() {
	Medicament med1 = createMed(1, "a", 100, 20);
	Medicament med2 = createMed(0, "b", 10, 15);
	Medicament med3 = createMed(2, "c", 100, 25);
	MedList lista = createList();

	assert(addMed(&lista, med2) == 0);
	assert(addMed(&lista, med1) == 0);
	assert(addMed(&lista, med3) == 0);

	MedList l = sortNameAsc(&lista);
	assert(getCode(getElement(&l, 0)) == 1);
	destroy(&l);
	l = sortNameDesc(&lista);
	assert(getCode(getElement(&l, 0)) == 2);
	destroy(&l);
	destroy(&lista);
}

void testSortareCantitate() {
	MedList lista = createList();
	assert(addMed(&lista, createMed(0, "B", 10, 15)) == 0);
	assert(addMed(&lista, createMed(2, "A", 100, 20)) == 0);

	MedList l = sortCantityAsc(&lista);
	assert(getCantity(getElement(&l, 0)) == 15);
	destroy(&l);
	l = sortCantityDesc(&lista);
	assert(getCantity(getElement(&l, 0)) == 20);
	destroy(&l);
	destroy(&lista);
}

void testCopieMedicament() {
	Medicament med1 = createMed(0, "B", 10, 15);
	Medicament med2 = createMed(2, "A", 100, 20);
	MedList lista = createList();

	assert(addMed(&lista, med1) == 0);
	assert(addMed(&lista, med2) == 0);

	cpyMedicament(&lista.elems[0], lista.elems[1]);
	assert(getCode(lista.elems[0]) == 2);
	destroy(&lista);
}

void testFiltrareCantitate() {
	MedList lista = createList();
	assert(addMed(&lista, createMed(0, "B", 10, 20)) == 0);
	assert(addMed(&lista, createMed(2, "A", 100, 15)) == 0);
	MedList l = filterCantity(&lista, 15);
	assert(getCantity(getElement(&l, 0)) == 15);
	destroy(&l);
	destroy(&lista);
}

void testFiltrareNume() {
	MedList lista = createList();
	assert(addMed(&lista, createMed(0, "Bcd", 10, 15)) == 0);
	assert(addMed(&lista, createMed(1, "Acd", 100, 20)) == 0);
	assert(addMed(&lista, createMed(2, "Ace", 123, 25)) == 0);
	MedList l = filterName(&lista, "A");
	assert(getCantity(getElement(&lista, 1)) == 20);
	destroy(&l);
	destroy(&lista);
}

void testDestroy() {
	Medicament med1 = createMed(0, "A", 10, 15);
	MedList lista = createList();
	destroyMed(&med1);
	assert(med1.name == NULL);
	destroy(&lista);

}

void run_tests() {
	testCreeareMed();
	testCreeareLista();
	testAdaugareMedicament();
	testActualizareMedicament();
	testStergerestoc();
	testComparareElemente();
	testCopieMedicament();
	testSortareNume();
	testSortareCantitate();
	testFiltrareCantitate();
	testFiltrareNume();
	testDestroy();
	printf("Tests PASSED!!!\n");
}