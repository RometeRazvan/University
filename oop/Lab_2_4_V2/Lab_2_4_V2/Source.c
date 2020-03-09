#include <stdio.h>
#include "Domain.h"
#include "TestDomain.h"
#include "TestRepository.h"
#include "TestService.h"
#include "TestValidator.h"
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
	return 0;
}