#include "ventana.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ventana w;

    w.resize(400, 300);
    w.dimensionarWidgetBoton();
    w.dimensionarWidgetBotonDeslizante();

    w.show();

    return a.exec();
}
