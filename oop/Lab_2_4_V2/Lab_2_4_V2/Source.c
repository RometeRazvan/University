#include <stdio.h>
#include "Domain.h"
#include "TestDomain.h"
#include "TestRepository.h"
#include "TestService.h"
#include "TestValidator.h"
#include "Service.h"
#include "Ui.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


void testAll() {
	testDomainAll();
	testRepositoryAll();
	testServiceAll();
	testValidatorAll();
}

int main() {
	testAll();

	Ui* ui = newUi(distructorService);

	adauga(ui->serv, "CJ 07 TRM", "2010", "SUV");
	adauga(ui->serv, "CJ 08 TRM", "2011", "MINI");
	adauga(ui->serv, "CJ 09 TRM", "2012", "GOLF");
	adauga(ui->serv, "CJ 20 TRM", "2010", "SUV");

	run(ui);

	distructorUi(ui);

	_CrtDumpMemoryLeaks();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtDumpMemoryLeaks();
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);

	return 0;
}