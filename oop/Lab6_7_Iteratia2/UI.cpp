#include <iostream>
#include <string>
#include <vector>

#include "Ui.h"
#include "RepoException.h"

using std::iostream;
using std::vector;
using std::string;
using std::cin;

UI::UI() noexcept {}

const void UI::adauga() {

	string apartament, nume, suprafata, tip;

	cout << "Apartament: "; cin >> apartament;
	cout << "Nume: "; cin >> nume;
	cout << "Suprafata: "; cin >> suprafata;
	cout << "Tip: "; cin >> tip;

	try {
		serv.adaugareService(apartament, nume, suprafata, tip);
	}
	catch (const RepoException& ex) {
		cout << ex.getMesaj();
	}

}

const void UI::sterge() {

	string nume;

	cout << "Nume: "; cin >> nume;

	try {
		serv.stergereService(nume);
	}
	catch (const RepoException& ex) {
		cout << ex.getMesaj();
	}

}

const void UI::modifica() {

	string apartament, nume, suprafata, tip;
	string numeLocatar;

	cout << "Nume Locatar: "; cin >> numeLocatar;
	cout << "Apartament: "; cin >> apartament;
	cout << "Nume: "; cin >> nume;
	cout << "Suprafata: "; cin >> suprafata;
	cout << "Tip: "; cin >> tip;

	try {
		Locatar locatar{ apartament, nume, suprafata, tip };
		serv.modificareService(locatar, numeLocatar);
	}
	catch (const RepoException& ex) {
		cout << ex.getMesaj();
	}

}

const void UI::sorteaza() {

	const string menu = "\nMeniu sortare: \n1 - Nume\n2 - Suprafata\n3 - Tip + Suprafata\n";
	const string outComanda = "\nComanda: ";
	string comanda;

	cout << menu;
	cout << outComanda; cin >> comanda;

	try {

		if (comanda == "1") comanda = "nume";
		else if (comanda == "2") comanda = "suprafata";
		else comanda = "Tip";

		serv.sorteaza(comanda);
		afiseaza();
	}
	catch (const RepoException& ex) {
		cout << ex.getMesaj();
	}

}

const void UI::filtreaza() {

	const string menu = "\nMeniu Filtrare: \n1 - Tip\n2 - Suprafata\n";
	const string outComanda = "\nComanda: ";
	string comanda;

	cout << menu;
	cout << outComanda; cin >> comanda;

	try {

		string fel;

		if (comanda == "1") fel = "tip", comanda = "Tip";
		else fel = "suprafata", comanda = "Suprafata";

		cout << comanda + ": "; cin >> comanda;

		MyList<Locatar> vec = serv.filtreaza(fel, comanda);

		const unsigned int size = vec.size();

		for (unsigned int i = 0; i < size; ++i) {
			const Locatar& locatar = vec.at(i);
			cout << locatar.getApartament() << " " << locatar.getNume() << " " << locatar.getSuprafata() << " " << locatar.getTip() << "\n";
		}
	}
	catch (const RepoException& ex) {
		cout << ex.getMesaj();
	}
}

const void UI::afiseaza() {

	MyList<Locatar>& vec = serv.getAll();

	const unsigned int size = vec.size();

	for (unsigned int i = 0; i < size; ++i) {
		const Locatar& locatar = vec.at(i);
		cout << locatar.getApartament() << " " << locatar.getNume() << " " << locatar.getSuprafata() << " " << locatar.getTip() << "\n";
	}
}

const void UI::run() {

	serv.adaugareService("13", "Razvan", "25mp", "Balcon");
	serv.adaugareService("14", "Dragos", "26mp", "Decomandat");
	serv.adaugareService("15", "Iulius", "27mp", "Open Space");

	const string menu = "\n1 - Adauga\n2 - Sterge\n3 - Modifica\n4 - Sorteaza\n5 - Filtreaza\n6 - Afiseaza\n0 - Exit\n";

	cout << menu;

	while (true) {

		try {
			string comanda;
			const string outComanda = "\nComanda este: ";

			while (true) {

				cout << outComanda; cin >> comanda;

				if (comanda == "1") adauga();
				else if (comanda == "2") sterge();
				else if (comanda == "3") modifica();
				else if (comanda == "4") sorteaza();
				else if (comanda == "5") filtreaza();
				else if (comanda == "6") afiseaza();
				else if (comanda == "0") return;

			}
		}
		catch (const RepoException& rex) {
			cout << rex.getMesaj();
		}
		catch (const ValidatorException& vex) {
			cout << vex.getMessage();
		}

	}

}