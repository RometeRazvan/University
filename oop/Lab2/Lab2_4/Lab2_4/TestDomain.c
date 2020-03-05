#include "TestDomain.h"
#include "Domain.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
void testGettersAndSetters() {

}

void testNew() {
	Masina m = newMasina("VS 04 TRM", "Electric", "Duster");
	assert(strcmp(getNrI(m), "VS 04 TRM") == 0 );
	char* str = getModel(m);
	//assert(strcmp(getModel(m), "Electric") == 0 );
	//assert(strcmp(getCateg(m), "Duster") == 0 );
}

void testAllDomain() {
	testGettersAndSetters();
	testNew();
	printf("Finalizare TestDomain !!!\n");
}