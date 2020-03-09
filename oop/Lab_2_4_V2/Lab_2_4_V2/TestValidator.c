#include "TestValidator.h"
#include "Validator.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void testVal() {
	Validator* v = newValidator(valideazaMasina);
	Masina* m1 = newMasina("CJ 07 TRM", "2010", "SUV");
	Masina* m2 = newMasina("CJ 08 TRM", "2011", "MINI");
	Masina* m3 = newMasina("CJ 09 TRM", "2012", "GOLF");
	Masina* m4 = newMasina("CJ 20 TRM", "2013", "MARE");

	assert(v->validatorMasina(m1) == 1);
	assert(v->validatorMasina(m2) == 1);
	assert(v->validatorMasina(m3) == 1);
	assert(v->validatorMasina(m4) == 1);

	distructorMasina(m1);
	distructorMasina(m2);
	distructorMasina(m3);
	distructorMasina(m4);

	distructorValidator(v);
}

void testValidatorAll() {
	testVal();

	printf("Finalizare tesdt validatorAll !");
}