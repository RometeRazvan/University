#include <iostream>

#include "TestLocatar.h"
#include "TestRepository.h"
#include "TestService.h"
#include "Ui.h"

using namespace std;

void testALL() {

	TestLocatar testLocatar{}; testLocatar.testAllLocatar();
	TestRepository testRepository{}; testRepository.testAllRepository();
	TestService testService{}; testService.testAllService();

}

int main() {
	
	testALL();

	UI ui{}; ui.run();

	return 0;
}