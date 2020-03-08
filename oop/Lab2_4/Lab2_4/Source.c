#include <stdio.h>
#include "Domain.h"
#include "TestDomain.h"
#include "TestRepository.h"
#include "TestService.h"

void testAll() {
	testDomainAll();
	testRepositoryAll();
	//testAllService();
}

int main() {
	testAll();
	system("PAUSE");
	return 0;
}