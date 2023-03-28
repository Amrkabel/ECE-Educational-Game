#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QMainWindow>
#include<QLabel>
#include<QPixmap>
#include<Qcolor>
#include<QColorDialog>
#include<QPalette>
#include "programming_levels.h"
#include "digitallevels.h"
#include "circuitlevels.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("ECE GAME");
    resize(700,500);


    QPixmap pix("C:/Users/Savitaj Singh/Desktop/5010/qt app/resources/home.png");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    /* COLOR CODING OF THE WIDGETS AND BACKGROUND*/
    ui->Programming->setStyleSheet("background-color:#C06F49");
    ui->DigitalLogic->setStyleSheet("background-color:#C06F49");
    ui->Circuits->setStyleSheet("background-color:#C06F49");

    connect(ui->Programming, SIGNAL(clicked()), this, SLOT(on_Programming_clicked()));
    connect(ui->DigitalLogic, SIGNAL(clicked()), this, SLOT(on_DigitalLogic_clicked()));
    connect(ui->Circuits, SIGNAL(clicked()), this, SLOT(on_Circuits_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Programming_clicked(){
    this->hide();
    Programming_levels *prog = new Programming_levels();
    prog->setModal(true);
    prog->exec();
}

void MainWindow::on_DigitalLogic_clicked(){
    this->hide();
    DigitalLevels *diglog = new DigitalLevels();
    diglog->setModal(true);
    diglog->exec();
}

void MainWindow::on_Circuits_clicked(){
    this->hide();
    CircuitLevels *cir = new CircuitLevels();
    cir->setModal(true);
    cir->exec();
}

