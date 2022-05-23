#include <QDebug>
#include "listadogenerico.h"

template<class T> void burbuja(T * v, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (v[j] > v[j+1]) {
                T aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

template<class T> void insercion(T * v, int n) {
    for (int j = 1; j < n; j++) {
        int y = v[j];
        int k;
        for(k = j-1; k >= 0 && y < v[k]; k--) {
            v[k+1] = v[k];
        }
        v[k+1] = y;
    }
}

template<class T> void seleccion(T * v, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(v[i] > v[j]) {
                T aux = v[j];
                v[j] = v[i];
                v[i] = aux;
            }
        }
    }
}

int main ( ) {
    ListadoGenerico<int> l;
    void (*pFuncionOrdenamiento)(int * v, int n);

    pFuncionOrdenamiento = &burbuja;

    l.push_back(8);
    l.push_back(10);
    l.push_back(3);
    l.push_back(5);
    l.push_back(1);

    l.ordenar(pFuncionOrdenamiento);

    for(int i = 0; i < l.size(); i++) {
        qDebug() << l.at(i);
    }

    ListadoGenerico<Persona> personas;
    void (*pFuncion)(Persona *v, int n);

    pFuncion = &burbuja;

    personas.push_back(10);
    personas.push_back(4);
    personas.push_back(30);
    personas.push_back(2);

    personas.ordenar(pFuncion);

    for(int i = 0; i < personas.size(); i++) {
        qDebug() << personas.at(i).getEdad();
    }

    return 0;
}
