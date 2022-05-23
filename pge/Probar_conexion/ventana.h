#ifndef VENTANA_H
#define VENTANA_H

#include "medidor.h"
#include <QWidget>
#include <QNetworkAccessManager>

namespace Ui {
class Ventana;
}

class Ventana : public QWidget {
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = 0);
    ~Ventana();

private:
    Ui::Ventana *ui;
    QNetworkAccessManager *manager;

private slots:
    void SLOT_CONEXION_OK();
};

#endif // VENTANA_H
