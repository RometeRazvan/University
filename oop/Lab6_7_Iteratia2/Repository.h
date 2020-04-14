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

	const int getSize() noexcept;

	Locatar& get(const string& nume);

	const void adaugaRepo(const Locatar& locatar);

	const void stergeRepo(const string& nume);

	const void modificaRepo(const Locatar& locatar, const string nume);

	MyList<Locatar>& getAll() noexcept;

	MyList<Locatar> getAllCopies();

};