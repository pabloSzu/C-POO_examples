#ifndef LISTADO_H
#define LISTADO_H

#include "excepcion.h"

template <class T> class Listado {
private:
    int cantidad;
    int libre;
    T *v;

public:
    Listado(int n = 10) : cantidad(n), libre(0), v(new T[n])  {  }
    bool add(T nuevo);

    T get(int i)  {
        if (i >= libre)
            throw ExcRango("Listado fuera de rango. Indice al que se trata de acceder: ", i);
        return v[i];
    }

    int length()  {  return libre;  }
};

template <class T> bool Listado<T>::add(T nuevo)  {
    if (libre < cantidad)  {
        v[libre] = nuevo;
        libre++;
        return true;
    }
    return false;
}

#endif // LISTADO_H
