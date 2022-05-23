#include "formulario.h"
#include "ui_formulario.h"

Formulario *Formulario::instancia = NULL;

Formulario::Formulario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formulario)
{
    ui->setupUi(this);

    this->setWindowTitle("Formulario");

    connect( ui->pbCerrar, SIGNAL( pressed() ), this, SLOT( slot_pbCerrarSesion() ) );

    connect( ui->pbAgregar, SIGNAL( pressed() ), this, SLOT( slot_pbAgregar() ) );
}

Formulario::~Formulario()
{
    delete ui;
}

Formulario *Formulario::getInstancia() {
    if( instancia == NULL ) {
        instancia = new Formulario();
    }
    return instancia;
}

void Formulario::slot_pbCerrarSesion() {
    this->hide();
    emit signal_cerrarSesion();
}

void Formulario::slot_pbAgregar() {
    emit signal_agregarUsuario();
}
