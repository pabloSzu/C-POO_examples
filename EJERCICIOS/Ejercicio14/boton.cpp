#include "boton.h"
#include "ui_boton.h"

#include <QDebug>

Boton::Boton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Boton)
{
    ui->setupUi(this);
}

Boton::~Boton()
{
    delete ui;
}

Boton::configurarAspectoAc(QString texto, unsigned int colorTexto, unsigned int colorFondo)
{
    this->texto = texto;
    this->colorTexto = colorTexto;
    this->colorFondo = colorFondo;

}


void Boton::mousePressEvent(QMouseEvent *e) {

    if(e->button() == Qt::LeftButton){
        emit signal_click();
    }
}

void Boton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    QRgb rgb = colorFondo;
    QColor colorF(rgb);


    pen.setColor(colorFondo);
    painter.fillRect(0,0, this->width(), this->height(), colorF);

    painter.setPen(colorTexto);
    painter.drawText(this->width()/4, this->height()/2, texto);
}

