#include "SimularePractic.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/Qtableview>

#include <assert.h>

#include "Melodie.h"
#include "Repository.h"
#include "Service.h"
#include "MainApp.h"
#include "TableItem.h"

void testAll() {
	TestMelodie tm{}; tm.testAllMelodie();
	TestRepo tr{}; tr.testAllRepo();
	TestServiec ts{}; ts.TestAllServiec();
	TestTableItem tt{}; tt.testAllItem();
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	testAll();

	Repository repo{ "Data.csv" };
	Service serv{ repo };

	MainApp ma{ serv }; ma.show();

	return a.exec();
}
