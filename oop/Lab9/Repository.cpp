#include <string>
#include <iostream>
#include <vector>
#include <random>

#include "Repository.h"

using std::string;
using std::iostream;
using std::vector;

const int Repository::getSize() noexcept{
	return repo.size();
}

Locatar& Repository::get(const string& nume) {

	for (IteratorList<Locatar> it = repo.begin(); it != repo.end(); ++it) {
		Locatar& locatar = *it;
		if (locatar.getNume() == nume)
			return locatar;
	}
	throw RepoException("Nu s-a gasit locatarul " + nume);
}

const bool Repository::exista(const Locatar& locatar) {

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

const void Repository::adaugaRepo(const Locatar& locatar) {
	if (exista(locatar))
		throw RepoException("Locatarul " + locatar.getNume() + " exista deja in lista !!");
	else repo.push_back(locatar);
}

const void Repository::stergeRepo(const string& nume) {

	bool val = true;

	try {
		get(nume);
	} catch (const RepoException&) {
		val = false;
	}

	if(!val)
		throw RepoException("Locatarul " + nume + " nu s-a putut sterge pentru ca nu a fost gasit !!");

	unsigned int size = repo.size();

	for (unsigned int i = 0; i < size; ++i)
		if (repo.at(i).getNume() == nume) {
			repo.erase(i);
			--size;
		}
	
}

const void Repository::modificaRepo(const Locatar& locatar, const string nume) {

	bool val = true;

	try {
		get(nume);
	}
	catch (const RepoException&) {
		val = false;
	}

	if(!val)
		throw RepoException("Locatarul " + nume + " nu s-a putut modifica pentru ca nu a fost gasit !!");

	const unsigned int size = repo.size();

	for (unsigned int i = 0; i < size; ++i) {
		if (repo.at(i).getNume() == nume)
			repo.replace(i, locatar);
	}

}

MyList<Locatar>& Repository::getAll() noexcept {
	return repo;
}

MyList<Locatar> Repository::getAllCopies() {
	return repo;
}

IteratorList<Locatar> Repository::begin() {
	return repo.begin();
}

IteratorList<Locatar> Repository::end() {
	return repo.end();
}

Locatar& Repository::getById(const unsigned int& id) {
	const unsigned int size = repo.size();

	for (unsigned int i = 0; i < size; ++i) {
		if (i == id)
			return repo.at(i);
	}

	throw RepoException("Nu s-a gasit locatar cu id-ul " + id);
}

Locatar& Repository::getByApartament(const string& apartament) {
	for (IteratorList<Locatar> it = repo.begin(); it != repo.end(); ++it) {
		Locatar& locatar = *it;
		if (locatar.getApartament() == apartament)
			return locatar;
	}
	throw RepoException("Nu s-a gasit locatarul cu apartamentul " + apartament);
}

bool Cos::notExists(const Locatar& locatar) {
	for (IteratorList<Locatar> it = cos.begin(); it != cos.end(); ++it) {
		const Locatar& loc = *it;

		if (loc.getNume() == locatar.getNume())
			return false;
	}

	return true;
}

void Cos::adaugaCos(const Locatar& locatar) {
	if(notExists(locatar))
		cos.push_back(locatar);
	else {
		throw RepoException("Locatarul " + locatar.getNume() + " este deja in cos");
	}
}

void Cos::genereazaCos(int nr, Repository& repo) {
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<> const dist(0, repo.getSize() - 1);

	if(nr > repo.getSize())
		throw RepoException("Numarul cerut este prea mare !");

	this->golesteCos();

	int frecv[100] = { 0 };
	int count = 0;

	while (count != nr) {
		int rndNr = dist(mt);

		if (frecv[rndNr] == 0) {
			++count;
			frecv[rndNr] = 1;
			this->adaugaCos(repo.getById(rndNr));
		}
	}

}

void Cos::golesteCos() noexcept{

	while (cos.size() != 0)
		cos.erase(0);
}

int Cos::size() noexcept{
	return cos.size();
}

IteratorList<Locatar> Cos::begin() {
	return cos.begin();
}

IteratorList<Locatar> Cos::end() {
	return cos.end();
}