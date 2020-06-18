#include <QtWidgets/Qtableview>
#include <QtWidgets/qvboxlayout>
#include <QtWidgets/qhboxlayout>
#include <QtWidgets/qformlayout>
#include <QtWidgets/qlabel>
#include <QtWidgets/qlineedit>
#include <QtWidgets/qpushbutton>
#include <QtWidgets/QMessagebox>

#include <vector>
#include <string>

#include "Service.h"
#include "TableModel.h"
#include "TableItem.h"

class MainApp : public QWidget {
public:
	MainApp(Service& serv) : serv{ serv } {
		initWindow();
		initConnectios();
	}

private:

	Service& serv;

	QHBoxLayout* mainLy = new QHBoxLayout();

	QVBoxLayout* rightSide = new QVBoxLayout();
	QVBoxLayout* leftSide = new QVBoxLayout();

	QTableView* table = new QTableView();

	QLineEdit* titluLine = new QLineEdit();
	QLineEdit* artistLine = new QLineEdit();
	QLineEdit* genLine = new QLineEdit();

	QFormLayout* form = new QFormLayout();

	QPushButton* addBtn = new QPushButton("Adauga");
	QPushButton* delBtn = new QPushButton("Sterge");

	TableModel* tm;

	void initWindow() {

		setFixedSize(1300, 400);

		setLayout(mainLy);

		mainLy->addLayout(leftSide);
		mainLy->addLayout(rightSide);

		leftSide->addWidget(table);

		form->addRow("Titlu: ", titluLine);
		form->addRow("Artist: ", artistLine);
		form->addRow("Gen: ", genLine);

		rightSide->addLayout(form);

		rightSide->addWidget(addBtn);
		rightSide->addWidget(delBtn);

		loadData();
	}

	void initConnectios() {
		QObject::connect(addBtn, &QPushButton::clicked, [&]() {addFunc(); });
		QObject::connect(delBtn, &QPushButton::clicked, [&]() {delFunc(); });
	}

	void loadData() {
		vector<TableItem> list;

		for (auto m : serv.getAll()) {
			int nrAutor = serv.getNrArtist(m.getArtist());
			int nrGen = serv.getNrGen(m.getGen());

			TableItem t{ m.getId(), m.getTilu(), m.getArtist(), m.getGen(), nrAutor, nrGen };

			list.push_back(t);
		}

		sort(list.begin(), list.end(), [](TableItem& t1, TableItem& t2) {
			return t1.getArtist() < t2.getArtist();
			});

		tm = new TableModel(list);

		table->setModel(tm);
	}

	void reloadData() {
		vector<TableItem> list;

		for (auto m : serv.getAll()) {
			int nrAutor = serv.getNrArtist(m.getArtist());
			int nrGen = serv.getNrGen(m.getGen());

			TableItem t{ m.getId(), m.getTilu(), m.getArtist(), m.getGen(), nrAutor, nrGen };

			list.push_back(t);
		}

		sort(list.begin(), list.end(), [](TableItem& t1, TableItem& t2) {
			return t1.getArtist() < t2.getArtist();
			});

		tm->setList(list);
		tm->updateModel();
	}

	void addFunc() {

		string titlu = titluLine->text().toStdString();
		string artist = artistLine->text().toStdString();
		string gen = genLine->text().toStdString();

		if (serv.add(titlu, artist, gen) == false) {
			QMessageBox msgBox;
			msgBox.setText("Date invalide");
			msgBox.exec();
		}

		reloadData();
		clearText();
	}

	void clearText() {
		titluLine->setText("");
		artistLine->setText("");
		genLine->setText("");
	}

	void delFunc() {
		if (table->selectionModel()->selectedIndexes().isEmpty()) {
			QMessageBox msgBox;
			msgBox.setText("Selecteaza melodia");
			msgBox.exec();
			return;
		}

		auto row = table->selectionModel()->selectedIndexes().at(0).row();

		auto cellId = table->model()->index(row, 0);

		int  id = stoi(table->model()->data(cellId, Qt::DisplayRole).toString().toStdString());

		serv.deleteById(id);

		reloadData();
	}
};