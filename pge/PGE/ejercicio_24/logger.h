#ifndef LOGGER_H
#define LOGGER_H

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>

class Logger {
public:
    static Logger *getInstancia();
    static bool abrir(QString ruta);
    static bool registrarEvento(QString evento);

private:
    static QFile *file;
    static Logger *instancia;
};

#endif // LOGGER_H
