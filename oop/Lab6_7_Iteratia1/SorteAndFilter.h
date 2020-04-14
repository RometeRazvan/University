#pragma once

#include <string>
#include <vector>

#include "Service.h"

using std::string;
using std::vector;

typedef bool (*ComparatorSortare)(const Locatar& l1, const Locatar& l2);

typedef bool (*ComparatorFiltrare)(const Locatar& l, const string& fltr);

class SorterAndFilter {

public:

	SorterAndFilter() noexcept;

	const void sorteza(vector<Locatar>& vec, ComparatorSortare cs);

	const vector<Locatar> filtreaza(vector<Locatar>& vec, const string& fel, ComparatorFiltrare cf);

};

bool sortNume(const Locatar& l1, const Locatar& l2);

bool sortSuprafata(const Locatar& l1, const Locatar& l2);

bool sortTipSuprafata(const Locatar& l1, const Locatar& l2);

bool filterTip(const Locatar& l, const string& fltr);

bool filterSuprafata(const Locatar& l, const string& fltr);