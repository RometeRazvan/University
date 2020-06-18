#pragma once

#include <string>
#include <iostream>

using std::string;
using std::cout;

class Locatar {

private:

	string apartament, nume, suprafata, tip;

public:

	Locatar() = default;

	Locatar(const string a, const string n, const string s, const string t);

	Locatar(const Locatar &locatar);

	~Locatar();

	string getApartament() const;

	string getNume() const;

	string getTip() const;

	string getSuprafata() const;

	const string toString();
};