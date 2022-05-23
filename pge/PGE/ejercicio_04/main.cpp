#include "lineadetexto.cpp"
#include <QApplication>


int main(int argv, char** argc) {
    QApplication a(argv, argc);

    LineaDeTexto le1;
    le1.setText("Hola");

    LineaDeTexto le2;
    le2.setText("che");

    LineaDeTexto l;

    l = le1 + le2;

    l.show();


    return a.exec();

}
