#include "login.h"
#include "ui_login.h"
#include "logger.h"

Login *Login::instancia = NULL;

Login::Login( QWidget * parent ) : QWidget( parent ),
                                   ui( new Ui::Login ) {
    ui->setupUi( this );

    this->setWindowTitle("Login");

    QStringList usuarioAdmin;
    usuarioAdmin << "admin" << "nimda";

    usuarios << usuarioAdmin;

    connect( ui->pbIngresar, SIGNAL( pressed() ), this, SLOT( slot_validarUsuario() ) );
    connect( ui->leClave, SIGNAL( returnPressed() ), this, SLOT( slot_validarUsuario() ) );
}

Login::~Login() {
    delete ui;
}

Login * Login::getInstancia(){
    if( instancia == NULL ) {
        instancia = new Login();
    }
    return instancia;
}

void Login::setBaseUsuarios( QVector< QStringList > usuarios ) {
    this->usuarios << usuarios;
}

void Login::slot_validarUsuario() {
    QStringList usuarioIngresado;
    usuarioIngresado << ui->leUsuario->text() << ui->leClave->text();

    if ( this->usuarios.contains( usuarioIngresado ) )
        emit signal_usuarioValidado( true, usuarioIngresado );
    else
        emit signal_usuarioValidado( false, usuarioIngresado );
}
