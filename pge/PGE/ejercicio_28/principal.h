#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QVector>
#include "persona.h"

namespace Ui {
class Principal;
}

class Principal : public QWidget
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);
    ~Principal();

private:
    Ui::Principal *ui;
    QVector<Persona*> vector;

private slots:
    void slot_agregar();
};

#endif // PRINCIPAL_H
