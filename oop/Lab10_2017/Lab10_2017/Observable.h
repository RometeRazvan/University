#pragma once

#include "Cos.h"

class Observable {
public:

	virtual void notifyObserver() = 0;

	virtual void getNotified(Cos cos) = 0;
};