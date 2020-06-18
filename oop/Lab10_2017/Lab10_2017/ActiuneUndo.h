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
	IRepository* repo;

public:

	UndoAdauga(string nume, IRepository* repo) : nume{ nume }, repo{ repo } {}

	void doUndo() override {
		repo->stergeRepo(nume);
	}
};

class UndoSterge : public ActiuneUndo {
private:

	Locatar locatar;
	IRepository* repo;

public:

	UndoSterge(Locatar locatar, IRepository* repo) : locatar{ locatar }, repo{ repo }{}

	void doUndo() override {
		repo->adaugaRepo(locatar);
	}

};

class UndoModifica : public ActiuneUndo {
private:

	string nume;
	Locatar locatar;
	IRepository* repo;

public:

	UndoModifica(Locatar locatar, string nume, IRepository* repo) : locatar{ locatar }, nume{ nume }, repo{ repo } {}

	void doUndo() override {
		repo->modificaRepo(locatar, nume);
	}

};

class UndoGolire : public ActiuneUndo {
private:

	Cos cos;
	Cos& cosAddr;

public:

	UndoGolire(Cos& cosC) : cosAddr{ cosC } {
		cos = cosAddr;
	}

	void doUndo() override {
		cosAddr = cos;
	}

};