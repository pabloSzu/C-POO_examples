#ifndef LISTADOGENERICO_H
#define LISTADOGENERICO_H

#include <QVector>
#include "ordenador.h"

template <class T> class ListadoGenerico : public QVector<T> {
private:
    Ordenador<T> ord;
public:
    void ordenar(void (Ordenador<T>::*puntero_funcion)(T * v, int n)) {
        (ord.*puntero_funcion)(this->data(), this->size());
    }
};

class Persona {
private:
    int edad;
public:
    Persona(int edad = 5) : edad(edad) { }

    bool operator>(Persona other) {
        if (this->edad > other.edad) {
            return true;
        }
        return false;
    }

    int getEdad() const {
        return this->edad;
    }
};

#endif // LISTADOGENERICO_H
