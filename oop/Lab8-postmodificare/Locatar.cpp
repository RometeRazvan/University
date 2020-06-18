#include <string>
#include <iostream>

#include "Locatar.h"

using std::string;
using std::iostream;

Locatar::Locatar(const string a, const string n, const string s, const string t) {

	apartament = a;
	nume = n;
	suprafata = s;
	tip = t;

}

Locatar::Locatar(const Locatar& locatar) {

	apartament = locatar.getApartament();
	nume = locatar.getNume();
	suprafata = locatar.getSuprafata();
	tip = locatar.getTip();

	//cout << "A fost copiat un locatar !!!\n";

}

Locatar::~Locatar() {}

string Locatar::getApartament() const {
	return apartament;
}

string Locatar::getNume() const {
	return nume;
}

string Locatar::getTip() const {
	return tip;
}

string Locatar::getSuprafata() const {
	return suprafata;
}