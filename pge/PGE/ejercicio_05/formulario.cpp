#include "formulario.h"
#include "ui_formulario.h"

formulario::formulario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::formulario) {
    ui->setupUi(this);

    connect(ui->le1, SIGNAL(textChanged(QString)), this, SLOT(slot_textoCambiado()));
    connect(ui->le2, SIGNAL(textChanged(QString)), this, SLOT(slot_textoCambiado()));
}

formulario::~formulario() {
    delete ui;
}

void formulario::slot_textoCambiado( ) {
    *ui->le4 = *ui->le1 + *ui->le2;
}
