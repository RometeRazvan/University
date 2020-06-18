#include "Lab10_2017.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/qlabel.>
#include <QtWidgets/qpushbutton.>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlineedit.h>

#include "TestService.h"
#include "mainApp.h"
#include "FilterApp.h"
#include "Ui.h"
#include "cosCRUDGUI.h"
#include "CosDesen.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);

	Service serv{ "Data.csv" };

	//mainApp ma{ serv }; ma.show();

	cosCRUDGUI cos{ serv }; cos.show();

	return a.exec();
}
