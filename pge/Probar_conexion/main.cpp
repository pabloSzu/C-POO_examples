#include <QApplication>
#include "ventana.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Medidor::getInstancia()->f_go();

    Ventana v;
    v.show();

    return a.exec();
}
