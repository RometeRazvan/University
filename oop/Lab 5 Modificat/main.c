#include <stdio.h>
#include "test.h"
#include "ui.h"
#include "repo.h"
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 


int main() {
	run_tests();
	MedList lista = createList();
	
	ui_run(&lista);

	_CrtDumpMemoryLeaks();
	return 0;
}