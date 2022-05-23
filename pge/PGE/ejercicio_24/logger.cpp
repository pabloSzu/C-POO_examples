#include "logger.h"

Logger *Logger::instancia = NULL;
QFile * Logger::file = new QFile("../../../../ejercicio_24/defecto.txt");

Logger *Logger::getInstancia() {
    if( instancia == NULL ) {
        instancia = new Logger();
    }
    return instancia;
}

bool Logger::abrir(QString ruta) {
    file->setFileName(ruta);
    if(!file->exists()) {
        return false;
    }

    return file->open(QIODevice::Append | QIODevice::Text);
}

bool Logger::registrarEvento(QString evento) {
    if(!file->isOpen()) {
        return false;
    }

    QString date = QDate::currentDate().toString();
    QString time = QTime::currentTime().toString();

    QString total = evento + "\t" + date + "\t" + time + "\n";

    QTextStream salida(file);
    salida << total;

    return true;
}
