#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Locatar.h"
#include "RepoException.h"
#include "MyList.h"

using std::string;
using std::iostream;
using std::vector;

class Repository {
private:

	MyList<Locatar> repo;

	const bool exista(const Locatar& locatar);

public:

	Locatar& getByApartament(const string& apartament);

	const int getSize() noexcept;

	Locatar& get(const string& nume);

	Locatar& getById(const unsigned int& id);

	const void adaugaRepo(const Locatar& locatar);

	const void stergeRepo(const string& nume);

	const void modificaRepo(const Locatar& locatar, const string nume);

	MyList<Locatar>& getAll() noexcept;

	MyList<Locatar> getAllCopies();

	IteratorList<Locatar> begin();

	IteratorList<Locatar> end();
};

class Cos {

private:

	MyList<Locatar> cos;

public:

	bool notExists(const Locatar& locatar);

	void adaugaCos(const Locatar& locatar);

	void genereazaCos(int nr, Repository& repo);

	void golesteCos() noexcept;

	int size() noexcept;

	IteratorList<Locatar> begin();

	IteratorList<Locatar> end();
};