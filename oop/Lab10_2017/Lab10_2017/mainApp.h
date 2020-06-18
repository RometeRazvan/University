#pragma once

#include <QtWidgets/QApplication>
#include <QtWidgets/qlabel.>
#include <QtWidgets/qpushbutton.>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qcheckbox.h>

#include <vector>
#include <algorithm>

#include "Service.h"
#include "FilterApp.h"
#include "CosApp.h"
#include "cosCRUDGUI.h"
#include "CosDesen.h"

using namespace std;

class mainApp : public QWidget{

public:

	mainApp(Service& serv) : serv{ serv } {
		initWindow();
		reloadDataWithBtn();
		initConnections();
	}

private:

	QListWidget* listOutPut = new QListWidget();

	Service& serv;

	MyList<QPushButton*> btnVector;

	QListWidget* list = new QListWidget();

	QHBoxLayout* mainLayOut = new QHBoxLayout();
	QVBoxLayout* leftSideLayout = new QVBoxLayout();
	QVBoxLayout* rightSideLayout = new QVBoxLayout();
	QVBoxLayout* modLayout = new QVBoxLayout();

	QFormLayout* formLayout = new QFormLayout();
	QGridLayout* btnGrdLayout = new QGridLayout();
	QHBoxLayout* srtBtnLayout = new QHBoxLayout();

	QLineEdit* apartamentLine = new QLineEdit();
	QLineEdit* numeLine = new QLineEdit();
	QLineEdit* suprafataLine = new QLineEdit();
	QLineEdit* tipLine = new QLineEdit();
	QLineEdit* oldLocatarLine = new QLineEdit();

	QPushButton* adaugaBtn = new QPushButton("Adauga");
	QPushButton* stergeBtn = new QPushButton("Sterge");
	QPushButton* modificaBtn = new QPushButton("Modifica");
	QPushButton* filtrareBtn = new QPushButton("Filtrare");
	QPushButton* closeBtn = new QPushButton("Close");
	QPushButton* undoBtn = new QPushButton("Undo");
	QPushButton* cosBtn = new QPushButton("Cos");
	QPushButton* cosDesenBtn = new QPushButton("CosDesen");

	QPushButton* srtNumeBtn = new QPushButton("Sort Nume");
	QPushButton* srtSuprafataBtn = new QPushButton("Sort Suprafata");
	QPushButton* srtTipBtn = new QPushButton("Sort Tip");

	QCheckBox* srtCbox = new QCheckBox();
	QLabel* cbLabel = new QLabel("Descrescator: ");

	void initWindow() {
		setLayout(mainLayOut);

		mainLayOut->addLayout(leftSideLayout);
		mainLayOut->addLayout(rightSideLayout);
		mainLayOut->addLayout(modLayout);

		leftSideLayout->addWidget(list);
		leftSideLayout->addLayout(srtBtnLayout);

		rightSideLayout->addLayout(formLayout);
		rightSideLayout->addLayout(btnGrdLayout);

		formLayout->addRow("Apartament: ", apartamentLine);
		formLayout->addRow("Nume: ", numeLine);
		formLayout->addRow("Suprafata: ", suprafataLine);
		formLayout->addRow("Tip: ", tipLine);
		formLayout->addRow("Nume locatar vechi: ", oldLocatarLine);

		btnGrdLayout->addWidget(adaugaBtn, 1, 1);
		btnGrdLayout->addWidget(stergeBtn, 1, 2);
		btnGrdLayout->addWidget(modificaBtn, 2, 1);
		btnGrdLayout->addWidget(filtrareBtn, 2, 2);
		btnGrdLayout->addWidget(undoBtn, 3, 1, 1, 2);
		btnGrdLayout->addWidget(cosBtn, 4, 1);
		btnGrdLayout->addWidget(cosDesenBtn, 4, 2);
		btnGrdLayout->addWidget(closeBtn, 5, 1, 1, 2);

		srtBtnLayout->addWidget(cbLabel);
		srtBtnLayout->addWidget(srtCbox);
		srtBtnLayout->addWidget(srtNumeBtn);
		srtBtnLayout->addWidget(srtSuprafataBtn);
		srtBtnLayout->addWidget(srtTipBtn);
	}

	void reloadData() {
		list->clear();

		for (IteratorList<Locatar> it = serv.beginRepo(); it != serv.endRepo(); ++it) {
			Locatar& locatar = *it;

			list->addItem(QString::fromStdString(locatar.toString()));
		}
	}

	void reloadDataWithBtn() {
		list->clear();

		int poz = -1;

		for (IteratorList<QPushButton*> it = btnVector.begin(); it != btnVector.end(); ++it) {
			QPushButton* btn = *it;

			delete btn;
		}

		while (btnVector.size())
			btnVector.erase(0);

		vector<Locatar> vec;

		for (IteratorList<Locatar> it = serv.beginRepo(); it != serv.endRepo(); ++it) {
			Locatar& locatar = *it;

			vec.push_back(locatar);
		}

		for (vector<Locatar>::iterator it = vec.begin(); it != vec.end(); ++it) {
			Locatar& locatar = *it;

			list->addItem(QString::fromStdString(locatar.toString()));

			QPushButton* locBtn = new QPushButton(QString::fromStdString(locatar.getNume()));

			btnVector.push_back(locBtn);

			modLayout->addWidget(locBtn);

			QObject::connect(locBtn, &QPushButton::clicked, [&, this, locBtn, locatar]() {
				serv.stergereService(locatar.getNume());
				reloadData();
				
				int poz = -1;

				for (IteratorList<QPushButton*> it = btnVector.begin(); it != btnVector.end(); ++it) {
					QPushButton* btn = *it;

					++poz;

					if (btn->text() == locBtn->text()) {
						btnVector.erase(poz);
						break;
					}
				}

				delete locBtn;
				});
		}
	}

	void reloadReverseDataWithBtn() {
		list->clear();

		for (IteratorList<QPushButton*> it = btnVector.begin(); it != btnVector.end(); ++it) {
			QPushButton* btn = *it;

			delete btn;
		}

		while (btnVector.size())
			btnVector.erase(0);

		vector<Locatar> vec;

		for (IteratorList<Locatar> it = serv.beginRepo(); it != serv.endRepo(); ++it) {
			Locatar& locatar = *it;

			vec.push_back(locatar);
		}

		reverse(vec.begin(), vec.end());

		for (vector<Locatar>::iterator it = vec.begin(); it != vec.end(); ++it) {
			Locatar& locatar = *it;

			list->addItem(QString::fromStdString(locatar.toString()));

			QPushButton* locBtn = new QPushButton(QString::fromStdString(locatar.getNume()));

			btnVector.push_back(locBtn);

			modLayout->addWidget(locBtn);

			QObject::connect(locBtn, &QPushButton::clicked, [&, this, locBtn, locatar]() {
				serv.stergereService(locatar.getNume());
				reloadData();

				int poz = -1;

				for (IteratorList<QPushButton*> it = btnVector.begin(); it != btnVector.end(); ++it) {
					QPushButton* btn = *it;

					++poz;

					if (btn->text() == locBtn->text()) {
						btnVector.erase(poz);
						break;
					}
				}

				delete locBtn;
				});
		}
	}

	void initConnections() {
		QObject::connect(adaugaBtn, &QPushButton::clicked, [&]() {adaugaClicked(); });
		QObject::connect(stergeBtn, &QPushButton::clicked, [&]() {stergeClicked(); });
		QObject::connect(modificaBtn, &QPushButton::clicked, [&]() {modificaClicked(); });
		QObject::connect(list, &QListWidget::itemSelectionChanged, [&]() {fromTableToLine(); });
		QObject::connect(srtNumeBtn, &QPushButton::clicked, [&]() {sortByName(); });
		QObject::connect(srtSuprafataBtn, &QPushButton::clicked, [&]() {sortBySuprafata(); });
		QObject::connect(srtTipBtn, &QPushButton::clicked, [&]() {sortByTip(); });
		QObject::connect(closeBtn, &QPushButton::clicked, [&]() {closeApp(); });
		QObject::connect(filtrareBtn, &QPushButton::clicked, [&]() {filterApp(); });
		QObject::connect(undoBtn, &QPushButton::clicked, [&]() {doUndo(); });
		QObject::connect(cosBtn, &QPushButton::clicked, [&]() {openCos(); });
		QObject::connect(cosDesenBtn, &QPushButton::clicked, [&]() {openCosDesen(); });
	}

	void clearLines() {
		apartamentLine->clear();
		numeLine->clear();
		suprafataLine->clear();
		tipLine->clear();
		oldLocatarLine->clear();
	}

	void adaugaClicked() {
		string apartament = apartamentLine->text().toStdString();
		string nume = numeLine->text().toStdString();
		string suprafata= suprafataLine->text().toStdString();
		string tip = tipLine->text().toStdString();

		try {
			serv.adaugareService(apartament, nume, suprafata, tip);
		}
		catch (const RepoException&) {
			QMessageBox::information(this, tr("Eraore"), tr("Date invalide"));
		}

		reloadDataWithBtn();
		clearLines();
	}

	void stergeClicked() {
		string nume = numeLine->text().toStdString();

		try {
			serv.stergereService(nume);
		}
		catch (const RepoException&) {
			QMessageBox::information(this, tr("Eraore"), tr("Date invalide"));
		}

		reloadDataWithBtn();
		clearLines();
	}

	void modificaClicked() {
		string apartament = apartamentLine->text().toStdString();
		string nume = numeLine->text().toStdString();
		string suprafata = suprafataLine->text().toStdString();
		string tip = tipLine->text().toStdString();
		string oldLocatar = oldLocatarLine->text().toStdString();

		try {
			Locatar locatar{ apartament, nume, suprafata, tip };
			serv.modificareService(locatar, oldLocatar);
		}
		catch (const RepoException&) {
			QMessageBox::information(this, tr("Eraore"), tr("Date invalide"));
		}

		reloadDataWithBtn();
		clearLines();
	}

	void fromTableToLine() {
	
		QList<QListWidgetItem*> selectedItem = list->selectedItems();

		if (selectedItem.isEmpty()) {
			apartamentLine->setText("");
			numeLine->setText("");
			suprafataLine->setText("");
			tipLine->setText("");
			return;
		}

		string text = selectedItem.at(0)->text().toStdString();
		string tmp;
		vector<string> date;
		for (string::iterator it = text.begin(); it != text.end(); ++it) {
			char chr = *it;

			if (chr == ' ') {
				date.push_back(tmp);
				tmp = "";
			}
			else tmp += chr;
		}

		apartamentLine->setText(QString::fromStdString(date.at(0)));
		numeLine->setText(QString::fromStdString(date.at(1)));
		suprafataLine->setText(QString::fromStdString(date.at(2)));
		tipLine->setText(QString::fromStdString(date.at(3)));
	}

	void sortByName() {
		serv.sorteaza("nume");

		if (!srtCbox->isChecked())
			reloadDataWithBtn();
		else reloadReverseDataWithBtn();
	}

	void sortBySuprafata() {
		serv.sorteaza("suprafata");

		if (!srtCbox->isChecked())
			reloadDataWithBtn();
		else reloadReverseDataWithBtn();
	}

	void sortByTip() {
		serv.sorteaza("tip");
		
		if (!srtCbox->isChecked())
			reloadDataWithBtn();
		else reloadReverseDataWithBtn();
	}

	void closeApp() {
		close();
	}

	void filterApp() {
		FilterApp* fa = new FilterApp(serv);
		fa->show();
	}

	void doUndo() {
		try {
			serv.doUndo();
			reloadDataWithBtn();
		}
		catch (const RepoException&) {
			QMessageBox::warning(this, tr("Eroare"), tr("Error"));
		}
	}

	void openCos() {
		cosCRUDGUI* cosCrudGui = new cosCRUDGUI(serv);
		cosCrudGui->show();
	}

	void openCosDesen() {
		CosDesen* cosDesen = new CosDesen(serv);
		cosDesen->show();
	}
};