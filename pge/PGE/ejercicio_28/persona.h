#ifndef PERSONA_H
#define PERSONA_H

#include <QString>

class Persona  {
public:
    Persona() : dni( 0 )  {  }
    virtual ~Persona()  {  }

private:
    int dni;
};

class Cliente : public Persona  {
public:
    Cliente() : cuenta( 0 ), tipo( "Corriente" )  {  }

private:
    int cuenta;
    QString tipo;
};

class Empleado : public Persona  {
public:
    Empleado() : sueldo( 0 )  {  }

private:
    int sueldo;
};

#endif // PERSONA_H
