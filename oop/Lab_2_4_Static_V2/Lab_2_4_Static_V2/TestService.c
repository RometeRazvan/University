#include "TestService.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

Serv generateSev() {
	Serv s = newService();

	adaugaS(&s, "VS 11 TRM", "2011", "Duster1");
	adaugaS(&s, "VS 12 TRM", "2012", "Duster2");
	adaugaS(&s, "VS 13 TRM", "2013", "Duster3");
	adaugaS(&s, "VS 14 TRM", "2014", "Duster4");

	return s;
}

void testCreateService() {

	Serv s = newService();

	assert(getLg(s.masini) == 0);
	assert(getLg(s.inchirieri) == 0);
}

void testAdaugaS() {

	Serv s = newService();

	adaugaS(&s, "VS 11 TRM", "2011", "Duster1");
	assert(strcmp(getModel(getSM(s, 0)), "2011") == 0);

	adaugaS(&s, "VS 12 TRM", "2012", "Duster2");
	assert(strcmp(getModel(getSM(s, 1)), "2012") == 0);

	adaugaS(&s, "VS 13 TRM", "2013", "Duster3");
	assert(strcmp(getModel(getSM(s, 2)), "2013") == 0);

	adaugaS(&s, "VS 14 TRM", "2014", "Duster4");
	assert(strcmp(getModel(getSM(s, 3)), "2014") == 0);

	assert(getLgM(s) == 4);

}

void testGet() {

	Serv s = generateSev();

	Lista l = getListaM(s);
	
	assert(getLg(l) == 4);

	l = getListaI(s);

	assert(getLg(l) == 0);

}

void testStergeS() {

	Serv s = generateSev();

	stergeS(&s, 0);

	assert(strcmp(getModel(getSM(s, 0)), "2012") == 0);

	assert(getLgM(s) == 3);

}

void testActualizare() {

	Serv s = generateSev();

	actualizeazaS(&s, 0, "VS 15 TRM", "2015", "Duster5");

	assert(strcmp(getModel(getSM(s, 0)), "2015") == 0);

}

void testInchiriereSiReturnare() {

	Serv s = generateSev();

	inchiriaza(&s, 0);
	inchiriaza(&s, 0);
	inchiriaza(&s, 0);
	inchiriaza(&s, 0);

	assert(getLgM(s) == 0);
	assert(getLgI(s) == 4);

	assert(strcmp(getModel(getSI(s, 0)), "2011") == 0);
	assert(strcmp(getModel(getSI(s, 1)), "2012") == 0);
	assert(strcmp(getModel(getSI(s, 2)), "2013") == 0);
	assert(strcmp(getModel(getSI(s, 3)), "2014") == 0);

	returneazaS(&s, 0);
	returneazaS(&s, 0);
	returneazaS(&s, 0);
	returneazaS(&s, 0);

	assert(getLgI(s) == 0);
	assert(getLgM(s) == 4);

	assert(strcmp(getModel(getSM(s, 0)), "2011") == 0);
	assert(strcmp(getModel(getSM(s, 1)), "2012") == 0);
	assert(strcmp(getModel(getSM(s, 2)), "2013") == 0);
	assert(strcmp(getModel(getSM(s, 3)), "2014") == 0);

}

void testFiltrare() {

	Serv s = newService();

	adaugaS(&s, "VS 11 TRM", "2011", "Duster1");
	adaugaS(&s, "VS 12 TRM", "2012", "Duster2");
	adaugaS(&s, "VS 13 TRM", "2013", "Duster3");
	adaugaS(&s, "VS 14 TRM", "2011", "Duster1");
	adaugaS(&s, "VS 15 TRM", "2011", "Duster1");
	adaugaS(&s, "VS 16 TRM", "2012", "Duster2");
	adaugaS(&s, "VS 17 TRM", "2013", "Duster3");
	adaugaS(&s, "VS 18 TRM", "2011", "Duster1");

	Lista l = filtreaza(&s, "2011", "Duster1");

	assert(strcmp(getNrI(getR(l, 0)), "VS 11 TRM") == 0);
	assert(strcmp(getNrI(getR(l, 1)), "VS 14 TRM") == 0);
	assert(strcmp(getNrI(getR(l, 2)), "VS 15 TRM") == 0);
	assert(strcmp(getNrI(getR(l, 3)), "VS 18 TRM") == 0);
}

void testSortare() {

	Serv s = newService();

	adaugaS(&s, "VS 11 TRM", "2018", "Duster8");
	adaugaS(&s, "VS 12 TRM", "2016", "Duster6");
	adaugaS(&s, "VS 13 TRM", "2011", "Duster1");
	adaugaS(&s, "VS 14 TRM", "2017", "Duster7");
	adaugaS(&s, "VS 15 TRM", "2014", "Duster4");
	adaugaS(&s, "VS 16 TRM", "2013", "Duster3");
	adaugaS(&s, "VS 17 TRM", "2015", "Duster5");
	adaugaS(&s, "VS 18 TRM", "2012", "Duster2");

	Lista l = sorteaza(&s, "model", 1);

	assert(strcmp(getModel(getR(l, 0)), "2011") == 0);
	assert(strcmp(getModel(getR(l, 1)), "2012") == 0);
	assert(strcmp(getModel(getR(l, 2)), "2013") == 0);
	assert(strcmp(getModel(getR(l, 3)), "2014") == 0);
	assert(strcmp(getModel(getR(l, 4)), "2015") == 0);
	assert(strcmp(getModel(getR(l, 5)), "2016") == 0);
	assert(strcmp(getModel(getR(l, 6)), "2017") == 0);
	assert(strcmp(getModel(getR(l, 7)), "2018") == 0);

	l = sorteaza(&s, "model", 0);

	assert(strcmp(getModel(getR(l, 7)), "2011") == 0);
	assert(strcmp(getModel(getR(l, 6)), "2012") == 0);
	assert(strcmp(getModel(getR(l, 5)), "2013") == 0);
	assert(strcmp(getModel(getR(l, 4)), "2014") == 0);
	assert(strcmp(getModel(getR(l, 3)), "2015") == 0);
	assert(strcmp(getModel(getR(l, 2)), "2016") == 0);
	assert(strcmp(getModel(getR(l, 1)), "2017") == 0);
	assert(strcmp(getModel(getR(l, 0)), "2018") == 0);

	l = sorteaza(&s, "categ", 1);

	assert(strcmp(getCateg(getR(l, 0)), "Duster1") == 0);
	assert(strcmp(getCateg(getR(l, 1)), "Duster2") == 0);
	assert(strcmp(getCateg(getR(l, 2)), "Duster3") == 0);
	assert(strcmp(getCateg(getR(l, 3)), "Duster4") == 0);
	assert(strcmp(getCateg(getR(l, 4)), "Duster5") == 0);
	assert(strcmp(getCateg(getR(l, 5)), "Duster6") == 0);
	assert(strcmp(getCateg(getR(l, 6)), "Duster7") == 0);
	assert(strcmp(getCateg(getR(l, 7)), "Duster8") == 0);

	l = sorteaza(&s, "categ", 0);

	assert(strcmp(getCateg(getR(l, 7)), "Duster1") == 0);
	assert(strcmp(getCateg(getR(l, 6)), "Duster2") == 0);
	assert(strcmp(getCateg(getR(l, 5)), "Duster3") == 0);
	assert(strcmp(getCateg(getR(l, 4)), "Duster4") == 0);
	assert(strcmp(getCateg(getR(l, 3)), "Duster5") == 0);
	assert(strcmp(getCateg(getR(l, 2)), "Duster6") == 0);
	assert(strcmp(getCateg(getR(l, 1)), "Duster7") == 0);
	assert(strcmp(getCateg(getR(l, 0)), "Duster8") == 0);

	l = sorteaza(&s, "123", 1);

}

void testServiceAll() {
	testCreateService();
	testAdaugaS();
	testGet();
	testStergeS();
	testActualizare();
	testInchiriereSiReturnare();
	testFiltrare();
	testSortare();

	printf("Finalizare testServiceAll !\n");
}