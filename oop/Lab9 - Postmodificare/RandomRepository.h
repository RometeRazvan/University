#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Locatar.h"
#include "RepoException.h"
#include "MyList.h"
#include "IRepository.h"

using namespace std;

class RandomRepository : public IRepository {
private:

	double exceptionProbability;

	MyList<Locatar> repo;

	const bool exista(const Locatar& locatar);

public:

	RandomRepository(double excProb) : exceptionProbability{excProb} {}

	Locatar& getByApartament(const string& apartament) override;

	const int getSize() override;

	Locatar& get(const string& nume) override;

	Locatar& getById(const unsigned int& id) override;

	const void adaugaRepo(const Locatar& locatar) override;

	const void stergeRepo(const string& nume) override;

	const void modificaRepo(const Locatar& locatar, const string nume) override;

	MyList<Locatar>& getAll() override;

	MyList<Locatar> getAllCopies() override;

	IteratorList<Locatar> begin() override;

	IteratorList<Locatar> end() override;

	void setProb(double prob);
};