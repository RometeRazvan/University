#pragma once

#include <string>
#include <iostream>

#include "Locatar.h"

using namespace std;

class Validator {

public:

	const bool validateApartament(const string& apartament);

	const bool validateNume(const string& nume);

	const bool validateSuprafata(const string& suprafata);

	const bool validateTip(const string& tip);

	const bool validateLocatar(const Locatar& locatar);

};

class ValidatorException {
private:

	string msg;

public:

	ValidatorException(const string& mesaj) : msg{ mesaj } {}

	const string getMessage() const {
		return "\n" + msg + "\n";
	}

};