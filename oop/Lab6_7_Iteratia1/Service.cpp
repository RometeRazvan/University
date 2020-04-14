#include <iostream>
#include <string>
#include <vector>

#include "Service.h"

using std::iostream;
using std::vector;
using std::string;

const int Service::getLg() const noexcept {
	return repo.getSize();
}

const Locatar& Service::get(const string& nume) {
	return repo.get(nume);
}

const void Service::adaugareService(const string& apartament, const string& nume, const string& suprafata, const string& tip) {
	Locatar locatar { apartament, nume, suprafata, tip };

	repo.adaugaRepo(locatar);
}

const void Service::stergereService(const string& nume) {
	repo.stergeRepo(nume);
}

const void Service::modificareService(const Locatar& locatar, const string& nume) {
	repo.modificaRepo(locatar, nume);
}

vector<Locatar>& Service::getAll() noexcept {
	return repo.getAll();
}

vector<Locatar> Service::getAllCopies() {
	return repo.getAllCopies();
}

const vector<Locatar> Service::filtreaza(const string& fel, const string& cuv) {
	SorterAndFilter saf{};

	if (fel == "suprafata")
		return saf.filtreaza(repo.getAll(), cuv, filterSuprafata);
	else return saf.filtreaza(repo.getAll(), cuv, filterTip);
}

const void Service::sorteaza(const string& fel) {
	SorterAndFilter saf{};

	if (fel == "nume") saf.sorteza(repo.getAll(), sortNume);
	else if (fel == "suprafata") saf.sorteza(repo.getAll(), sortSuprafata);
	else saf.sorteza(repo.getAll(), sortTipSuprafata);
}