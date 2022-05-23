#include "boton.h"
#include "ui_boton.h"
#include <QPainter>
#include <QColor>

Boton::Boton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Boton)
{
    ui->setupUi(this);
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

Boton::~Boton()
{
    delete ui;
}

void Boton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //painter.fillRect(0, 0, this->width(), this->height()); // Completar para que pinte Color.
    QColor color;
    switch (this->color) {
    case ROJO:
        color.setNamedColor("#ES1400");
        break;
    case CELESTE:
        color.setNamedColor("");
        break;
    case AZULADO:
        color.setNamedColor("");
        break;
    default:;
    }

//    painter.fillRect(0, 0, this->width(), this->height()); //Completar
//    painter.drawText(); //Completar
}

void Boton::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
        emit signal_clic();
}
