#pragma once

#include <string>

#include "Repository.h"
#include "RepoException.h"

using std::string;

class TestRepository {

public:

	TestRepository() noexcept;

	const void testAdaugare();

	const void testStergere();

	const void testModificare();

	const void testGetAll();

	const void testAllRepository();

	const void testCos();

};