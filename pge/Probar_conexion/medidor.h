#ifndef MEDIDOR_H
#define MEDIDOR_H

#include <QThread>
#include <QObject>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDebug>
#include <QEventLoop>
#include <QTimer>

class Medidor: public QThread {
    Q_OBJECT

private:
    static Medidor *instancia;
    QNetworkAccessManager *manager;
    QTimer *timer, *repeticion;
    bool fin, ok;

public:
    Medidor(QObject* parent = 0);
    ~Medidor();
    static Medidor *getInstancia();
    bool isOk();
    void conexion_existe();


    void f_go();

private slots:
    void SLOT_TIME_OUT();
    void SLOT_REPETIR();

};

#endif // MEDIDOR_H
