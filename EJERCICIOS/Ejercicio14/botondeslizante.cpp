#include "botondeslizante.h"
#include "ui_botondeslizante.h"

#include <QDebug>

BotonDeslizante::BotonDeslizante(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BotonDeslizante)
{
    ui->setupUi(this);
}

BotonDeslizante::~BotonDeslizante()
{
    delete ui;
}

BotonDeslizante::configurarAspectoOp(QString texto, unsigned int colorTexto, unsigned int colorFondo)
{
    this->texto = texto;
    this->colorTexto = colorTexto;
    this->colorFondo = colorFondo;

}

void BotonDeslizante::mousePressEvent(QMouseEvent *e) {

    if(e->button() == Qt::LeftButton){
        emit signal_click();
    }
}

void BotonDeslizante::paintEvent(QPaintEvent *)
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
