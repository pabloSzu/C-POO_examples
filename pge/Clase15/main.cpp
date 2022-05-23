#include "wsocial.h"
#include "boton.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WSocial::getInstancia()->iniciar();

    return a.exec();
}
