#include "programming_levels.h"
#include "ui_programming_levels.h"
#include "progguilevel1.h"

Programming_levels::Programming_levels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Programming_levels)
{
    ui->setupUi(this);
    resize(700,500);

    ui->progLevel1->setStyleSheet("background-color:#C06F49");
    ui->progLevel2->setStyleSheet("background-color:#C06F49");
    ui->progLevel3->setStyleSheet("background-color:#C06F49");

    connect(ui->progLevel1, SIGNAL(clicked()), this, SLOT(on_progLevel1_clicked()));
}

Programming_levels::~Programming_levels()
{
    delete ui;
}

void Programming_levels::on_progLevel1_clicked(){
    this->hide();
    ProgGuiLevel1 *progLev1 = new ProgGuiLevel1;
    progLev1->setModal(true);
    progLev1->exec();
}
