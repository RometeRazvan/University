#include "TestDomain.h"
#include "Domain.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void testNew() {
	Masina m = newMasina("CJ 04 TRM", "Electric", "Duster");
	assert(strcmp(getNrI(m), "CJ 04 TRM") == 0 );
	assert(strcmp(getModel(m), "Electric") == 0 );
	assert(strcmp(getCateg(m), "Duster") == 0 );

	Lista l = newLista();
	assert(getMax(l) == 1);
	addMasina(l, m);
	printf("%d\n", l.max);
	assert(getMax(l) == 2);
}

void testAllDomain() {
	testNew();
	printf("Finalizare TestDomain !!!\n");
}