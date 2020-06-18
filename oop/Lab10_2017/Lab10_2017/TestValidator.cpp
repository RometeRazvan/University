#include <string>
#include <assert.h>
#include <iostream>

#include "TestValidator.h"

using namespace std;

TestValidator::TestValidator() noexcept {}

const void TestValidator::testAllValidator() {

	Validator val{};

	Locatar l1{ "012", "Razvan", "20mp", "Balcon" };
	Locatar l2{ "12a", "Razvan", "20mp", "Balcon" };
	Locatar l3{ "10", "Razvan", "20mp", "Balcon" };
	Locatar l4{ "12", "R2azvan", "20mp", "Balcon" };
	Locatar l5{ "12", "R2azvan", "20mz", "Balcon" };
	Locatar l6{ "12", "R2azvan", "20zp", "Balcon" };
	Locatar l7{ "12", "Razvan", "2amp", "Balcon" };
	Locatar l8{ "12", "Razvan", "2amp", "Balasasascon" };

	try { val.validateLocatar(l1); assert(false); }
	catch (const ValidatorException& ex) { assert(ex.getMessage() == "\nLocatar invalid\n"); }
	try { val.validateLocatar(l2); assert(false); }
	catch (const ValidatorException&) { assert(true); }
	assert(val.validateLocatar(l3) == true);
	try { val.validateLocatar(l4); assert(false); }
	catch (const ValidatorException&) { assert(true); }
	try { val.validateLocatar(l5); assert(false); }
	catch (const ValidatorException&) { assert(true); }
	try { val.validateLocatar(l6); assert(false); }
	catch (const ValidatorException&) { assert(true); }
	try { val.validateLocatar(l7); assert(false); }
	catch (const ValidatorException&) { assert(true); }
	try { val.validateLocatar(l8); assert(false); }
	catch (const ValidatorException&) { assert(true); }


	cout << "Finalizare teste Validator !!!\n";

}