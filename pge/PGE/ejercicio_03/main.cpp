#include "listado.h"
#include <QDebug>

int main ( ) {
    Listado<int> lista1;

    lista1.add(8);
    lista1.add(20);
    lista1.add(9);
    lista1.add(3);

    lista1++;

    for(int i = 0; i < lista1.size(); i++) {
        qDebug() << lista1.get(i);
    }
}
