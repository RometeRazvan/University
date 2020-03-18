#include "Validator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int valideazaNrI(char* nrI) {

	char* nr = "0123456789";
	char* str = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
	char* sep = " -_";

	if (strlen(nrI) != 9)
		return 0;

	if (strchr(sep, nrI[2]) == NULL || strchr(sep, nrI[5]) == NULL)
		return 0;

	if (strchr(str, nrI[0]) == NULL || strchr(str, nrI[1]) == NULL)
		return 0;

	if (strchr(nr, nrI[3]) == NULL || strchr(nr, nrI[4]) == NULL)
		return 0;

	if (strchr(str, nrI[6]) == NULL || strchr(str, nrI[7]) == NULL || strchr(str, nrI[8]) == NULL)
		return 0;

	return 1;
}

int valideazaModel(char* model) {

	char* nr = "0123456789";

	int lg = strlen(model);

	if (lg != 4)
		return 0;

	for (int i = 0; i < lg; ++i)
		if (strchr(nr, model[i]) == NULL)
			return 0;

	int number = atoi(model);

	if (number < 1879 || number > 2020)
		return 0;

	return 1;
}

int valideazaCateg(char* categ) {

	char* categorii = "SUV MINI GOLF MARE DUSTER DUSTER1 DUSTER2 DUSTER3 DUSTER4 DUSTER5 DUSTER6 DUSTER7 DUSTER8";

	if (strstr(categorii, categ) == NULL)
		return 0;

	return 1;

}

int valideazaMasina(Masina* m) {

	int vNrI = valideazaNrI(getNrI(m));
	int vModel = valideazaModel(getModel(m));
	int vCateg = valideazaCateg(getCateg(m));

	if (vNrI == 1 && vModel == 1 && vCateg == 1)
		return 1;
	else return 0;
}

Validator* newValidator(ValidatorMasina valmas) {
	Validator* v = malloc(sizeof(Validator));
	v->validatorMasina = valmas;
	return v;
}

void distructorValidator(Validator* v) {
	free(v);
}