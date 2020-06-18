#pragma once

#include "MyList.h"
#include "Locatar.h"
#include "IRepository.h"

class Cos {

private:

	MyList<Locatar> cos;

public:

	bool notExists(const Locatar& locatar);

	void adaugaCos(const Locatar& locatar);

	void genereazaCos(int nr, IRepository* repo);

	void golesteCos() noexcept;

	int size() noexcept;

	IteratorList<Locatar> begin();

	IteratorList<Locatar> end();

	MyList<Locatar>& getCos();
};