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

#include "Service.h"

class CosApp : public QWidget {

public:

	CosApp(Service& serv) : serv{ serv } {
		initWindw();
		initConnections();
	}

private:

	Service& serv;

	QHBoxLayout* mainLayout = new QHBoxLayout();

	QVBoxLayout* leftLayout = new QVBoxLayout();
	QVBoxLayout* rightLayout = new QVBoxLayout();

	QHBoxLayout* inputLayout = new QHBoxLayout();

	QLabel* inputLabel = new QLabel("Apartament/Numar: ");

	QLineEdit* inputLine = new QLineEdit();

	QPushButton* addBtn = new QPushButton("Adauga Apartament");
	QPushButton* genBtn = new QPushButton("Genereaza Cos");
	QPushButton* golBtn = new QPushButton("Goleste Cos");
	QPushButton* closeBtn = new QPushButton("Close");

	QListWidget* list = new QListWidget();

	void initWindw() {

		setLayout(mainLayout);

		mainLayout->addLayout(leftLayout);
		mainLayout->addLayout(rightLayout);

		leftLayout->addLayout(inputLayout);

		inputLayout->addWidget(inputLabel);
		inputLayout->addWidget(inputLine);

		leftLayout->addWidget(addBtn);
		leftLayout->addWidget(genBtn);
		leftLayout->addWidget(golBtn);
		leftLayout->addWidget(closeBtn);

		rightLayout->addWidget(list);

	}

	void initConnections() {
		QObject::connect(closeBtn, &QPushButton::clicked, [&]() {close(); });
		QObject::connect(addBtn, &QPushButton::clicked, [&]() {adaugaCos(); });
		QObject::connect(genBtn, &QPushButton::clicked, [&]() {genereazaCos(); });
		QObject::connect(golBtn, &QPushButton::clicked, [&]() {golesteCos(); });
	}

	void reloadData() {
		list->clear();

		for (IteratorList<Locatar> it = serv.beginCos(); it != serv.endCos(); ++it) {
			Locatar locatar = *it;

			list->addItem(QString::fromStdString(locatar.toString()));
		}
	}

	void adaugaCos() {
		string nr = inputLine->text().toStdString();

		serv.adaugaCos(nr);
		reloadData();
		inputLine->setText("");
	}

	void genereazaCos() {
		int nr = inputLine->text().toInt();

		serv.genereazaCos(nr);
		reloadData();
		inputLine->setText("");
	}

	void golesteCos() {
		serv.golesteCos();

		list->clear();
		inputLine->setText("");
	}
};