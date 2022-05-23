#include "widget.h"

#include "poste.h"

#include "listado.h"

#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Listado< int > l1( 4 );
    Listado< int > l2( 3 );
    Listado< int > l3( 10 );

    l1.add( 1 );
    l1.add( 2 );
    l1.add( 3 );

    l2.add( 10 );
    l2.add( 11 );

    l3 = l2 + l1;

    qDebug() << "-- l1 ---------------- " << l1.getCantidad();
    for ( int i = 0 ; i < l1.length() ; i++ )  {
        qDebug() << l1.get( i );
    }

    qDebug() << "-- l2 ----------------" << l2.getCantidad();
    for ( int i = 0 ; i < l2.length() ; i++ )  {
        qDebug() << l2.get( i );
    }

    qDebug() << " -- l3 ----------------" << l3.getCantidad();
    for ( int i = 0 ; i < l3.length() ; i++ )  {
        qDebug() << l3.get( i );
    }



  //  return 0;









    Poste p1;
    Poste p2( 8 );
    Poste p3;

    p3 = p1 + p2;
    qDebug() << p3.getAltura();

    p3 = p1 + 5;  // p3 = p1.operator( 5 )
    qDebug() << p3.getAltura();

    p3 = 5 + p1;
    qDebug() << p3.getAltura();

    p3 = 5 + p1 + p2 + 7;
    qDebug() << p3.getAltura();

    p3.getAltura() > 7 ? p3.setAltura( 10 ) : p3.setAltura( 5 );
    qDebug() << p3.getAltura();

//    p3 = ~p2;
//    qDebug() << p3.getAltura();

    ~p2;
    qDebug() << p2.getAltura();


    return 0;
}

