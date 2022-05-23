#include "boton.h"
#include <QMouseEvent>
#include <QPainter>
#include <QColor>

Boton::Boton(QWidget *parent) : QWidget(parent)
{

}

void Boton::setAspecto(QString texto, Boton::Color color)
{
    this->texto = texto;
    this->color = color;
}

void Boton::setTexto(QString texto)
{
    this->texto = texto;
}

void Boton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);//this referiencia al mismo boton, seria el liezo a pintar0
    QColor color;
    switch (this->color) {
    case ROJO:
        color.setNamedColor("#e51400");
        break;
    case CELESTE:
        color.setNamedColor("#aaabbb");
        break;
    case AZUL:
        color.setNamedColor("#eeeeee");
        break;
    default:
        break;
    }
    painter.fillRect(color);
    painter.drawText(this->texto);
}

void Boton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton) {
        emit signal_click();
    }
}

