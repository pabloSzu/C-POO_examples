#ifndef CLIENTE_H
#define CLIENTE_H

#include <QString>

class Cliente {
public:
    Cliente(QString nombre = "", QString apellido = "", QString empresa = "") : nombre(nombre),
                                                                                apellido(apellido),
                                                                                empresa(empresa) {}

    QString getNombre() const {return nombre;}
    void setNombre(const QString &nombre) {this->nombre = nombre;}

    QString getApellido() const {return apellido;}
    void setApellido(const QString &apellido) {this->apellido = apellido;}

    QString getEmpresa() const {return empresa;}
    void setEmpresa(const QString &empresa) {this->nombre = empresa;}

private:
    QString nombre;
    QString apellido;
    QString empresa;

};

#endif // CLIENTE_H
