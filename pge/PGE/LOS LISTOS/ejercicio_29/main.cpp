#include "listado.h"
#include <QDebug>

int main( ) {
    try{
        Listado<int> list;
        list.add(3);
        list.add(4);
        qDebug() << list.get(7);
    }
    catch(ExcRango e) {
        qDebug () << e.getMensaje();
    }

    return 0;
}
