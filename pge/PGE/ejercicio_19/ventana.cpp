#include "ventana.h"
#include "ui_ventana.h"
#include <QPainter>

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
    im.load("../../../../ejercicio_19/imagen.png");

    connect(ui->pbConvertir, SIGNAL(pressed()), this, SLOT(slot_convertirImagen()));
}

Ventana::~Ventana() {
    delete ui;
}

void Ventana::paintEvent(QPaintEvent *)  {
    QPainter painter(this);
    if(!(im.isNull())) {
        painter.drawImage(0, 0, im.scaled(this->width(), this->height()));
    }
}

void Ventana::slot_convertirImagen() {

}
