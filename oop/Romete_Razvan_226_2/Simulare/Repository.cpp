#include <string>
#include <vector>
#include <fstream>

#include "Repository.h"

using namespace std;

void Repository::loadFromFile() {

	ifstream fin(fileName);

	string line;

	vector<string> vec;

	while (getline(fin, line)) {
		string tmp = "";

		for(char chr : line) {

			if (chr == ';') {
				vec.push_back(tmp);
				tmp = "";
			}
			else {
				tmp = tmp + chr;
			}
		}

		Participant participant{ vec.at(0), vec.at(1), vec.at(2) };

		vec.clear();

		repo.push_back(participant);
	}
}

void Repository::writeToFile() {

	ofstream fout(fileName);

	for (vector<Participant>::iterator it = repo.begin(); it != repo.end(); ++it) {
		Participant participant = *it;

		fout << participant.getNume() + ";" + participant.getTitlu() + ";" + participant.getRating() + ";\n";
	}

}

void Repository::adaugaRepo(Participant participant) {

	if (participant.getTitlu() == "Maestru Candidat" && stoi(participant.getRating()) < 2200)
		throw new exception("Nu s-a putut adauga");

	if (participant.getTitlu() == "Maestru" && stoi(participant.getRating()) < 2400)
		throw new exception("Nu s-a putut adauga");

	if (participant.getTitlu() == "Mare Maestru" && stoi(participant.getRating()) < 2500)
		throw new exception("Nu s-a putut adauga");

	repo.push_back(participant);

	writeToFile();

}

void Repository::modificaRepo(string nume, Participant participant) {
	if (participant.getTitlu() == "Maestru Candidat" && stoi(participant.getRating()) < 2200)
		throw new exception("Nu s-a putut adauga");

	if (participant.getTitlu() == "Maestru" && stoi(participant.getRating()) < 2400)
		throw new exception("Nu s-a putut adauga");

	if (participant.getTitlu() == "Mare Maestru" && stoi(participant.getRating()) < 2500)
		throw new exception("Nu s-a putut adauga");


	for (int i = 0; i < repo.size(); ++i) {
		if (repo.at(i).getNume() == nume) {
			repo.at(i).setNume(participant.getNume());
			repo.at(i).setTitlu(participant.getTitlu());
			repo.at(i).setRating(participant.getRating());
		}
	}

}

void Repository::stergeRepo(string nume) {

	for (int i = 0; i < repo.size(); ++i)
		if (repo.at(i).getNume() == nume)
			repo.erase(repo.begin() + i);

}

Participant Repository::get(string nume) {
	for (vector<Participant>::iterator it = repo.begin(); it != repo.end(); ++it) {
		Participant participant = *it;
		
		if (participant.getNume() == nume)
			return participant;
	}

	throw new exception("Nu s-a putut gasi participant");
}

vector<Participant> Repository::getAll() {
	return repo;
}