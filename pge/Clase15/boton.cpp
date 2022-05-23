#include "boton.h"
#include "ui_boton.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

Boton::Boton( Boton::Red mired, QWidget *parent ) : QWidget( parent ),
                                                    ui( new Ui::Boton ),
                                                    red( mired )
{
    this->resize( 150, 20 );
}

Boton::~Boton()
{
    delete ui;
}

void Boton::setRed( Boton::Red nred)
{
    red = nred;
    this->repaint();
}

Boton::Red Boton::getRed()
{
    return red;
}

void Boton::setTexto(QString texto)
{
    ui->lTexto->setText( texto );
}

QString Boton::texto()
{
    return ui->lTexto->text();
}


int imagen_num = 0;
void Boton::paintEvent( QPaintEvent * )
{
    QPainter painter( this );
    QImage imagen;

    switch ( red ) {
        case Facebook:
            imagen.load( ":/Facebook" );
            imagen_num ++;
            break;
        case Twitter:
            imagen.load( ":/Twitter" );
            break;
        case Google:
            imagen.load( ":/Google" );
            break;
        case LinkedIn:
            imagen.load( ":/LinkedIn" );
            break;
        case Instagram:
            imagen.load( ":/Instagram" );
            break;
        case Otra:
            imagen.load( ":/Otra" );
            break;
    }

    painter.drawImage( QRect( 0, 0, this->width(), this->height() ), imagen );
}

void Boton::mousePressEvent( QMouseEvent *event )
{
    if ( event->button() == Qt::LeftButton ){
        emit signal_click( red );
    }
}

void Boton::click()
{
    emit signal_click( red );
}
