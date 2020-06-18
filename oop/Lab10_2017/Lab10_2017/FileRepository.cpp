#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <iostream>

#include "FileRepository.h"

using namespace std;

const void  FileRepository::readFromFile() {

	fstream fin(fileName);

	if (!fin.is_open()) throw RepoException("Fisierul nu s-a putut deschide");

	string line = "";

	while (getline(fin, line)) {

		string tmp = "";
		vector<string> lindeData;

		for (string::iterator it = line.begin(); it != line.end(); ++it) {
			char chr = *it;

			if (chr == ';') {
				lindeData.push_back(tmp);
				tmp = "";
			}
			else tmp += chr;
		}

		Locatar locatar{ lindeData.at(0), lindeData.at(1), lindeData.at(2), lindeData.at(3) };

		repo.push_back(locatar);
	}

	fin.close();
}

const void  FileRepository::writeToFile() {

	ofstream fout(fileName);

	if (!fout.is_open()) throw RepoException("Fisierul nu s-a putut deschide");

	for (IteratorList<Locatar> it = repo.begin(); it != repo.end(); ++it) {
		const Locatar& locatar = *it;

		string toFile = locatar.getApartament() + ';' + locatar.getNume() + ';' + locatar.getSuprafata() + ';' + locatar.getTip() + ";\n";

		fout << toFile;
	}

}

const int FileRepository::getSize() noexcept {
	return repo.size();
}

Locatar& FileRepository::get(const string& nume) {

	for (IteratorList<Locatar> it = repo.begin(); it != repo.end(); ++it) {
		Locatar& locatar = *it;
		if (locatar.getNume() == nume)
			return locatar;
	}
	throw RepoException("Nu s-a gasit locatarul " + nume);
}

const bool FileRepository::exista(const Locatar& locatar) {

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

const void FileRepository::adaugaRepo(const Locatar& locatar) {
	if (exista(locatar))
		throw RepoException("Locatarul " + locatar.getNume() + " exista deja in lista !!");
	else repo.push_back(locatar);

	writeToFile();
}

const void FileRepository::stergeRepo(const string& nume) {

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

	writeToFile();
}

const void FileRepository::modificaRepo(const Locatar& locatar, const string nume) {

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

	writeToFile();
}

MyList<Locatar>& FileRepository::getAll() noexcept {
	return repo;
}

MyList<Locatar> FileRepository::getAllCopies() {
	return repo;
}

IteratorList<Locatar> FileRepository::begin() {
	return repo.begin();
}

IteratorList<Locatar> FileRepository::end() {
	return repo.end();
}

Locatar& FileRepository::getById(const unsigned int& id) {
	const unsigned int size = repo.size();

	for (unsigned int i = 0; i < size; ++i) {
		if (i == id)
			return repo.at(i);
	}

	throw RepoException("Nu s-a gasit locatar cu id-ul " + id);
}

Locatar& FileRepository::getByApartament(const string& apartament) {
	for (IteratorList<Locatar> it = repo.begin(); it != repo.end(); ++it) {
		Locatar& locatar = *it;
		if (locatar.getApartament() == apartament)
			return locatar;
	}
	throw RepoException("Nu s-a gasit locatarul cu apartamentul " + apartament);
}