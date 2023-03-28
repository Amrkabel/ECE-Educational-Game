#ifndef DIGITALLEVEL1_H
#define DIGITALLEVEL1_H

#include <QDialog>

namespace Ui {
class DigitalLevel1;
}

class DigitalLevel1 : public QDialog
{
    Q_OBJECT

public:
    explicit DigitalLevel1(QWidget *parent = nullptr);
    ~DigitalLevel1();

private slots:
    void on_submitDigitalLevel1_clicked();

private:
    Ui::DigitalLevel1 *ui;
};

#endif // DIGITALLEVEL1_H
