#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLineEdit>

#include <vector>
#include <string>

#include "Service.h"

class MainApp : public QWidget {

public:

	MainApp(string fileName) {

		serv = new Service(fileName);
		initWindow();
		initConnections();
		reloadData();
	}

private:

	Service* serv;

	QHBoxLayout* mainLayout = new QHBoxLayout();

	QVBoxLayout* leftSide = new QVBoxLayout();
	QVBoxLayout* rightSide = new QVBoxLayout();

	QFormLayout* form = new QFormLayout();

	QListWidget* list = new QListWidget();

	QPushButton* addBtn = new QPushButton("Adauga");
	QPushButton* delBtn = new QPushButton("Sterge");
	QPushButton* modBtn = new QPushButton("Modifica");

	QLineEdit* numeLine = new QLineEdit();
	QLineEdit* titluLine = new QLineEdit();
	QLineEdit* ratingLine = new QLineEdit();
	QLineEdit* oldNumeLine = new QLineEdit();

	void initWindow() {

		this->setLayout(mainLayout);

		mainLayout->addLayout(leftSide);
		mainLayout->addLayout(rightSide);

		leftSide->addWidget(list);

		form->addRow("Nume: ", numeLine);
		form->addRow("Titlu: ", titluLine);
		form->addRow("Rating: ", ratingLine);
		form->addRow("NumeVechi: ", oldNumeLine);

		rightSide->addLayout(form);

		rightSide->addWidget(addBtn);
		rightSide->addWidget(delBtn);
		rightSide->addWidget(modBtn);

	}

	void initConnections() {
		QObject::connect(addBtn, &QPushButton::clicked, [&] {addOp();});
		QObject::connect(delBtn, &QPushButton::clicked, [&] {delOp();});
		QObject::connect(modBtn, &QPushButton::clicked, [&] {modOp();});
	}

	void reloadData() {
		list->clear();

		vector<Participant> lis = serv->getAll();

		for (vector<Participant>::iterator it = lis.begin(); it != lis.end(); ++it) {
			Participant part = *it;

			list->addItem(QString::fromStdString(part.toFile()));
		}
	}

	void addOp() {
		try {
			string nume = numeLine->text().toStdString();
			string titlu = titluLine->text().toStdString();
			string rating = ratingLine->text().toStdString();

			serv->addService(nume, titlu, rating);

			reloadData();
		}
		catch (...) {}
	}

	void delOp() {
		try {
			string nume = numeLine->text().toStdString();

			serv->stergeService(nume);

			reloadData();
		}
		catch (...) {}
	}

	void modOp() {
		try {
			string nume = numeLine->text().toStdString();
			string titlu = titluLine->text().toStdString();
			string rating = ratingLine->text().toStdString();
			string oldNume = oldNumeLine->text().toStdString();

			serv->modificaService(oldNume, nume, titlu, rating);

			reloadData();
		}
		catch(...) {}
	}

};