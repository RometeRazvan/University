#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SimularePractic.h"

class SimularePractic : public QMainWindow
{
    Q_OBJECT

public:
    SimularePractic(QWidget *parent = Q_NULLPTR);

private:
    Ui::SimularePracticClass ui;
};
