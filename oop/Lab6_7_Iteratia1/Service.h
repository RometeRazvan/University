#pragma once

#include <string>
#include <vector>

#include "Repository.h"
#include "SorteAndFilter.h"

using std::string;
using std::vector;

class Service {

private:

	Repository repo;

public:

	const int getLg() const noexcept;

	const Locatar& get(const string& nume);

	const void adaugareService(const string& apartament, const string& nume, const string& suprafata, const string& tip);

	const void stergereService(const string& nume);

	const void modificareService(const Locatar& locatar, const string& nume);

	vector<Locatar>& getAll() noexcept;

	vector<Locatar> getAllCopies();

	const vector<Locatar> filtreaza(const string& fel, const string& cuv);

	const void sorteaza(const string& fel);
};