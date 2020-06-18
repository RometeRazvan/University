#include <iostream>
#include <fstream>
#include <random>

#include "TestLocatar.h"
#include "TestRepository.h"
#include "TestService.h"
#include "TestMyList.h"
#include "TestValidator.h"
#include "Ui.h"
#include "FileRepository.h"

using namespace std;

void testALL() {

	TestLocatar testLocatar{}; testLocatar.testAllLocatar();
	TestMyList testMyList{}; testMyList.testAllMyList();
	TestRepository testRepository{}; testRepository.testAllRepository();
	TestValidator testValidator{}; testValidator.testAllValidator();
	TestService testService{}; testService.testAllService();

}

int main() {
	
	testALL();
	
	UI ui(0.5); ui.run();

	return 0;
}