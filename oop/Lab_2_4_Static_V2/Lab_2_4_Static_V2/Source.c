#include "Domain.h"
#include "Repository.h"
#include "Service.h"
#include "Ui.h"
#include "TestRepository.h"
#include "TestDomain.h"
#include "TestService.h"
#include <stdio.h>
#include <string.h>

void testAll() {
	testDomainAll();
	testRepositoryAll();
	testServiceAll();
}

int main() {

	testAll();

	Ui ui = newUi();
	
	adaugaS(&ui.s, "CJ 07 TRM", "2010", "SUV");
	adaugaS(&ui.s, "CJ 08 TRM", "2011", "MINI");
	adaugaS(&ui.s, "CJ 09 TRM", "2012", "GOLF");
	adaugaS(&ui.s, "CJ 20 TRM", "2010", "SUV");
	
	runUi(&ui);

	return 0;
}