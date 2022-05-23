#include "manager.h"

Manager::Manager( QObject * parent ) : QObject( parent ),
                                       principal( new Principal ),
                                       login( new Login ),
                                       ventana ( new Ventana )
{

    QVector< QStringList > nuevosUsuarios;

    QStringList usuario1;  usuario1 << "carlos" << "123";
    QStringList usuario2;  usuario2 << "miguel" << "1234";
    QStringList usuario3;  usuario3 << "julio" << "12345";

    nuevosUsuarios << usuario1 << usuario2 << usuario3;

    login->setBaseUsuarios( nuevosUsuarios );

    connect( login, SIGNAL( signal_usuarioValidado( bool, QStringList ) ),
             this, SLOT( slot_usuarioValido( bool, QStringList ) ) );

    connect(principal, SIGNAL( signal_cerrarSesion() ), login, SLOT( show() ) );

    connect(ventana, SIGNAL( signal_cerrarSesion() ), login, SLOT( show() ) );

    connect(principal, SIGNAL( signal_ok() ), ventana, SLOT( show() ) );
}

void Manager::iniciar() {
    login->show();
}

void Manager::slot_usuarioValido( bool isValido, QStringList user ) {
    if ( isValido )  {
        login->hide();
        principal->show();
        principal->setWindowTitle( "Bienvenido: " + user.at( 0 ) );
    }
    else  {
        login->close();
    }
}
