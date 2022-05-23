#include "wsocial.h"
#include "boton.h"
#include <QLabel>
#include <QPainter>

WSocial * WSocial::instancia = nullptr;

WSocial *WSocial::getInstancia()
{

    if ( instancia == nullptr ){
        instancia = new WSocial;
    }

    return instancia;
}

void WSocial::iniciar()
{
    this->setStyleSheet("background-image: /Imagenes/img.png");
    this->show();
}









/*
int aux_x = 15;
int aux_y = 5;
int aux = 0;
int cant_botones = 1;
*/

WSocial::WSocial( QWidget * parent ):
         QWidget( parent ),

         b( new Boton( Boton::Facebook, this ) ),

         lInf( new QLabel( "Conectarse con:", this ) ),
         lSoc( new QLabel( "Social", this ) )
{
    this->resize( 340, 130 );
    this->setStyleSheet("background-image: Imagenes/img.png");
    lInf->setGeometry( 5, 5, 150, 20);
    lSoc->setGeometry( 185, 5, 75, 20 );

/*
    for (int i=0; i < cant_botones; i++ )
    {
        if (aux == 0){
            aux_y = aux_y + 30;
            b->move( aux_x , aux_y );
            aux_x = 175;
            aux = 1;
        }
        else {
            b->move( aux_x , aux_y );
            aux_x = 15;
            aux = 0;
        }

    };

    bF->move( 15, 35 );
    bG->move( 175, 35 );
    bL->move( 15, 65 );
    bT->move( 175, 65 );
    bI->move( 15, 95 );
*/
}

void WSocial::paintEvent( QPaintEvent * )
{
    QPainter painter( this );

    QPen lapiz( Qt::black );

    painter.setPen( lapiz );

    painter.drawRect( QRect( 175, 5, 75, 20 ) );
    painter.drawRect( QRect( 5, 25, 330, 100 ) );
}



int aux_x = 15;
int aux_y = 5;
int aux = 0;
int cant_botones = 1;

void WSocial::add_boton(  Boton b )
{

  //  b.setTexto("HOLA");
  //  b.setRed(Boton::Facebook);

cant_botones = cant_botones + 1;
for (int i=0; i < cant_botones; i++ )
{
    if (aux == 0){
        aux_y = aux_y + 30;
        b.move( aux_x , aux_y );
        aux_x = 175;
        aux = 1;
    }
    else {
        b.move( aux_x , aux_y );
        aux_x = 15;
        aux = 0;
    }

};
}

