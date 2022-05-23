#ifndef LISTADOENTEROS_H
#define LISTADOENTEROS_H

#include <QVector>

class ListadoEnteros : public QVector<int> {
public:
    void ordenar(void (*pFuncionOrdenamiento)(int *v, int))  {
            (*pFuncionOrdenamiento)(this->data(), this->size());
    }
};

#endif // LISTADOENTEROS_H
