#include <string>
#include <iostream>
#include <vector>

#include "Repository.h"

using std::string;
using std::iostream;
using std::vector;

const int Repository::getSize() const noexcept {
	return repo.size();
}

Locatar& Repository::get(const string& nume) {
	for (auto& locatar : repo) {
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

	vector<Locatar>::iterator it;

	for (unsigned int i = 0; i < repo.size(); ++i) {
		if (repo.at(i).getNume() == nume)
			repo.erase(repo.begin() + i);
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

	for (unsigned int i = 0; i < repo.size(); ++i) {
		if (repo.at(i).getNume() == nume)
			repo.at(i) = locatar;
	}

}

vector<Locatar>& Repository::getAll() noexcept {
	return repo;
}

vector<Locatar> Repository::getAllCopies() {
	return repo;
}