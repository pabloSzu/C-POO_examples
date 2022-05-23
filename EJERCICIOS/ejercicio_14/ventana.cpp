#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
    ui->bAceptar->configurarAspecto("Aceptar", 0xFF000000, 0xFFFFFF00);
}

Ventana::~Ventana() {
    delete ui;
}

void Ventana::dimensionarWidget() {
    int borde = this->height() / 25;
    int posBotonAceptarX = borde;
    int posBotonAceptarY = 8 * this->height() / 9;
    int botonAceptarW = this->width() / 2 - 2 * borde;
    int botonAceptarH = this->height() - posBotonAceptarY - borde;

    ui->bAceptar->resize(botonAceptarW, botonAceptarH);
    ui->bAceptar->move(posBotonAceptarX, posBotonAceptarY);
}
