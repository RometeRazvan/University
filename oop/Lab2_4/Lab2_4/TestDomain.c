#include "TestDomain.h"
#include "Domain.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
void testGettersAndSetters() {

}

void testNew() {
	Masina m = newMasina("CJ 04 TRM", "Electric", "Duster");
	assert(strcmp(getNrI(m), "CJ 04 TRM") == 0 );
	assert(strcmp(getModel(m), "Electric") == 0 );
	assert(strcmp(getCateg(m), "Duster") == 0 );
	setNrI(m, "CJ");
	printf("%s\n", getNrI(m));
	//setModel(m, "Ele");
	//setCateg(m,"WW");
	assert(strcmp(getNrI(m), "CJ") == 0);
	//assert(strcmp(getModel(m), "Ele") == 0);
	//assert(strcmp(getCateg(m), "WW") == 0);
}

void testAllDomain() {
	testGettersAndSetters();
	testNew();
	printf("Finalizare TestDomain !!!\n");
}