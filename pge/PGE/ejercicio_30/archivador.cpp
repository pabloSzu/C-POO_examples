#include "archivador.h"

QFile * Archivador::file = new QFile("./defecto.txt");

bool Archivador::abrir(QString ruta) {
    file->setFileName(ruta);
    if(!file->exists()) {
        return false;
    }

    return file->open(QIODevice::Append | QIODevice::Text);
}

bool Archivador::almacenar(QString texto) {
    if(!file->isOpen()) {
        return false;
    }

    QTextStream salida(file);
    salida << texto;

    return true;
}
