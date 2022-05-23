#ifndef LISTADOGENERICO_H
#define LISTADOGENERICO_H

#include <QVector>

template <class T> class ListadoGenerico : public QVector<T> {
public:
    void ordenar(void (*pFuncionOrdenamiento)(T *, int))  {
            (*pFuncionOrdenamiento)(this->data(), this->size());
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
