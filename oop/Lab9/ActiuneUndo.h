#pragma once

#include "Service.h"

using namespace std;

class ActiuneUndo {
public:

	virtual void doUndo() = 0;

	virtual ~ActiuneUndo() = default;
};

class UndoAdauga : public ActiuneUndo {
private:

	string nume;
	Service& serv;

public:

	UndoAdauga(string nume, Service& serv) : nume{ nume }, serv{ serv } {}

	void doUndo() override {
		serv.stergereService(nume);
	}

};

class UndoSterge : public ActiuneUndo {
private:

	string apartament, nume, suprafata, tip;
	Service& serv;

public:

	UndoSterge(string apartament, string nume, string suprafata, string tip, Service& serv) : apartament{ apartament }, nume{ nume }, suprafata{ suprafata }, tip{ tip }, serv{ serv } {}

	void doUndo() override {
		serv.adaugareService(apartament, nume, suprafata, tip);
	}

};

class UndoModifica : public ActiuneUndo {
private:

	string nume;
	Locatar locatar;
	Service& serv;

public:

	UndoModifica(Locatar locatar, string nume, Service& serv) : locatar{ locatar }, nume{nume}, serv{ serv } {}

	void doUndo() override {
		serv.modificareService(locatar, nume);
	}

};