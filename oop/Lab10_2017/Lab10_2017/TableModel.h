#include <QAbstractTableModel>

#include <vector>

#include "Locatar.h"
#include "MyList.h"

class TableModel : public QAbstractTableModel {
private:

	vector<Locatar> list;
	int size;

public:

	TableModel(vector<Locatar> list) : list {list} {
		size = list.size();
	}

	int rowCount(const QModelIndex &parent = QModelIndex()) const override {
		return size;
	}

	int columnCount(const QModelIndex &parent = QModelIndex()) const override {
		return 4;
	}

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
		if (role == Qt::DisplayRole) {
			Locatar locatar = list[index.row()];

			if (index.column() == 0)
				return QString::fromStdString(locatar.getApartament());
			if (index.column() == 1)
				return QString::fromStdString(locatar.getNume());
			if (index.column() == 2)
				return QString::fromStdString(locatar.getSuprafata());
			if (index.column() == 3)
				return QString::fromStdString(locatar.getTip());
		}

		return QVariant{};
	}

	QVariant headerData(int section, Qt::Orientation orientation, int role) const {
		if (role == Qt::DisplayRole) {
			if (orientation == Qt::Horizontal) {
				if (section == 0)
					return QString::fromStdString("Apartament");
				if (section == 1)
					return QString::fromStdString("Nume");
				if (section == 2)
					return QString::fromStdString("Suprafata");
				if (section == 3)
					return QString::fromStdString("Tip");
			}
		}
		return QVariant();
	}

};