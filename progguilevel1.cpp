#include "progguilevel1.h"
#include "ui_progguilevel1.h"
#include "Programming.h"
#include "proglev1.h"

#include <QLabel>
#include <QMessageBox>
#include <iostream>
#include<algorithm>

ProgGuiLevel1::ProgGuiLevel1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgGuiLevel1)
{
    ui->setupUi(this);

    resize(1700,1700);

    //A label is created that showcases the code, which the user reads to find the syntax errors.

    std::string s = "";
    std::vector<int> v;

    Programming p(s,v);
    p = inputs_lev1();
    std::string str = p.getCode();

    QString text = QString::fromStdString(str);
    QStringList lines = text.split(".");

    QString formattedText;
    for (int i = 0; i < lines.length(); i++) {
        formattedText += lines[i].trimmed() + "\n   ";
    }

    QLabel* label = new QLabel(this);
    label->setText(formattedText);
    label->setFont(QFont("Times", 16));
    label->setGeometry(50, 50, 1000,600);


    //Label telling the user what task is to be done.

    QLabel*label1 = new QLabel(this);
    label1->setText("Enter the line numbers containig errors");
    label1->setGeometry(550,650,400,50);
    label1->setFont(QFont("Times", 13));

    //There are two inputs that have been created in .ui file. The names of the inputs are: error1 and error2.
}

ProgGuiLevel1::~ProgGuiLevel1()
{
    delete ui;
}

void ProgGuiLevel1::on_pushButton_clicked()
{
    std::string t = "";
    std::vector<int> u;
    Programming q(t, u);
    q = inputs_lev1();

    std::vector<int> errors = q.getErrors();

    int e1 = (ui->lineEdit->text()).toInt();
    int e2 = (ui->lineEdit_2->text()).toInt();

    std::vector<int> user_input;
    user_input.push_back(e1);
    user_input.push_back(e2);

//sort is used because the user might enter the input in reverse order to what is stored in "errors".
    std::sort(errors.begin(), errors.end());
    std::sort(user_input.begin(), user_input.end());
;


    if (user_input == errors){
        QMessageBox::information(this, "Correct", "That's Right");
    }
    else{
        QMessageBox::information(this, "Oops", "Please Try Again");
    }
}

