#pragma once

#include <string>
#include <assert.h>

using namespace std;

class Participant {
private:

	string nume, titlu, rating;

public:

	Participant(string nume, string titlu, string rating) : nume {nume}, titlu {titlu}, rating {rating} {}

	string getNume() {
		return nume;
	}

	string getTitlu() {
		return titlu;
	}

	string getRating() {
		return rating;
	}

	string toFile() {
		return nume + ";" + titlu + ";" + rating + ";" + "\n";
	}

	void setNume(string n) {
		nume = n;
	}

	void setTitlu(string n) {
		titlu = n;
	}

	void setRating(string n) {
		rating = n;
	}

};

class TestParticipant {
public:

	void testAllParticipant() {
		Participant participant{ "Razvan", "Maestru candidat", "2200" };

		assert(participant.getNume() == "Razvan");
		assert(participant.getRating() == "2200");
		assert(participant.getTitlu() == "Maestru candidat");
	}
};