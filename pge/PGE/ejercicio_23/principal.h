#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>

namespace Ui {
class Principal;
}

class Principal : public QWidget {
    Q_OBJECT

public:
    explicit Principal( QWidget *parent = 0 );
    ~Principal();
    static Principal *getInstancia();

private:
    Ui::Principal *ui;
    static Principal *instancia;

signals:
    void signal_ok();
    void signal_cerrarSesion();

private slots:
    void slot_pbCerrarSesion();
    void slot_pbOk();

};

#endif // PRINCIPAL_H
