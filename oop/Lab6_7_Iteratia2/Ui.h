#pragma once

#include "Service.h"

class UI {

private :

	Service serv;

public:

	UI() noexcept;

	const void adauga();

	const void sterge();

	const void modifica();

	const void sorteaza();

	const void filtreaza();

	const void afiseaza();

	const void run();

};