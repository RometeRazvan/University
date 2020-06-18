#pragma once

#include<string>
#include<vector>

#include "Repository.h"

using namespace std;

class Service {
private:

	Repository* repo;

public:

	Service(string fileName) {
		repo = new Repository(fileName);
	}

	void addService(string nume, string titlu, string rating);

	void stergeService(string nume);

	void modificaService(string numeOld, string nume, string titlu, string rating);

	Participant get(string nume);

	vector<Participant> getAll();

};