#include "manager.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Manager *m = Manager::getInstancia();

    m->iniciar();

    return a.exec();
}
