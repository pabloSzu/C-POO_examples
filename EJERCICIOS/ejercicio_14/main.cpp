#include "ventana.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ventana w;

    w.resize(200, 400);
    w.dimensionarWidget();
    w.show();

    return a.exec();
}
