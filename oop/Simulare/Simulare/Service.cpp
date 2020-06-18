#include <vector>
#include <string>

#include "Service.h"

using namespace std;

void Service::addService(string nume, string titlu, string rating) {

	Participant participant{ nume, titlu, rating };

	repo->adaugaRepo(participant);

}

void Service::stergeService(string nume) {

	repo->stergeRepo(nume);

}

void Service::modificaService(string numeOld, string nume, string titlu, string rating) {

	Participant participant{ nume, titlu, rating };

	repo->modificaRepo(numeOld, participant);
}

Participant Service::get(string nume) {
	return repo->get(nume);
}

vector<Participant> Service::getAll() {
	return repo->getAll();
}