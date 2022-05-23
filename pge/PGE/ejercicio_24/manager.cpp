#include "manager.h"
#include "principal.h"
#include "login.h"
#include "formulario.h"
#include "logger.h"

Manager * Manager::instancia = NULL;

Manager::Manager( QObject * parent ) : QObject( parent ) {

    Logger::getInstancia()->abrir("../../../../ejercicio_24/registros.txt");

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

    connect( Formulario::getInstancia(), SIGNAL( signal_agregarUsuario( QStringList ) ),
             Login::getInstancia(), SLOT(slot_agregarUsuario(QStringList ) ) );

    connect( Formulario::getInstancia(), SIGNAL( signal_cierreFormulario() ), this, SLOT( slot_cierreApp()) );

    connect( Login::getInstancia(), SIGNAL( signal_cierreLogin() ), this, SLOT( slot_cierreApp()) );

    connect( Principal::getInstancia(), SIGNAL( signal_cierrePrincipal() ), this, SLOT( slot_cierreApp()) );
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
        Logger::registrarEvento("Usuario válido logueado");
        Login::getInstancia()->hide();
        Principal::getInstancia()->show();
        Principal::getInstancia()->setWindowTitle("Bienvenido: " + user.at( 0 ));
        Logger::registrarEvento("Apertura de Principal");
    }
    else {
        Logger::registrarEvento("Usuario inválido");
        Login::getInstancia()->close();
        Logger::registrarEvento("Cierre de aplicacion por usuario inválido");
    }
}

void Manager::slot_cierreApp() {
    Logger::registrarEvento("Cierre de Aplicación");
}
