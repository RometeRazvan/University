#include "TestValidator.h"
#include "Validator.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void testVal() {
	Validator* v = newValidator(valideazaMasina);
	Masina* m1 = newMasina("CJ 07 TRM", "2010", "asdasd");
	Masina* m2 = newMasina("CJ 08 TRM", "20dasdas11", "MINI");
	Masina* m3 = newMasina("CJ 09+TRM", "2012", "GOLF");
	Masina* m4 = newMasina("CJ-20 TRM", "2013", "MARE");
	Masina* m5 = newMasina("CJ 20_TRM", "2013", "MARE");
	Masina* m6 = newMasina("CJ 20_TRMasdasd", "2013", "MARE");
	Masina* m7 = newMasina("1J 20_TRM", "2013", "MARE");
	Masina* m8 = newMasina("CJ A0_TRM", "2013", "MARE");
	Masina* m9 = newMasina("CJ 20_TR1", "2013", "MARE");
	Masina* m10 = newMasina("CJ 20_TRM", "20sd", "MARE");
	Masina* m11 = newMasina("CJ 20_TRM", "1000", "MARE");

	assert(v->validatorMasina(m1) == 0);
	assert(v->validatorMasina(m2) == 0);
	assert(v->validatorMasina(m3) == 0);
	assert(v->validatorMasina(m4) == 1);
	assert(v->validatorMasina(m5) == 1);
	assert(v->validatorMasina(m6) == 0);
	assert(v->validatorMasina(m7) == 0);
	assert(v->validatorMasina(m8) == 0);
	assert(v->validatorMasina(m9) == 0);
	assert(v->validatorMasina(m10) == 0);
	assert(v->validatorMasina(m11) == 0);

	distructorMasina(m1);
	distructorMasina(m2);
	distructorMasina(m3);
	distructorMasina(m4);
	distructorMasina(m5);
	distructorMasina(m6);
	distructorMasina(m7);
	distructorMasina(m8);
	distructorMasina(m9);
	distructorMasina(m10);
	distructorMasina(m11);

	distructorValidator(v);
}

void testValidatorAll() {
	testVal();

	printf("Finalizare test validatorAll !");
}