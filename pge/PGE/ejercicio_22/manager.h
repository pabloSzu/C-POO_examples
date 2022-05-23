#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "principal.h"
#include "login.h"
#include "ventana.h"


class Manager : public QObject {
    Q_OBJECT

public:
    Manager( QObject * parent = 0 );
    void iniciar();

private:
    Principal *principal;
    Login *login;
    Ventana *ventana;

private slots:
     void slot_usuarioValido( bool isValido, QStringList user );

};


#endif // MANAGER_H
