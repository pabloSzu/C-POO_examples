#include "principal.h"
#include "ui_principal.h"

principal::principal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::principal) {

    ui->setupUi(this);
    this->setFixedSize(200,200);
    ui->tuLabel->cambiarTexto("Sos un TuLabel?");
}

principal::~principal()
{
    delete ui;
}
