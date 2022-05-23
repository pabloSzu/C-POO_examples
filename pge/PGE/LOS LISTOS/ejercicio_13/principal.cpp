#include "principal.h"
#include "ui_principal.h"

principal::principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principal) {

    ui->setupUi(this);

    connect(ui->actionSalir, SIGNAL(triggered(bool)), this, SLOT(slot_cerrar()));

    connect(ui->actionAbrir, SIGNAL(triggered(bool)), this, SLOT(slot_abrir()));
}

principal::~principal() {
    delete ui;
}

void principal::slot_cerrar() {
    this->close();
}

void principal::slot_abrir() {

}
