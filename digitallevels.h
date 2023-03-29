#ifndef DIGITALLEVELS_H
#define DIGITALLEVELS_H

#include <QDialog>

namespace Ui {
class DigitalLevels;
}

class DigitalLevels : public QDialog
{
    Q_OBJECT

public:
    explicit DigitalLevels(QWidget *parent = nullptr);
    ~DigitalLevels();

private:
    Ui::DigitalLevels *ui;

private slots:
    void on_digLevel1_clicked();

};

#endif // DIGITALLEVELS_H
