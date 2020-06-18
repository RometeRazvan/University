#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Locatar.h"

using std::string;

class RepoException {

private:

	const string mesaj;

public:

	RepoException(const string& ms);

	const string getMesaj() const;

};