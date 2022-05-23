#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QCloseEvent>

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

protected:
    void closeEvent(QCloseEvent *event);

signals:
    void signal_cerrarSesion();
    void signal_agregarUsuario(QStringList usuario);
    void signal_cierreFormulario();

private slots:
    void slot_pbCerrarSesion();
    void slot_pbAgregar();
};

#endif // FORMULARIO_H
