#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <QWidget>
#include <QVector>

template <class T> class Inventario : public QVector<T> {
    Q_OBJECT
private:
    QVector<T> vector;
    int max;
    int libre;
public:
    Inventario(int);
    void add(T elemento);
    int get(int posicion) {return vector[posicion];}
    int cantidad() {return libre;}
    void operator-(int n){
            if(this->count() <= n) this->remove(0, this->count());
            else for(int i = 0; i < n; i++){
                this->removeLast();
            }
        };
};


template <class T> Inventario <T>::Inventario(int) {
    this->libre = 0;
    this->max = max;
}

template <class T> void Inventario<T>::add(T elemento) {
    libre++;
    for (int i=0; i<libre; i++) {
        T aux = vector[i];
        vector[i] = elemento;
        vector[i+1] = aux;
    }
}



#endif // INVENTARIO_H
