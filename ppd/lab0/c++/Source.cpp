#include "FileGenerator.h"
#include "FileComparer.h"
#include <iostream>

using namespace std;

int main() {
	FileGenerator* fileGenerator = new FileGenerator();

	//fileGenerator->generateFile("file.txt", 100, 1, 100);
	//fileGenerator->generateFile("file2.txt", 100, 1, 100);

	FileComparer* fileComparer = new FileComparer();

	cout << fileComparer->compareFiles("file.txt", "file2.txt", "int");
}