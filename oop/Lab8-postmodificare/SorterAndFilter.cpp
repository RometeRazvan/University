#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#include "SorteAndFilter.h"

using namespace std;

bool sortNume(const Locatar& l1, const Locatar& l2) {
	if (l1.getNume() <= l2.getNume())
		return 1; return 0;
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

const void SorterAndFilter::sorteza(MyList<Locatar>& vec, ComparatorSortare cs) {
	vector<Locatar> vec2;

	for (IteratorList<Locatar> it = vec.begin(); it != vec.end(); ++it) {
		Locatar& l = *it;
		vec2.push_back(l);
	}
	/*bool val = false;

	if (cs != nullptr) {
		while (!val) {
			val = true;

			const unsigned int size = vec.size();

			for (unsigned int i = 0; i < size - 1; ++i) {
				if (!cs(vec.at(i), vec.at(i + 1))) {

					Locatar aux{ vec.at(i).getApartament(), vec.at(i).getNume(), vec.at(i).getSuprafata(), vec.at(i).getTip() };

					vec.replace(i, vec.at(i + 1));
					vec.replace(i + 1, aux);
					val = false;
				}
			}
		}
	}*/

	sort(vec2.begin(), vec2.end(), cs);

	while (vec.size())
		vec.erase(0);

	for (auto it = vec2.begin(); it != vec2.end(); ++it) {
		Locatar& l = *it;
		vec.push_back(l);
	}
}

const MyList<Locatar> SorterAndFilter::filtreaza(MyList<Locatar>& vec, const string& fel,ComparatorFiltrare cf) {
	MyList<Locatar> vec2;

	vector<Locatar> nefiltrat;

	for (IteratorList<Locatar> it = vec.begin(); it != vec.end(); ++it) {
		const Locatar& l = *it;
		const Locatar newL{ l.getApartament(), l.getNume(), l.getSuprafata(), l.getTip() };
		
		nefiltrat.push_back(newL);
	}

	vector<Locatar> filtrat(nefiltrat.size());

	auto it = copy_if(nefiltrat.begin(), nefiltrat.end(), filtrat.begin(),
		[&](const Locatar& l) {return cf(l, fel);});

	filtrat.resize(distance(filtrat.begin(), it));

	for (unsigned int i = 0; i < filtrat.size(); ++i) {
		const Locatar& l = filtrat.at(i);
		const Locatar newL{ l.getApartament(), l.getNume(), l.getSuprafata(), l.getTip() };

		vec2.push_back(newL);
	}

	/*const unsigned int size = vec.size();

	if (cf != nullptr) {
		for (IteratorList<Locatar> it = vec.begin(); it != vec.end(); ++it) {
			const Locatar& locatar = *it;
			if (cf(locatar, fel)) {
				Locatar l{ locatar.getApartament(),locatar.getNume(), locatar.getSuprafata(), locatar.getTip() };

				vec2.push_back(l);
			}
		}
	}*/

	return vec2;
}