#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Service.h"

using namespace std;

const int Service::getLg() noexcept {
	return repo->getSize();
}

const Locatar& Service::get(const string& nume) {
	return repo->get(nume);
}

const void Service::adaugareService(const string& apartament, const string& nume, const string& suprafata, const string& tip) {
	Locatar locatar{ apartament, nume, suprafata, tip };

	validator.validateLocatar(locatar);
	actiuniUndo.push(make_unique<UndoAdauga>(nume, repo));
	repo->adaugaRepo(locatar);
}

const void Service::stergereService(const string& nume) {
	actiuniUndo.push(make_unique<UndoSterge>(repo->get(nume), repo));

	repo->stergeRepo(nume);
}

const void Service::modificareService(const Locatar& locatar, const string& nume) {
	validator.validateLocatar(locatar);

	actiuniUndo.push(make_unique<UndoModifica>(repo->get(nume), locatar.getNume(), repo));

	repo->modificaRepo(locatar, nume);
}

MyList<Locatar>& Service::getAll() noexcept {
	return repo->getAll();
}

MyList<Locatar> Service::getAllCopies() {
	return repo->getAllCopies();
}

const MyList<Locatar> Service::filtreaza(const string& fel, const string& cuv) {
	SorterAndFilter saf{};

	if (fel == "suprafata")
		return saf.filtreaza(repo->getAll(), cuv, filterSuprafata);
	else return saf.filtreaza(repo->getAll(), cuv, filterTip);
}

const void Service::sorteaza(const string& fel) {
	SorterAndFilter saf{};

	if (fel == "nume") saf.sorteza(repo->getAll(), sortNume);
	else if (fel == "suprafata") saf.sorteza(repo->getAll(), sortSuprafata);
	else saf.sorteza(repo->getAll(), sortTipSuprafata);
}

map<string, int> Service::makeMap() {

	MyList<Locatar>& myList = getAll();
	map<string, int> myMap;

	const unsigned int size = myList.size();
	for (unsigned int i = 0; i < size; ++i) {
		const Locatar& locatar = myList.at(i);

		if (myMap.find(locatar.getTip()) == myMap.end()) {
			myMap.insert(pair<string, int>(locatar.getTip(), 1));
		}
		else ++myMap[locatar.getTip()];
	}

	return myMap;
}

const void  Service::adaugaCos(const string& apartament) {
	cos.adaugaCos(repo->getByApartament(apartament));
}

const void  Service::golesteCos() {
	actiuniUndo.push(make_unique<UndoGolire>(cos));

	cos.golesteCos();
}

const void  Service::genereazaCos(const unsigned int& nr) {
	cos.genereazaCos(nr, repo);
}

int Service::size() {
	return cos.size();
}

IteratorList<Locatar> Service::beginRepo() {
	return repo->begin();
}

IteratorList<Locatar> Service::endRepo() {
	return repo->end();
}

IteratorList<Locatar> Service::beginCos() {
	return cos.begin();
}

IteratorList<Locatar> Service::endCos() {
	return cos.end();
}

Cos& Service::getCos() {
	return cos;
}

const void Service::doUndo() {
	actiuniUndo.top()->doUndo();
	actiuniUndo.pop();
}