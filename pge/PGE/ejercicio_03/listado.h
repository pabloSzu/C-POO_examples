#ifndef LISTADO_H
#define LISTADO_H

#include <QDebug>

template <class T> class Listado {
private:
    int cantidad;
    int libre;
    T *v;

public:
    Listado(int cantidad = 10);
    T get(int i);
    int size();
    bool add(T elemento);
    void clear();
    bool insert(int i, T elemento);
    void borrar(int i);
    void erase(int x, bool front_or_back);
    void operator++(int);
};

template <class T> Listado<T>::Listado(int cantidad) : cantidad(cantidad), libre(0), v(new T[cantidad]) {

}

template <class T> T Listado<T>::get(int i) {
        return v[i];
}

template <class T> int Listado<T>::size() {
    return libre;
}

template <class T> bool Listado<T>::add(T elemento) {
    if (libre < cantidad) {
        v[libre] = elemento;
        libre++;
        return true;
    }
    return false;
}

template <class T> void Listado<T>::clear() {
    if (libre == 0)
        return;
    else
        libre = 0;
}

template <class T> bool Listado<T>::insert(int i, T elemento) {
    if (i <= libre) {

        for(int j = libre; j >= i; j--) {
            v[j] = v[j-1];

        }

        v[i] = elemento;
        libre++;
        return true;
    }
    return false;
}

template <class T> void Listado<T>::borrar(int i) {
    if(i < libre) {
        for(int j = i; j < libre; j++) {
            v[j] = v[j+1];
        }
        libre--;
    }
}

template <class T> void Listado<T>::erase(int x, bool front_or_back) {
    if (x < libre) {
        if (front_or_back == true) {
            for(int j = x, k = 0; j < libre; j++, k++) {
                v[k] = v[j];
            }
            libre = libre - x;
        }
        else {
            libre = libre - x;
        }
    }
}

template <class T> void Listado<T>::operator++(int) {
    this->cantidad = cantidad*2;
    int tope = this->size();

    for(int contador = 0; contador < tope; contador++) {
        this->add(this->get(contador));
    }
}

#endif // LISTADO_H
