#include <QDebug>
#include "listadogenerico.h"

int main ( ) {
    ListadoGenerico<int> l;
    void (Ordenador<int>::*puntero_funcion)(int * v, int n);

    puntero_funcion = &Ordenador<int>::burbuja;

    l.push_back(8);
    l.push_back(10);
    l.push_back(3);
    l.push_back(5);
    l.push_back(1);

    l.ordenar(puntero_funcion);

    for(int i = 0; i < l.size(); i++) {
        qDebug() << l.at(i);
    }

    ListadoGenerico<Persona> personas;
    void (Ordenador<Persona>::*puntero)(Persona *v, int n);

    puntero = &Ordenador<Persona>::burbuja;

    personas.push_back(10);
    personas.push_back(4);

    personas.ordenar(puntero);

    for(int i = 0; i < personas.size(); i++) {
        qDebug() << personas.at(i).getEdad();
    }

    return 0;
}
