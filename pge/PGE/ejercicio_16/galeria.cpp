#include "galeria.h"
#include "ui_galeria.h"

Galeria::Galeria(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Galeria)
{
    ui->setupUi(this);
}

Galeria::~Galeria() {
    delete ui;
}

void Galeria::paintEvent(QPaintEvent *)  {
    QPainter painter(this);
    if(!(im.isNull())) {
        painter.drawImage(this->width()/2 - im.width()/2, this->height()/2 - im.height()/2, im.scaled(100, 100));
    }
}

void Galeria::slot_mostrarImagen() {

    im.load("../../../../ejercicio_16/imagenes/.png");
}
