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

#include "Service.h"

class FilterApp : public QWidget {
public:

	FilterApp(Service& serv) : serv { serv } {
		initWindow();
		initConnections();
	}

private:

	Service& serv;

	QHBoxLayout* mainLayout = new QHBoxLayout();

	QVBoxLayout* leftSide = new QVBoxLayout();
	QVBoxLayout* rightSide = new QVBoxLayout();

	QHBoxLayout* inputLayout = new QHBoxLayout();

	QLabel* inputLabel = new QLabel("Suprafata/Tip: ");
	QLineEdit* inputLine = new QLineEdit();

	QPushButton* sprBtn = new QPushButton("Filtrare Suprafata");
	QPushButton* tipBtn = new QPushButton("Filtrare Tip");
	QPushButton* closeBtn = new QPushButton("Close");
	QPushButton* mapBtn = new QPushButton("Incarca Map");

	QListWidget* list = new QListWidget();

	void initWindow() {
		setLayout(mainLayout);

		mainLayout->addLayout(leftSide);
		mainLayout->addLayout(rightSide);

		leftSide->addLayout(inputLayout);

		inputLayout->addWidget(inputLabel);
		inputLayout->addWidget(inputLine);

		leftSide->addWidget(sprBtn);
		leftSide->addWidget(tipBtn);
		leftSide->addWidget(mapBtn);
		leftSide->addWidget(closeBtn);

		rightSide->addWidget(list);
	}

	void initConnections() {
		QObject::connect(sprBtn, &QPushButton::clicked, [&]() {surfaceFilter(); });
		QObject::connect(tipBtn, &QPushButton::clicked, [&]() {typeFilter(); });
		QObject::connect(closeBtn, &QPushButton::clicked, [&]() {close(); });
		QObject::connect(mapBtn, &QPushButton::clicked, [&]() {loadMap(); });
	}

	void reloadData(MyList<Locatar> myList) {
		list->clear();

		for (IteratorList<Locatar> it = myList.begin(); it != myList.end(); ++it) {
			Locatar locatar = *it;

			list->addItem(QString::fromStdString(locatar.toString()));
		}
	}

	void surfaceFilter() {
		string suprafata = inputLine->text().toStdString();

		MyList<Locatar> myList = serv.filtreaza("suprafata", suprafata);
		reloadData(myList);
		inputLine->setText("");
	}

	void typeFilter() {
		string tip = inputLine->text().toStdString();

		MyList<Locatar> myList = serv.filtreaza("tip", tip);
		reloadData(myList);
		inputLine->setText("");
	}

	void loadMap() {
		list->clear();

		map<string, int> myMap = serv.makeMap();

		for (auto it = myMap.begin(); it != myMap.end(); ++it) {
			string line = it->first + ": " + to_string(it->second);

			list->addItem(QString::fromStdString(line));
		}
		inputLine->setText("");
	}
};