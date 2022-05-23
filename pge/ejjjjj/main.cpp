#include <QApplication>
#include <inventario.h>
#include <QDebug>

int main(int argc, char ** argv) {
    QApplication a(argc, argv);

    Inventario<int> i(5);

    i.add(4);
    i.add(6);
    i.add(2);
    i.add(9);
    i.add(4);
    i.add(1);

    qDebug() << i.cantidad();

    qDebug() << i.get(2);


    qDebug() << i;


    return a.exec();
}
