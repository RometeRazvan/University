#pragma once
#include "Domain.h"

typedef void* ElemT;
typedef void(*Distructor)(ElemT);

typedef struct {
	ElemT* lista;
	int lg;
	int capacitate;
	Distructor f;
}Lista;

Lista* newLista(Distructor f);

int getLg(Lista* l);

int getCapac(Lista* l);

void checkRealloc(Lista* l);

void adaugareMasinaR(Lista* l, ElemT m);

ElemT stergeMasinaR(Lista* l, int poz);

void updateMasinaR(Lista* l, int poz, ElemT m);

ElemT getMasinaR(Lista* l, int poz);

void distructorLista(Lista* l);