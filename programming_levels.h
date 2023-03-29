#ifndef PROGRAMMING_LEVELS_H
#define PROGRAMMING_LEVELS_H

#include <QDialog>

namespace Ui {
class Programming_levels;
}

class Programming_levels : public QDialog
{
    Q_OBJECT

public:
    explicit Programming_levels(QWidget *parent = nullptr);
    ~Programming_levels();

private:
    Ui::Programming_levels *ui;

private slots:
    void on_progLevel1_clicked();
};

#endif // PROGRAMMING_LEVELS_H
