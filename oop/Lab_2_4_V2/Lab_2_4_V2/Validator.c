#include "Validator.h"
#include <stdlib.h>

int valideazaMasina(Masina* m) {
	return 1;
}

Validator* newValidator(ValidatorMasina valmas) {
	Validator* v = malloc(sizeof(Validator));
	v->validatorMasina = valmas;
	return v;
}

void distructorValidator(Validator* v) {
	free(v);
}