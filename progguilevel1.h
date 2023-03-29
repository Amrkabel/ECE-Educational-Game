#ifndef PROGGUILEVEL1_H
#define PROGGUILEVEL1_H
#include "Programming.h"

#include <QDialog>

namespace Ui {
class ProgGuiLevel1;
}

class ProgGuiLevel1 : public QDialog
{
    Q_OBJECT

public:
    explicit ProgGuiLevel1(QWidget *parent = nullptr);
    ~ProgGuiLevel1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ProgGuiLevel1 *ui;
};



#endif // PROGGUILEVEL1_H
