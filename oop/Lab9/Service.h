#pragma once

#include <string>
#include <vector>
#include <map>
#include <stack>

#include "Repository.h"
#include "SorteAndFilter.h"
#include "Validator.h"

using namespace std;

class Service {

private:

	Repository repo;
	Cos cos;
	Validator validator;

public:

	const int getLg() noexcept;

	const Locatar& get(const string& nume);

	const void adaugareService(const string& apartament, const string& nume, const string& suprafata, const string& tip);

	const void stergereService(const string& nume);

	const void modificareService(const Locatar& locatar, const string& nume);

	MyList<Locatar>& getAll() noexcept;

	MyList<Locatar> getAllCopies();

	const MyList<Locatar> filtreaza(const string& fel, const string& cuv);

	const void sorteaza(const string& fel);

	map<string, int> makeMap();

	const void adaugaCos(const string& apartament);

	const void golesteCos();

	const void genereazaCos(const unsigned int& nr);

	int size();

	IteratorList<Locatar> beginRepo();

	IteratorList<Locatar> endRepo();

	IteratorList<Locatar> beginCos();

	IteratorList<Locatar> endCos();
};