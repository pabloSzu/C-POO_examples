#include "lineadetexto.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LineaDeTexto w;
    w.show();

    return a.exec();
}
