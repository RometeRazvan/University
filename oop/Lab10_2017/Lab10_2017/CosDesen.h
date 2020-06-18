#pragma once

#include <qtwidgets/qwidget.h>

#include <qpainter.h>
#include <stdlib.h>

using namespace std;

class CosDesen : public QWidget, public Observable {
public:

	CosDesen(Service& serv) : serv{ serv } {
		initWindow();
	}

private:

	Service& serv;
	Cos cos;

	void initWindow() {
		serv.addObservable(this);
	}

	int randomPoz() {
		return rand() % 300;
	}

	int randomSize() {
		return (rand() + 40) % 200;
	}

	void paintEvent(QPaintEvent* ev) override {
		int size = cos.size();

		QPainter p{ this };

		while (size) {
			--size;

			int x = randomPoz();
			int y = randomPoz();

			int l = randomSize();
			int h = randomSize();
		
			p.drawRect(x, y, l, h);
		}
	}


	void notifyObserver() override { repaint(); }

	void getNotified(Cos cosP) override {
		cos = cosP;

		repaint();
	}

};