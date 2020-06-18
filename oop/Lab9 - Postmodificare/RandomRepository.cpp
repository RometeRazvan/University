#include <string>
#include <iostream>
#include <vector>
#include <random>

#include "RandomRepository.h"

using namespace std;

void RandomRepository::setProb(double prob) {
	exceptionProbability = prob;
}

double getFuncProb() {
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<> const dist(0, 99);

	double functionProbability = (double)dist(mt) / 100;

	return functionProbability;
}

const int RandomRepository::getSize() {
	return repo.size();
}

Locatar& RandomRepository::get(const string& nume) {

	for (IteratorList<Locatar> it = repo.begin(); it != repo.end(); ++it) {
		Locatar& locatar = *it;
		if (locatar.getNume() == nume)
			return locatar;
	}
	throw RepoException("Nu s-a gasit locatarul " + nume);
}

const bool RandomRepository::exista(const Locatar& locatar) {
	bool val = false;

	try {
		get(locatar.getNume());
		val = true;
	}
	catch (RepoException&) {
		val = false;
	}

	return val;
}

const void RandomRepository::adaugaRepo(const Locatar& locatar) {
	double functionProbability = getFuncProb();

	if (exceptionProbability > functionProbability)
		throw RepoException("Exceptie repo");

	if (exista(locatar))
		throw RepoException("Locatarul " + locatar.getNume() + " exista deja in lista !!");
	else repo.push_back(locatar);
}

const void RandomRepository::stergeRepo(const string& nume) {
	double functionProbability = getFuncProb();

	if (exceptionProbability > functionProbability)
		throw RepoException("Exceptie repo");

	bool val = true;

	try {
		get(nume);
	}
	catch (const RepoException&) {
		val = false;
	}

	if (!val)
		throw RepoException("Locatarul " + nume + " nu s-a putut sterge pentru ca nu a fost gasit !!");

	unsigned int size = repo.size();

	for (unsigned int i = 0; i < size; ++i)
		if (repo.at(i).getNume() == nume) {
			repo.erase(i);
			--size;
		}

}

const void RandomRepository::modificaRepo(const Locatar& locatar, const string nume) {
	double functionProbability = getFuncProb();

	if (exceptionProbability > functionProbability)
		throw RepoException("Exceptie repo");

	bool val = true;

	try {
		get(nume);
	}
	catch (const RepoException&) {
		val = false;
	}

	if (!val)
		throw RepoException("Locatarul " + nume + " nu s-a putut modifica pentru ca nu a fost gasit !!");

	const unsigned int size = repo.size();

	for (unsigned int i = 0; i < size; ++i) {
		if (repo.at(i).getNume() == nume)
			repo.replace(i, locatar);
	}

}

MyList<Locatar>& RandomRepository::getAll() {
	return repo;
}

MyList<Locatar> RandomRepository::getAllCopies() {
	return repo;
}

IteratorList<Locatar> RandomRepository::begin() {
	return repo.begin();
}

IteratorList<Locatar> RandomRepository::end() {
	return repo.end();
}

Locatar& RandomRepository::getById(const unsigned int& id) {
	const unsigned int size = repo.size();

	for (unsigned int i = 0; i < size; ++i) {
		if (i == id)
			return repo.at(i);
	}

	throw RepoException("Nu s-a gasit locatar cu id-ul " + id);
}

Locatar& RandomRepository::getByApartament(const string& apartament) {
	for (IteratorList<Locatar> it = repo.begin(); it != repo.end(); ++it) {
		Locatar& locatar = *it;
		if (locatar.getApartament() == apartament)
			return locatar;
	}
	throw RepoException("Nu s-a gasit locatarul cu apartamentul " + apartament);
}