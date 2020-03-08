#include "Service.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

/*Serv* generateServ() {
	Serv* s = newServ();
	adauga(s, "IS 10 TRM", "2010", "SUV");
	adauga(s, "IS 11 TRM", "2011", "MINI");
	adauga(s, "IS 12 TRM", "2012", "GOLF");
	adauga(s, "IS 13 TRM", "2013", "LIMO");
	return s;
}

void testCreateService() {
	Serv* s = newServ();

	assert(getLgLista(s) == 0);
	assert(getLgInchirieri(s) == 0);

	destructorService(s);
}

void testAdaugare() {
	Serv* s = generateServ();

	assert(getLgLista(s) == 4);

	Masina* m = getMasinaS(s, 3);

	assert(strcmp(getModel(m), "2013") == 0);
}

void testActualizare() {
	Serv* s = generateServ();

	actualizeaza(s, 2, "IS 10 TRM", "2010", "SUV");

	Masina* m = getMasinaS(s, 3);

	assert(strcmp(getModel(m), "2013") == 0);
}

void testInchiriereSiReturnare() {
	Serv* s = generateServ();

	inchiriaza(s, 0);
	assert(getLgLista(s) == 3);
	printf("%s\n", getModel(getMasinaS(s, 0)));
	inchiriaza(s, 2);
	assert(getLgLista(s) == 2);
	printf("%s\n", getModel(getMasinaIS(s, 1)));
	assert(strcmp(getModel(getMasinaIS(s, 0)), "2010") == 0);
	assert(strcmp(getModel(getMasinaIS(s, 1)), "2013") == 0);
}

void testFiltrare() {}

void testSortare() {}

void testAllService() {

	testCreateService();
	testAdaugare();
	testActualizare();
	//testInchiriereSiReturnare();
	testFiltrare();
	testSortare();

	printf("Finalizare testService !\n");
}*/