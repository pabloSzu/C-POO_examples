#ifndef WSOCIAL_H
#define WSOCIAL_H

#include <QWidget>

class Boton;
class QLabel;

class WSocial : private QWidget
{

public:
    static WSocial* getInstancia();

    void iniciar();

    void add_boton( Boton );

private:
    static WSocial * instancia;

    Boton * b;
    QLabel* lInf;
    QLabel* lSoc;

    WSocial( QWidget * parent = nullptr );

    void paintEvent( QPaintEvent *event );



};
#endif // WSOCIAL_H
