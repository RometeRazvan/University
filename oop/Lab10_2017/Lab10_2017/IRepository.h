#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Locatar.h"
#include "RepoException.h"
#include "MyList.h"

using namespace std;

class IRepository {
public:
	virtual const bool exista(const Locatar& locatar) = 0;

	virtual Locatar& getByApartament(const string& apartament) = 0;

	virtual const int getSize() = 0;

	virtual Locatar& get(const string& nume) = 0;

	virtual Locatar& getById(const unsigned int& id) = 0;

	virtual const void adaugaRepo(const Locatar& locatar) = 0;

	virtual const void stergeRepo(const string& nume) = 0;

	virtual const void modificaRepo(const Locatar& locatar, const string nume) = 0;

	virtual MyList<Locatar>& getAll() = 0;

	virtual MyList<Locatar> getAllCopies() = 0;

	virtual IteratorList<Locatar> begin() = 0;

	virtual IteratorList<Locatar> end() = 0;
};
