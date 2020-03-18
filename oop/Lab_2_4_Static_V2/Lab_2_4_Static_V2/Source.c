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

	//Ui ui = newUi(); ui.s = generateSev2(); runUi(&ui);

	return 0;
}