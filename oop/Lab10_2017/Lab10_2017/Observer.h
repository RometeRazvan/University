#pragma once

#include <vector>

#include "Observable.h"
#include "Cos.h"

using namespace std;

class Observer {
private:

	vector<Observable*> observables;

public:

	void addObservable(Observable* observable) {
		observables.push_back(observable);
	}

	void notifyObservables(Cos cos) {
		for (Observable* observable : observables) {
			observable->getNotified(cos);
		}
	}
};