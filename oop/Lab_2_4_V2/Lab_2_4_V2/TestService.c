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

	assert(adauga(s, "CJ 20 TRM", "2013", "MARdasdE") == 0);

	distructorService(s);
}

void testActualizeaza() {
	Serv* s = generateService();

	actualizeaza(s, 2, "CJ 11 TRM", "2015", "DUSTER");

	Masina* m = getMasinaS(s, 2);

	assert(strcmp(getNrI(m), "CJ 11 TRM") == 0);
	assert(strcmp(getModel(m), "2015") == 0);
	assert(strcmp(getCateg(m), "DUSTER") == 0);

	assert(actualizeaza(s, -1, "CJ 11 TRM", "2015", "DUSTER") == 0);

	distructorService(s);

}

void testInchiriazaSiReturneaza() {
	Serv* s = generateService();

	assert(inchiriaza(s, -1) == 0);

	inchiriaza(s, 0);
	inchiriaza(s, 0);
	inchiriaza(s, 0);
	inchiriaza(s, 0);

	assert(strcmp(getModel(getMasinaSI(s, 0)), "2010") == 0);
	assert(strcmp(getModel(getMasinaSI(s, 1)), "2011") == 0);
	assert(strcmp(getModel(getMasinaSI(s, 2)), "2012") == 0);
	assert(strcmp(getModel(getMasinaSI(s, 3)), "2013") == 0);
	assert(getLgInc(s) == 4);

	Lista* l = getListaInc(s);

	assert(getLg(l) == 4);

	assert(returneaza(s, -1) == 0);

	returneaza(s, 1);
	returneaza(s, 0);
	returneaza(s, 1);
	returneaza(s, 0);

	assert(strcmp(getModel(getMasinaS(s, 0)), "2011") == 0);
	assert(strcmp(getModel(getMasinaS(s, 1)), "2010") == 0);
	assert(strcmp(getModel(getMasinaS(s, 2)), "2013") == 0);
	assert(strcmp(getModel(getMasinaS(s, 3)), "2012") == 0);

	l = getListaMasini(s);

	assert(getLg(l) == 4);

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
	distructorService(s);
}

void testSorteaza() {
	
	Serv* s = newService(distructorLista);

	adauga(s, "VS 11 TRM", "2018", "DUSTER8");
	adauga(s, "VS 12 TRM", "2016", "DUSTER6");
	adauga(s, "VS 13 TRM", "2011", "DUSTER1");
	adauga(s, "VS 14 TRM", "2017", "DUSTER7");
	adauga(s, "VS 15 TRM", "2014", "DUSTER4");
	adauga(s, "VS 16 TRM", "2013", "DUSTER3");
	adauga(s, "VS 17 TRM", "2015", "DUSTER5");
	adauga(s, "VS 18 TRM", "2012", "DUSTER2");

	Lista* l = sorteaza(s, "model", 1);

	assert(strcmp(getModel(getMasinaR(l, 0)), "2011") == 0);
	assert(strcmp(getModel(getMasinaR(l, 1)), "2012") == 0);
	assert(strcmp(getModel(getMasinaR(l, 2)), "2013") == 0);
	assert(strcmp(getModel(getMasinaR(l, 3)), "2014") == 0);
	assert(strcmp(getModel(getMasinaR(l, 4)), "2015") == 0);
	assert(strcmp(getModel(getMasinaR(l, 5)), "2016") == 0);
	assert(strcmp(getModel(getMasinaR(l, 6)), "2017") == 0);
	assert(strcmp(getModel(getMasinaR(l, 7)), "2018") == 0);

	distructorLista(l);

	l = sorteaza(s, "model", 0);

	assert(strcmp(getModel(getMasinaR(l, 7)), "2011") == 0);
	assert(strcmp(getModel(getMasinaR(l, 6)), "2012") == 0);
	assert(strcmp(getModel(getMasinaR(l, 5)), "2013") == 0);
	assert(strcmp(getModel(getMasinaR(l, 4)), "2014") == 0);
	assert(strcmp(getModel(getMasinaR(l, 3)), "2015") == 0);
	assert(strcmp(getModel(getMasinaR(l, 2)), "2016") == 0);
	assert(strcmp(getModel(getMasinaR(l, 1)), "2017") == 0);
	assert(strcmp(getModel(getMasinaR(l, 0)), "2018") == 0);

	distructorLista(l);

	l = sorteaza(s, "categ", 1);

	assert(strcmp(getCateg(getMasinaR(l, 0)), "DUSTER1") == 0);
	assert(strcmp(getCateg(getMasinaR(l, 1)), "DUSTER2") == 0);
	assert(strcmp(getCateg(getMasinaR(l, 2)), "DUSTER3") == 0);
	assert(strcmp(getCateg(getMasinaR(l, 3)), "DUSTER4") == 0);
	assert(strcmp(getCateg(getMasinaR(l, 4)), "DUSTER5") == 0);
	assert(strcmp(getCateg(getMasinaR(l, 5)), "DUSTER6") == 0);
	assert(strcmp(getCateg(getMasinaR(l, 6)), "DUSTER7") == 0);
	assert(strcmp(getCateg(getMasinaR(l, 7)), "DUSTER8") == 0);

	distructorLista(l);

	l = sorteaza(s, "categ", 0);

	assert(strcmp(getCateg(getMasinaR(l, 7)), "DUSTER1") == 0);
	assert(strcmp(getCateg(getMasinaR(l, 6)), "DUSTER2") == 0);
	assert(strcmp(getCateg(getMasinaR(l, 5)), "DUSTER3") == 0);
	assert(strcmp(getCateg(getMasinaR(l, 4)), "DUSTER4") == 0);
	assert(strcmp(getCateg(getMasinaR(l, 3)), "DUSTER5") == 0);
	assert(strcmp(getCateg(getMasinaR(l, 2)), "DUSTER6") == 0);
	assert(strcmp(getCateg(getMasinaR(l, 1)), "DUSTER7") == 0);
	assert(strcmp(getCateg(getMasinaR(l, 0)), "DUSTER8") == 0);

	distructorLista(l);

	l = sorteaza(s, "123", 1);

	distructorLista(l);
	distructorService(s);
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