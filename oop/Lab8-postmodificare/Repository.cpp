#include <string>
#include <iostream>
#include <vector>
#include <random>

#include "Repository.h"

using std::string;
using std::iostream;
using std::vector;

void Repository::toMyList() {
	typedef map<string, Locatar> Map;
	
	while (vector.size())
		vector.erase(0);

	for (Map::iterator it = repo.begin(); it != repo.end(); ++it) {
		const Locatar& l1 = it->second;

		const Locatar l2{ l1.getApartament(), l1.getNume(), l1.getSuprafata(), l1.getTip() };

		vector.push_back(l2);
	}
}

const int Repository::getSize() noexcept{
	return repo.size();
}

Locatar& Repository::get(const string& nume) {

	toMyList();

	auto it = find_if(vector.begin(), vector.end(),
		[&](const Locatar& l) {return l.getNume() == nume;});

	if (it != vector.end()) {
		Locatar& l = *it;
		return l;
	}

	/*if (repo.find(nume) != repo.end())
		return repo[nume];*/
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
	else repo.insert(pair<string, Locatar>(locatar.getNume(), locatar));
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

	if (repo.find(nume) != repo.end())
		repo.erase(nume);
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

	typedef map<string, Locatar> Map;
	map<string, Locatar> newMap;
	for (Map::iterator it = repo.begin(); it != repo.end(); ++it) {
		if (it->first != nume)
			newMap.insert(pair<string, Locatar>(it->first, it->second));
		else newMap.insert(pair<string, Locatar>(locatar.getNume(), locatar));
	}

	repo = newMap;
}

MyList<Locatar>& Repository::getAll() noexcept {
	toMyList();
	return vector;
}

MyList<Locatar> Repository::getAllCopies() {
	toMyList();
	return vector;
}

IteratorList<Locatar> Repository::begin() {
	toMyList();
	return vector.begin();
}

IteratorList<Locatar> Repository::end() {
	toMyList();
	return vector.end();
}

Locatar& Repository::getById(const unsigned int& id) {

	toMyList();

	const unsigned int size = vector.size();

	for (unsigned int i = 0; i < size; ++i) {
		if (i == id)
			return vector.at(i);
	}

	throw RepoException("Nu s-a gasit locatar cu id-ul " + id);
}

Locatar& Repository::getByApartament(const string& apartament) {
	/*toMyList();
	for (IteratorList<Locatar> it = begin(); it != end(); ++it) {
		Locatar& locatar = *it;
		if (locatar.getApartament() == apartament)
			return locatar;
	}*/
	for (map<string, Locatar>::iterator it = repo.begin(); it != repo.end(); ++it) {
		Locatar& l = it->second;

		if (l.getApartament() == apartament)
			return l;
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

MyList<Locatar>& Repository::getList() {
	return vector;
} 