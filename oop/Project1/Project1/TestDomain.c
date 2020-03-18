#include "TestDomain.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void testCreate() {
	Masina m = newMasina("VS 10 TRM", "2010", "Duster");

	assert(strcmp(getNrI(m), "VS 10 TRM") == 0);
	assert(strcmp(getModel(m), "2010") == 0);
	assert(strcmp(getCateg(m), "Duster") == 0);
}

void testDomainAll() {

	testCreate();

	printf("Finalizare testDomainAll !\n");
}