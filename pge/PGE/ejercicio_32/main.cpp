#include <QDebug>
#include "listadeenteros.h"

int main ( ) {
    ListaDeEnteros l;
    void (Ordenador::*puntero_funcion)(int * v, int n);

    puntero_funcion = &Ordenador::seleccion;

    l.push_back(8);
    l.push_back(10);
    l.push_back(3);
    l.push_back(5);
    l.push_back(1);

    l.ordenar(puntero_funcion);

    for(int i = 0; i < l.size(); i++) {
        qDebug() << l.at(i);
    }

    return 0;
}
