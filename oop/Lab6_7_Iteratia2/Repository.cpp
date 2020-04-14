#include <string>
#include <iostream>
#include <vector>

#include "Repository.h"

using std::string;
using std::iostream;
using std::vector;

const int Repository::getSize() noexcept{
	return repo.size();
}

Locatar& Repository::get(const string& nume) {

	const unsigned int size = repo.size();

	for(unsigned int i = 0; i < size; ++i) {
		if (repo.at(i).getNume() == nume)
			return repo.at(i);
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