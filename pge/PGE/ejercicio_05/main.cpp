#include "formulario.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    formulario w;
    w.show();

    return a.exec();
}
