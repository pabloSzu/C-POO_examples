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
    void hayConexion();
    void iniciar();

private slots:
    void slot_timeout();
    void slot_repetir();

};

#endif // MEDIDOR_H
