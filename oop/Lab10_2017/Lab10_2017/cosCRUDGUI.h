#pragma once

#include <QtWidgets/QApplication>
#include <QtWidgets/qlabel.>
#include <QtWidgets/qpushbutton.>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qtableview.h>
#include <QtWidgets/qlistwidget.h>

#include "Service.h"
#include "TableModel.h"

class cosCRUDGUI : public QWidget, public Observable {

public:

	cosCRUDGUI(Service& serv) : serv{ serv } {
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

	QTableView* table = new QTableView();

	void initWindw() {

		serv.addObservable(this);

		setFixedSize(1000, 250);

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

		rightLayout->addWidget(table);

		serv.genereazaCos(4);
		reloadData(serv.getCos());
	}

	void initConnections() {
		QObject::connect(closeBtn, &QPushButton::clicked, [&]() {close(); });
		QObject::connect(addBtn, &QPushButton::clicked, [&]() {adaugaCos(); });
		QObject::connect(genBtn, &QPushButton::clicked, [&]() {genereazaCos(); });
		QObject::connect(golBtn, &QPushButton::clicked, [&]() {golesteCos(); });
		QObject::connect(table->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {outputSelection(); });
	}

	void outputSelection() {
		if (table->selectionModel()->selectedIndexes().isEmpty()) {
			inputLine->setText("");
			return;
		}

		auto row = table->selectionModel()->selectedIndexes().at(0).row();

		auto cell0 = table->model()->index(row, 0);
		auto cell1 = table->model()->index(row, 1);
		auto cell2 = table->model()->index(row, 2);
		auto cell3 = table->model()->index(row, 3);

		string apartament = table->model()->data(cell0, Qt::DisplayRole).toString().toStdString();
		string nume = table->model()->data(cell1, Qt::DisplayRole).toString().toStdString();
		string suprafata = table->model()->data(cell2, Qt::DisplayRole).toString().toStdString();
		string tip = table->model()->data(cell3, Qt::DisplayRole).toString().toStdString();

		QString line = QString::fromStdString(apartament + nume + suprafata + tip);

		inputLine->setText(line);

	}

	void reloadData(Cos cos) {
		vector<Locatar> vec;

		for (IteratorList<Locatar> it = cos.begin(); it != cos.end(); ++it) {
			Locatar locatar = *it;

			vec.push_back(locatar);
		}

		TableModel* tableModel = new TableModel(vec);

		table->setModel(tableModel);

	}

	void adaugaCos() {
		string nr = inputLine->text().toStdString();

		if (nr == "") return;

		serv.adaugaCos(nr);
		reloadData(serv.getCos());
		inputLine->setText("");
		notifyObserver();
	}

	void genereazaCos() {
		int nr = inputLine->text().toInt();

		serv.genereazaCos(nr);
		reloadData(serv.getCos());
		inputLine->setText("");
		notifyObserver();
	}

	void golesteCos() {
		serv.golesteCos();

		clearView();
		inputLine->setText("");
		notifyObserver();
	}

	void clearView() {
		reloadData(Cos());
	}

	void notifyObserver() override {
		serv.notifyObservables(serv.getCos());
	}

	void getNotified(Cos cos) override {
		reloadData(cos);
	}
};