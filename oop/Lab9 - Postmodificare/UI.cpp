#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "Ui.h"
#include "RepoException.h"

using namespace std;

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

const void UI::afiseazaMap() {

	map<string, int> myMap = serv.makeMap();

	cout << "\n";

	for (auto it = myMap.begin(); it != myMap.end(); ++it)
		cout << it->first << ": " << it->second << "\n";
}

const void UI::exportCos(const string& filename) {

	ofstream fout(filename);

	for (IteratorList<Locatar> it = serv.beginCos(); it != serv.endCos(); ++it) {
		const Locatar& locatar = *it;

		fout << locatar.getApartament() << ";" << locatar.getNume() << ";" << locatar.getSuprafata() << ";" << locatar.getTip() << ";\n";
	}
	fout.close();
}

const void UI::afiseazaCos() {
	cout << "\n";

	for (IteratorList<Locatar> it = serv.beginCos(); it != serv.endCos(); ++it) {
		const Locatar& locatar = *it;

		cout << locatar.getApartament() << " " << locatar.getNume() << " " << locatar.getSuprafata() << " " << locatar.getTip() << "\n";
	}
}

const void UI::operatiiCos() {

	const string& menu = "\n1 - Adauga dupa apartament\n2 - Genereaza cos\n3 - Goleste Cos\n4 - Export to file\n5 - Afiseaza Cos\n0 - Exit\n";
	const string& strComanda = "\nComanda: ";

	string comanda;

	cout << menu;

	while (true) {

		try {
			cout << strComanda; cin >> comanda;

			if (comanda == "1") {
				string apartament;

				cout << "\nApartamentul: "; cin >> apartament;

				serv.adaugaCos(apartament);
			}
			else if (comanda == "2") {
				int nr;

				cout << "\nNumar: "; cin >> nr;

				serv.genereazaCos(nr);
			}
			else if (comanda == "3") {
				serv.golesteCos();
			}
			else if (comanda == "4") {
				string filename;

				cout << "\nFilename: "; cin >> filename;

				this->exportCos(filename);
			}
			else if (comanda == "5") {
				this->afiseazaCos();
			}
			else if (comanda == "0") return;

			afiseazaCos();
		}
		catch (const RepoException& ex) {
			cout << ex.getMesaj();
		}
		catch (const exception& ex) {
			cout << ex.what();
		}
	}
}

const void UI::undo() {
	serv.doUndo();

	cout << "\nLocatari:\n\n";
	this->afiseaza();

	cout << "\nCos:\n";
	this->afiseazaCos();
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

	try { if (!file) { serv.adaugareService("13", "Razvan", "25mp", "Balcon"); } }
	catch (const RepoException&) {}
	try { if (!file) { serv.adaugareService("14", "Dragos", "26mp", "Open Space"); } }
	catch (const RepoException&) {}
	try { if (!file) { serv.adaugareService("15", "Iulius", "27mp", "Balcon"); } }
	catch (const RepoException&) {}
	try { if (!file) { serv.adaugareService("16", "Dan", "25mp", "Balcon"); } }
	catch (const RepoException&) {}
	try { if (!file) { serv.adaugareService("17", "Andrei", "26mp", "Open Space"); } }
	catch (const RepoException&) {}
	try { if (!file) { serv.adaugareService("18", "Vasile", "27mp", "Mansarda"); } }
	catch (const RepoException&) {}

	const string menu = "\n1 - Adauga\n2 - Sterge\n3 - Modifica\n4 - Sorteaza\n5 - Filtreaza\n6 - Afiseaza tipuri : numar\n7 - Operatii Cos\n8 - Undo\n9 - Afiseaza\n0 - Exit\n";

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
				else if (comanda == "6") afiseazaMap();
				else if (comanda == "7") operatiiCos();
				else if (comanda == "8") undo();
				else if (comanda == "9") afiseaza();
				else if (comanda == "0") return;

			}
		}
		catch (const RepoException& rex) {
			cout << rex.getMesaj();
		}
		catch (const ValidatorException& vex) {
			cout << vex.getMessage();
		}
		catch (const exception& ex) {
			cout << ex.what();
		}

	}

}