#ifndef CIRCUITLEVELS_H
#define CIRCUITLEVELS_H

#include <QDialog>

namespace Ui {
class CircuitLevels;
}

class CircuitLevels : public QDialog
{
    Q_OBJECT

public:
    explicit CircuitLevels(QWidget *parent = nullptr);
    ~CircuitLevels();

private:
    Ui::CircuitLevels *ui;
};

#endif // CIRCUITLEVELS_H
