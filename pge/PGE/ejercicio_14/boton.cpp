#include "boton.h"
#include "ui_boton.h"
#include <QPainter>
#include <QPen>

Boton::Boton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Boton)
{
    ui->setupUi(this);
}

Boton::~Boton() {
    delete ui;
}

void Boton::configurarAspecto(QString texto, unsigned int colorTexto, unsigned int colorFondo) {
    this->texto = texto;
    this->colorTexto = colorTexto;
    this->colorFondo = colorFondo;
    this->repaint();
}

void Boton::mousePressEvent(QMouseEvent *e) {
    if(e->button() == Qt::LeftButton) {
        emit signal_clic();
    }
}

void Boton::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPen pen;
    QRgb rgb = colorFondo;
    QColor colorF(rgb);
    //pen.setColor(colorFondo);
    painter.fillRect(0, 0, this->width(), this->height(), colorF);
    pen.setColor(colorTexto);
    painter.drawText(this->width()/2, this->height()/2, "Aceptar");
}
