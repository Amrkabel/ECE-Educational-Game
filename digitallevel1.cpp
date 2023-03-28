#include <iostream>
#include "digitallevel1.h"
#include "ui_digitallevel1.h"
#include "Nodes.h"
#include "Gates.h"
#include "DigitalLogic.h"
#include "DigitalLogicLevel1.h"
#include <QMessageBox>
#include <vector>

DigitalLevel1::DigitalLevel1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DigitalLevel1)
{
    ui->setupUi(this);
    resize(1000,500);


}

DigitalLevel1::~DigitalLevel1()
{
    delete ui;
}

void DigitalLevel1::on_submitDigitalLevel1_clicked()
{
    std::string g1 = (ui->gate1->text()).toStdString();
    std::string g2 = (ui->gate2->text()).toStdString();



    bool result = result_Logic(g1, g2);
    std::cout<< result << std::endl;
    std::cout<< g1<<std::endl;

    if (result == true){
        QMessageBox::information(this, "Correct", "That's Right");
    }
    else{
        QMessageBox::information(this, "Oops", "Please Try Again");
    }
}

