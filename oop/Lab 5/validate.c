#include "validate.h"
#include <string.h>
#include <stdio.h>

/*
	Validate a medicament
	Return 0 if med is valid
*/
int validateMed(Medicament med)
{
	if (strlen(getName(med)) == 0)
	{
		return 1;
	}
	if (med.concentration < 0)
	{
		return 2;
	}
	if (med.cantity < 0)
	{
		return 3;
	}
	return 0;
}
