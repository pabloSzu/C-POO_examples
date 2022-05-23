#include "manager.h"
#include "principal.h"
#include "login.h"
#include "formulario.h"
#include "logger.h"

Manager * Manager::instancia = NULL;

Manager::Manager( QObject * parent ) : QObject( parent ) {

    QVector< QStringList > nuevosUsuarios;

    QStringList usuario1;  usuario1 << "carlos" << "123";
    QStringList usuario2;  usuario2 << "miguel" << "1234";
    QStringList usuario3;  usuario3 << "julio" << "12345";

    nuevosUsuarios << usuario1 << usuario2 << usuario3;

    Login::getInstancia()->setBaseUsuarios( nuevosUsuarios );

    connect( Login::getInstancia(), SIGNAL( signal_usuarioValidado( bool, QStringList ) ),
             this, SLOT( slot_usuarioValido( bool, QStringList ) ) );

    connect( Principal::getInstancia(), SIGNAL( signal_cerrarSesion() ), Login::getInstancia(), SLOT( show() ) );

    connect( Formulario::getInstancia(), SIGNAL( signal_cerrarSesion() ), Login::getInstancia(), SLOT( show() ) );

    connect( Principal::getInstancia(), SIGNAL( signal_ok() ), Formulario::getInstancia(), SLOT( show() ) );

    //connect( Formulario::getInstancia(), SIGNAL( signal_agregarUsuario() ),  );
}

Manager * Manager::getInstancia() {
    if( instancia == NULL ) {
        instancia = new Manager();
    }
    return instancia;
}

void Manager::iniciar() {
    Login::getInstancia()->show();
}

void Manager::slot_usuarioValido( bool isValido, QStringList user ) {
    if ( isValido )  {
        Logger::registrar("Usuario válido logeado", "../../../../ejercicio_23/logs/registros.txt");
        Login::getInstancia()->hide();
        Principal::getInstancia()->show();
        Principal::getInstancia()->setWindowTitle( "Bienvenido: " + user.at( 0 ) );
    }
    else  {
        Logger::registrar("Usuario inválido", "../../../../ejercicio_23/logs/registros.txt");
        Login::getInstancia()->close();
    }
}
