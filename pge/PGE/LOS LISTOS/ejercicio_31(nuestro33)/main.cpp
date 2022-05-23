#include <QApplication>
#include "ventana.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Medidor::getInstancia()->iniciar();

    Ventana v;
    v.show();

    return a.exec();
}
