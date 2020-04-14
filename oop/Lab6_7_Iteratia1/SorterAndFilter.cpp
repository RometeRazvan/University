#include <string>
#include <iostream>
#include <vector>

#include "SorteAndFilter.h"

using std::string;
using std::vector;
using std::iostream;

bool sortNume(const Locatar& l1, const Locatar& l2) {
	if (l1.getNume() <= l2.getNume())
		return 1;
	return 0;
}

bool sortSuprafata(const Locatar& l1, const Locatar& l2) {
	if (l1.getSuprafata() <= l2.getSuprafata())
		return 1;
	return 0;
}

bool sortTipSuprafata(const Locatar& l1, const Locatar& l2) {
	if (l1.getTip() < l2.getTip())
		return 1;
	else if (l1.getTip() > l2.getTip())
		return 0;
	else return sortSuprafata(l1, l2);
}

bool filterTip(const Locatar& l, const string& fltr) {
	if (l.getTip() == fltr)
		return 1;
	return 0;
}

bool filterSuprafata(const Locatar& l, const string& fltr) {
	if (l.getSuprafata() == fltr)
		return 1;
	return 0;
}

SorterAndFilter::SorterAndFilter() noexcept {}

const void SorterAndFilter::sorteza(vector<Locatar>& vec, ComparatorSortare cs) {
	bool val = false;

	if (cs != nullptr) {
		while (!val) {
			val = true;

			for (unsigned int i = 0; i < vec.size() - 1; ++i) {
				if (!cs(vec.at(i), vec.at(i + 1))) {

					Locatar aux{ vec.at(i).getApartament(), vec.at(i).getNume(), vec.at(i).getSuprafata(), vec.at(i).getTip() };

					vec.at(i) = vec.at(i + 1);
					vec.at(i + 1) = aux;
					val = false;
				}
			}
		}
	}
}

const vector<Locatar> SorterAndFilter::filtreaza(vector<Locatar>& vec, const string& fel,ComparatorFiltrare cf) {
	vector<Locatar> vec2;

	if (cf != nullptr) {
		for (const Locatar& locatar : vec) {
			if (cf(locatar, fel)) {
				Locatar l{ locatar.getApartament(),locatar.getNume(), locatar.getSuprafata(), locatar.getTip() };

				vec2.push_back(l);
			}
		}
	}

	return vec2;
}