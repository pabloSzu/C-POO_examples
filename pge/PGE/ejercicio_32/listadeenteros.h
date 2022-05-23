#ifndef LISTADEENTEROS_H
#define LISTADEENTEROS_H

#include <QVector>
#include "ordenador.h"

class ListaDeEnteros : public QVector<int> {
private:
    Ordenador ord;
public:
    // Este método ordenará los elementos
    void ordenar(void (Ordenador::*puntero_funcion)(int * v, int n)) {
        (ord.*puntero_funcion)(this->data(), this->size());
    }

};

#endif // LISTADEENTEROS_H
