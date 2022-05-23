#include <QApplication>
#include "principal.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Principal p;
    p.showMaximized();

    return a.exec();
}

