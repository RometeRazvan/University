#pragma once
#include "Service.h"

typedef struct {
	Serv* serv;
	Distructor f;
}Ui;

Ui* newUi(Distructor f);

void distructorUi(Ui* ui);

void run(Ui* ui);
