#ifndef EXCEPCION_H
#define EXCEPCION_H

#include <QString>

class ExcRango  {
private:
    QString mensaje;
public:
    ExcRango(QString mensaje, int i) : mensaje(mensaje + QString::number(i))  {   }
    QString getMensaje()  {  return mensaje;  }
};

#endif // EXCEPCION_H
