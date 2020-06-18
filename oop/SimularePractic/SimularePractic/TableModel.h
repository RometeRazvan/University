#include <QAbstractTableModel>

#include <vector>
#include <string>
#include <assert.h>

#include "TableItem.h"

using namespace std;

class TableModel : public QAbstractTableModel {
private:
	vector<TableItem> list;
public:

	TableModel(vector<TableItem> vec) {
		list = vec;
	}

	int rowCount(const QModelIndex &parent = QModelIndex()) const override {
		return list.size();
	}

	int columnCount(const QModelIndex &parent = QModelIndex()) const override {
		return 6;
	}

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
		if (role == Qt::DisplayRole) {
			TableItem ta = list[index.row()];

			if (index.column() == 0)
				return QString::number(ta.getId());
			if (index.column() == 1)
				return QString::fromStdString(ta.getTilu());
			if (index.column() == 2)
				return QString::fromStdString(ta.getArtist());
			if (index.column() == 3)
				return QString::fromStdString(ta.getGen());
			if (index.column() == 4)
				return QString::number(ta.getNrAutor());
			if (index.column() == 5)
				return QString::number(ta.getNrGen());
		}

		return QVariant();
	}

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
		if (role == Qt::DisplayRole) {
			if (orientation == Qt::Horizontal) {
				if (section == 0)
					return QString::fromStdString("Id");
				if (section == 1)
					return QString::fromStdString("Titlu");
				if (section == 2)
					return QString::fromStdString("Artist");
				if (section == 3)
					return QString::fromStdString("Piesa");
				if (section == 4)
					return QString::fromStdString("nrArtisi");
				if (section == 5)
					return QString::fromStdString("nrGen");
			}
		}

		return QVariant();
	}

	void updateModel() {
		QModelIndex topLeft = createIndex(0, 0);
		QModelIndex btmRight = createIndex(rowCount(), columnCount());
		emit dataChanged(topLeft, btmRight);
	}

	void setList(vector<TableItem> vec) {
		list = vec;
	}
};