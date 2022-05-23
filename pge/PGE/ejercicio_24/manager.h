#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>


class Manager : public QObject {
    Q_OBJECT

public:
    Manager( QObject * parent = 0 );
    static Manager *getInstancia();
    void iniciar();

private:
    static Manager *instancia;

private slots:
     void slot_usuarioValido( bool isValido, QStringList user );
     void slot_cierreApp();

};


#endif // MANAGER_H
