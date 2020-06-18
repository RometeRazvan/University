#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Locatar.h"
#include "RepoException.h"
#include "MyList.h"
#include "IRepository.h"

using std::string;
using std::iostream;
using std::vector;

class FileRepository : public IRepository {
private:

	string fileName;
	MyList<Locatar> repo;

	const bool exista(const Locatar& locatar);

public:

	FileRepository(string fileName) : fileName{ fileName } {
		readFromFile();
	}

	Locatar& getByApartament(const string& apartament) override;

	const int getSize() noexcept override;

	Locatar& get(const string& nume) override;

	Locatar& getById(const unsigned int& id) override;

	const void adaugaRepo(const Locatar& locatar) override;

	const void stergeRepo(const string& nume) override;

	const void modificaRepo(const Locatar& locatar, const string nume) override;

	MyList<Locatar>& getAll() noexcept override;

	MyList<Locatar> getAllCopies() override;

	IteratorList<Locatar> begin() override;

	IteratorList<Locatar> end() override;

	const void readFromFile();

	const void writeToFile();
};