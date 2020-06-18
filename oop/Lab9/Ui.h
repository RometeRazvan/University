#pragma once

#include <stack>

#include "Service.h"
#include "ActiuneUndo.h"

using namespace std;

class UI {

private :

	Service serv;
	stack<unique_ptr<ActiuneUndo>> actiuniUndo;

public:

	UI() noexcept;

	const void adauga();

	const void sterge();

	const void modifica();

	const void sorteaza();

	const void filtreaza();

	const void afiseazaMap();

	const void afiseaza();

	const void afiseazaCos();

	const void operatiiCos();

	const void exportCos(const string& filename);

	const void undo();

	const void run();

};