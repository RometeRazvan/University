#include "Cos.h"

#include <string>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

bool Cos::notExists(const Locatar& locatar) {
	for (IteratorList<Locatar> it = cos.begin(); it != cos.end(); ++it) {
		const Locatar& loc = *it;

		if (loc.getNume() == locatar.getNume())
			return false;
	}

	return true;
}

void Cos::adaugaCos(const Locatar& locatar) {
	if (notExists(locatar))
		cos.push_back(locatar);
	else {
		throw RepoException("Locatarul " + locatar.getNume() + " este deja in cos");
	}
}

void Cos::genereazaCos(int nr, IRepository* repo) {
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<> const dist(0, repo->getSize() - 1);

	if (nr > repo->getSize())
		throw RepoException("Numarul cerut este prea mare !");

	this->golesteCos();

	int frecv[100] = { 0 };
	int count = 0;

	while (count != nr) {
		int rndNr = dist(mt);

		if (frecv[rndNr] == 0) {
			++count;
			frecv[rndNr] = 1;
			this->adaugaCos(repo->getById(rndNr));
		}
	}

}

void Cos::golesteCos() noexcept {

	while (cos.size() != 0)
		cos.erase(0);
}

int Cos::size() noexcept {
	return cos.size();
}

IteratorList<Locatar> Cos::begin() {
	return cos.begin();
}

IteratorList<Locatar> Cos::end() {
	return cos.end();
}

MyList<Locatar>& Cos::getCos() {
	return cos;
}