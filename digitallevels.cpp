#include "digitallevels.h"
#include "ui_digitallevels.h"
#include "digitallevel1.h"

DigitalLevels::DigitalLevels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DigitalLevels)
{
    ui->setupUi(this);
    resize(900,500);

    ui->digLevel1->setStyleSheet("background-color:#C06F49");
    ui->digLevel2->setStyleSheet("background-color:#C06F49");
    ui->digLevel3->setStyleSheet("background-color:#C06F49");

    connect(ui->digLevel1, SIGNAL(clicked()), this, SLOT(on_digLevel1_clicked()));

}

DigitalLevels::~DigitalLevels()
{
    delete ui;
}

void DigitalLevels::on_digLevel1_clicked(){
    this->hide();
    DigitalLevel1 *digLev1 = new DigitalLevel1;
    digLev1->setModal(true);
    digLev1->exec();
}


