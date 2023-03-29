#include "circuitlevels.h"
#include "ui_circuitlevels.h"

CircuitLevels::CircuitLevels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CircuitLevels)
{
    ui->setupUi(this);
    resize(700,500);
}

CircuitLevels::~CircuitLevels()
{
    delete ui;
}
