#ifndef LISTADO_H
#define LISTADO_H

#include <QDebug>

template< class T > class Listado  {
public:
    Listado( int n = 10 );
    bool add( T nuevo );
    T get( int i ) const;
    int length() const;
    int getCantidad() const;
    Listado< T > operator+( const Listado< T > otro );

private:
    int cantidad;
    int libre;
    T *v;
};


template< class T > Listado< T >::Listado( int n ) : cantidad( n ), libre( 0 ), v( new T[ n ] )  {

}

template< class T > bool Listado< T >::add( T nuevo )  {
    if ( libre < cantidad )  {
        v[ libre ] = nuevo;
        libre++;
        return true;
    }
    return false;
}


template< class T > T Listado< T >::get( int i ) const  {  return v[ i ];  }

template< class T > int Listado< T >::length() const  {  return libre;  }

template< class T > int Listado< T >::getCantidad() const  {  return cantidad;  }




//------------------CLASE 3 (SOBRECARGA DE OPERADORES) -------------------------------------
template< class T > Listado< T > Listado< T >::operator+( const Listado< T > otro )  {
    T vAux[ this->length() + otro.length() ];

    int contador = 0;

    for ( ; contador < this->length() ; contador++ )
            vAux[ contador ] = this->get( contador );

    for ( int i = 0 ; contador < ( this->length() + otro.length() ) ; contador++, i++ )
            vAux[ contador ] = otro.get( i );

    Listado< T > res( this->getCantidad() + otro.getCantidad() );

    for ( int j = 0 ; j < contador ; j++ )
            res.add( vAux[ j ] );

    return res;
}

#endif // LISTADO_H
