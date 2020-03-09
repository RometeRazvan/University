#pragma once
#include "Repository.h"

typedef int(*ValidatorMasina)(ElemT);

typedef struct {
	ValidatorMasina validatorMasina;
}Validator;

Validator* newValidator(ValidatorMasina valmas);

void distructorValidator(Validator* v);

int valideazaMasina(Masina* m);