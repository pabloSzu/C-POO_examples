#ifndef LOGGER_H
#define LOGGER_H

#include <QFile>
#include <QTextStream>

class Logger  {
private:
    static QFile *file;

public:
    static bool registrar(QString texto, QString archivo = "../../../../logs/registros.txt");
};

#endif // LOGGER_H
