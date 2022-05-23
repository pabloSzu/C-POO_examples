#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana( QWidget *parent ) :
    QWidget( parent ),
    ui( new Ui::Ventana ) {

    ui->setupUi( this );

    connect( ui->pbCerrar, SIGNAL( pressed() ), this, SLOT( slot_pbCerrarSesion() ) );
}

Ventana::~Ventana() {
    delete ui;
}

void Ventana::slot_pbCerrarSesion() {
    this->hide();
    emit signal_cerrarSesion();
}
