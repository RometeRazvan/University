#include <string>
#include <iostream>
#include <string.h>

#include "Validator.h"

using namespace std;

const bool Validator::validateApartament(const string& apartament) {

	const string nr = "1234567890";

	if (apartament.at(0) == '0') return false;

	for (unsigned int i = 1; i < apartament.size(); ++i)
		if (nr.find(apartament.at(i)) > nr.size())
			return false;

	return true;
}

const bool Validator::validateNume(const string& nume) {

	const string lit = " abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ";

	for (unsigned int i = 0; i < nume.size(); ++i)
		if (lit.find(nume.at(i)) > lit.size())
			return false;

	return true;
}

const bool Validator::validateSuprafata(const string& suprafata) {

	if (suprafata.at(suprafata.size() - 1) != 'p') return false;
	if (suprafata.at(suprafata.size() - 2) != 'm') return false;

	const string nr = "1234567890";

	for (unsigned int i = 1; i < suprafata.size() - 2; ++i)
		if (nr.find(suprafata.at(i)) > nr.size())
			return false;

	return true;
}

const bool Validator::validateTip(const string& tip) {

	constexpr int n = 6;
	const string tipuri[n] = { "Open space", "Balcon", "Mansarda", "Decomandat", "Open Space", "Acoperis" };
	
	bool val = false;

	if (tipuri->find(tip) != NULL)
		val = true;

	return val;
}

const bool Validator::validateLocatar(const Locatar& locatar) {

	if (validateApartament(locatar.getApartament()) == false ||
		validateNume(locatar.getNume()) == false ||
		validateSuprafata(locatar.getSuprafata()) == false ||
		validateTip(locatar.getTip()) == false)

		throw ValidatorException("Locatar invalid");

	return true;
}