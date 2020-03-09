#include "Service.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#pragma once

Serv* generateService() {
	Serv* s = newService(distructorLista);

	adauga(s, "CJ 07 TRM", "2010", "SUV");
	adauga(s, "CJ 08 TRM", "2011", "MINI");
	adauga(s, "CJ 09 TRM", "2012", "GOLF");
	adauga(s, "CJ 20 TRM", "2013", "MARE");

	return s;
}

void testCreate() {
	Serv* s = newService(distructorLista);
	distructorService(s);
}

void testAdauga() {

	Serv* s = newService(distructorLista);
	
	adauga(s, "CJ 07 SRT", "2010", "SUV");
	adauga(s, "CJ 08 TRM", "2011", "MINI");
	adauga(s, "CJ 09 TRM", "2012", "GOLF");
	adauga(s, "CJ 20 TRM", "2013", "MARE");

	assert(getLgLista(s) == 4);

	distructorService(s);
}

void testActualizeaza() {
	Serv* s = generateService();

	actualizeaza(s, 2, "CJ 11 TRM", "2015", "GOLF123");

	Masina* m = getMasinaS(s, 2);

	assert(strcmp(getNrI(m), "CJ 11 TRM") == 0);
	assert(strcmp(getModel(m), "2015") == 0);
	assert(strcmp(getCateg(m), "GOLF123") == 0);

	distructorService(s);

}

void testInchiriazaSiReturneaza() {
	Serv* s = generateService();

	inchiriaza(s, 0);
	inchiriaza(s, 0);
	inchiriaza(s, 0);
	inchiriaza(s, 0);

	assert(strcmp(getModel(getMasinaSI(s, 0)), "2010") == 0);
	assert(strcmp(getModel(getMasinaSI(s, 1)), "2011") == 0);
	assert(strcmp(getModel(getMasinaSI(s, 2)), "2012") == 0);
	assert(strcmp(getModel(getMasinaSI(s, 3)), "2013") == 0);
	assert(getLgInc(s) == 4);

	returneaza(s, 1);
	returneaza(s, 0);
	returneaza(s, 1);
	returneaza(s, 0);

	assert(strcmp(getModel(getMasinaS(s, 0)), "2011") == 0);
	assert(strcmp(getModel(getMasinaS(s, 1)), "2010") == 0);
	assert(strcmp(getModel(getMasinaS(s, 2)), "2013") == 0);
	assert(strcmp(getModel(getMasinaS(s, 3)), "2012") == 0);

	distructorService(s);
}

void testFiltreaza() {

	Serv* s = generateService();

	adauga(s, "CJ 07 SRT", "2010", "SUV");
	adauga(s, "CJ 07 RTD", "2011", "SUV");
	adauga(s, "CJ 07 SRT", "2011", "SUV");
	adauga(s, "CJ 07 MGS", "2010", "SUV");

	Lista* l = filtreaza(s, "2010", "SUV");

	assert(strcmp(getNrI(getMasinaR(l, 0)), "CJ 07 TRM") == 0);
	assert(strcmp(getNrI(getMasinaR(l, 1)), "CJ 07 SRT") == 0);
	assert(strcmp(getNrI(getMasinaR(l, 2)), "CJ 07 MGS") == 0);
	
	distructorLista(l);
}

void testSorteaza() {
	/*Serv* s = newService(distructorLista);

	adauga(s, "CJ 07 SRT", "2013", "SUV");
	adauga(s, "CJ 07 RTD", "2011", "SUV");
	adauga(s, "CJ 07 SRT", "2012", "SUV");
	adauga(s, "CJ 07 MGS", "2010", "SUV");

	//sorteaza(s, "model", 1);

	/*assert(strcmp(getModel(getMasinaS(s, 1)), "2010") == 0);
	assert(strcmp(getModel(getMasinaS(s, 1)), "2011") == 0);
	assert(strcmp(getModel(getMasinaS(s, 1)), "2012") == 0);
	assert(strcmp(getModel(getMasinaS(s, 1)), "2013") == 0);*/

	//distructorService(s);
}

void testServiceAll() {
	testCreate();
	testAdauga();
	testActualizeaza();
	testInchiriazaSiReturneaza();
	testFiltreaza();
	testSorteaza();

	printf("Finalizare testService !\n");
}