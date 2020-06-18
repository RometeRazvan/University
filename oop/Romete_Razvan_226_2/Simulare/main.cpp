#include "Simulare.h"
#include <QtWidgets/QApplication>

#include "MainApp.h"

#include "Participant.h"
#include "Repository.h"

using namespace std;

void testAll() {
    TestParticipant testParticipant{}; testParticipant.testAllParticipant();
    TestRepository testRepo{}; testRepo.testAllRepo();
}

int main(int argc, char *argv[])
{
    testAll();

    QApplication a(argc, argv);
    //Simulare w;
   // w.show();
    MainApp ma{"data.txt"};

    ma.show();
    return a.exec();
}
