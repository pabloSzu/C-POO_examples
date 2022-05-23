#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>

namespace Ui {
class Formulario;
}

class Formulario : public QWidget{
    Q_OBJECT

public:
    explicit Formulario( QWidget *parent = 0 );
    ~Formulario();
    static Formulario *getInstancia();

private:
    Ui::Formulario *ui;
    static Formulario *instancia;

signals:
    void signal_cerrarSesion();
    void signal_agregarUsuario();

private slots:
    void slot_pbCerrarSesion();
    void slot_pbAgregar();
};

#endif // FORMULARIO_H
