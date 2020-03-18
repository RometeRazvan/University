#include "Domain.h"
#include "Repository.h"
#include "Service.h"
#include "TestRepository.h"
#include "TestDomain.h"
#include "TestService.h"
#include <stdio.h>

void testAll() {
	testDomainAll();
	testRepositoryAll();
	testServiceAll();
}

int main() {
	testAll();

	return 0;
}