#include "logger.h"

QFile * Logger::file = new QFile;

bool Logger::registrar(QString texto, QString archivo) {
    file->setFileName(archivo);
    return !file->open(QIODevice::Append | QIODevice::Text);

    QTextStream salida(file);
    salida << texto;

    return true;
}
