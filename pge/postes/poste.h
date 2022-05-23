#ifndef POSTE_H
#define POSTE_H

#include <QDebug>


//------------------CLASE 3 (SOBRECARGA DE OPERADORES) -------------------------------------
class Poste  {
private:
    float altura;

public:
    explicit Poste( float altura = 6 ) : altura( altura )  {
    }

    float getAltura() const  {
        return altura;
    }

    void setAltura( float altura ) {
        this->altura = altura;
    }

    Poste operator+( Poste otro )  {
        qDebug() << "Poste operator+( Poste otro ) - 2";
        Poste poste;
        poste.setAltura( this->getAltura() + otro.getAltura() );
        return poste;
    }

    Poste operator+( int otro )  {
        qDebug() << "Poste operator+( int otro ) - 3";
        Poste poste;
        poste.setAltura( this->getAltura() + otro );
        return poste;
    }

//    Poste operator~()  {
//        // 5 (en binario es 101)  ~5 ( 010 ) = 2
//        Poste poste;
////        poste.setAltura( ~( int( this->getAltura() ) ) );
//        poste.setAltura( 0 );
//        return poste;
//    }

    void operator~()  {
        this->setAltura( -1 );
    }


};


// Operador global
Poste operator+( int entero, Poste poste )  {
    qDebug() << "Poste operator+( int entero, Poste poste ) - 1";
    Poste posteRes;
    posteRes.setAltura( entero + poste.getAltura() );
    return posteRes;
}


#endif // POSTE_H

