#pragma once

#include <string>

using namespace std;

template<typename T>
struct Nod {
	T val;
	Nod* urm;
	Nod(T v) : val{ v }, urm{ nullptr } {};
	Nod(T v, Nod* urm) : val{ v }, urm{ urm } {};
};

template<typename T>
class IteratorList;

template<typename T>
class MyList {

private:

	Nod<T>* cap;

	void free() noexcept;

	Nod<T>* copiaza(Nod<T>* nod);

public:

	MyList() noexcept;

	MyList(const MyList& myList);

	~MyList();

	T& at(const int& poz);

	void operator=(const MyList& myList);

	const int size() noexcept;

	void push_back(const T& val);

	void erase(const int& poz) noexcept;

	void replace(const int& poz, const T& val);

	IteratorList<T> begin();

	IteratorList<T> end();
};

template<typename T>
MyList<T>::MyList() noexcept {

	cap = nullptr;

}

template<typename T>
const int MyList<T>::size() noexcept{

	auto nCurent = cap;
	int lg = 0;

	while (nCurent != nullptr) {
		++lg;
 		nCurent = nCurent->urm;
	}

	return lg;
}

template<typename T>
Nod<T>* MyList<T>::copiaza(Nod<T>* nod) {
	if (nod == nullptr)
		return nullptr;

	Nod<T>* n = nullptr;

	n = new Nod<T>(nod->val);
	n->urm = copiaza(nod->urm);

	return n;
}

template<typename T>
MyList<T>::MyList(const MyList& myList) {
	cap = copiaza(myList.cap);
}

template<typename T>
T& MyList<T>::at(const int& poz) {

	if (poz > size())
		throw exception("Nu s-a gasit elementul");

	Nod<T>* nCurent = cap;
	int nPoz = 0;

	while (nPoz != poz) {
		nCurent = nCurent->urm;
		++nPoz;
	}

	return nCurent->val;
}

template<typename T>
void MyList<T>::free() noexcept{

	Nod<T>* nCurent = cap;

	while (nCurent != nullptr) {

		auto aux = nCurent->urm;
		delete nCurent;
		nCurent = aux;
	}

	cap = nullptr;
}

template<typename T>
MyList<T>::~MyList() {
	free();
}

template<typename T>
void MyList<T>::operator=(const MyList& myList) {

	free();

	cap = copiaza(myList.cap);

}

template<typename T>
void MyList<T>::push_back(const T& val) {

	Nod<T>* nCurent = cap;

	while (nCurent != nullptr && nCurent->urm != nullptr)
		nCurent = nCurent->urm;

	if (nCurent == nullptr)
		cap = new Nod<T>{ val, nullptr };
	else nCurent->urm = new Nod<T>{ val, nullptr };
}

template<typename T>
void MyList<T>::erase(const int& poz) noexcept {

	if (poz == 0) {
		Nod<T>* aux = cap;
		cap = cap->urm;
		delete aux;
	}
	else {
		Nod<T>* nCurent = cap;
		int lg = 0;

		while (lg != poz - 1) {
			++lg;
			nCurent = nCurent->urm;
		}

		if (size() == 2) {
			delete nCurent->urm;
			nCurent->urm = nullptr;
		}
		else {
			if (poz == size() - 1) {
				auto aux = nCurent->urm;
				nCurent->urm = nullptr;
				delete aux;
			}
			else {
				auto aux = nCurent->urm;
				nCurent->urm = nCurent->urm->urm;
				delete aux;
			}
		}
	}
}

template<typename T>
void MyList<T>::replace(const int& poz, const T& val) {

	if (poz > size()) return;

	Nod<T>* nCurent = cap;
	int lg = 0;

	while (lg != poz) {
		nCurent = nCurent->urm;
		++lg;
	}

	nCurent->val = val;
}

template<typename T>
IteratorList<T> MyList<T>::begin() {
	return IteratorList<T>{cap};
}

template<typename T>
IteratorList<T> MyList<T>::end() {
	return IteratorList<T>{nullptr};
}

template<typename T>
class IteratorList {
	
private:

	Nod<T>* curent;

public:

	IteratorList(Nod<T>* cap) noexcept;

	void operator=(const IteratorList<T>& it) noexcept;

	void operator++() noexcept;

	bool operator!=(const IteratorList& iteratorList) noexcept;

	T& operator*() noexcept;

};

template<typename T>
IteratorList<T>::IteratorList(Nod<T>* cap) noexcept{
	curent = cap;
}

template <typename T>
void IteratorList<T>::operator=(const IteratorList<T>& it)  noexcept{
	curent = it.curent;
}

template<typename T>
void IteratorList<T>::operator++() noexcept{
	curent = curent->urm;
}

template<typename T>
bool IteratorList<T>::operator!=(const IteratorList& iteratorList) noexcept{
	return curent != iteratorList.curent;
}

template <typename T>
T& IteratorList<T>::operator*() noexcept{
	return curent->val;
}