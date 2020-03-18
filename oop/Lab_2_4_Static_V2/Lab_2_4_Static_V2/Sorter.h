#pragma once
#include "Service.h"

typedef int(*choose)(Masina a, Masina B);

Lista sortList(Lista l, choose fc);

int modelCrescator(Masina a, Masina b);

int modelDescrescator(Masina a, Masina b);

int categCrescator(Masina a, Masina b);

int categDescrescator(Masina a, Masina b);