#include "principal.h"
#include "ui_principal.h"

Principal::Principal( QWidget *parent ) :
    QWidget( parent ),
    ui( new Ui::Principal ) {

    ui->setupUi( this );

    connect( ui->pbCerrar, SIGNAL( pressed() ), this, SLOT( slot_pbCerrarSesion() ) );

    connect( ui->pbOk, SIGNAL( pressed() ), this, SLOT( slot_pbOk() ) );
}

Principal::~Principal() {
    delete ui;    
}

void Principal::slot_pbCerrarSesion() {
    this->hide();
    emit signal_cerrarSesion();
}

void Principal::slot_pbOk() {
    this->hide();
    emit signal_ok();
}
