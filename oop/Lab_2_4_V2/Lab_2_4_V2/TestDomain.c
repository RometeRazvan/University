#include "Domain.h"
#include "TestDomain.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>



void testMasina() {
	Masina *m = newMasina("CJ 04 TRM", "Electric", "SUV");
	assert(strcmp(getNrI(m), "CJ 04 TRM") == 0);
	assert(strcmp(getCateg(m), "SUV") == 0);
	assert(strcmp(getModel(m), "Electric") == 0);
	
	distructorMasina(m);
}

void testDomainAll() {
	testMasina();

	printf("Finalizare testDomain !\n");
}