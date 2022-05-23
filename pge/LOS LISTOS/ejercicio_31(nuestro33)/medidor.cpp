#include "medidor.h"

Medidor *Medidor::instancia = NULL;

Medidor::Medidor(QObject *parent) : QThread(parent), manager(new QNetworkAccessManager(this)),
    timer(new QTimer(this)), repeticion(new QTimer(this)),
    fin(false), ok(false) {

    repeticion->start(30000);
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_timeout()));
    connect(repeticion, SIGNAL(timeout()), this, SLOT(slot_repetir()));
}

Medidor::~Medidor() {
    if(instancia !=NULL) {
        delete instancia;
    }
}

Medidor * Medidor::getInstancia() {
    if(instancia == NULL) {
        instancia = new Medidor();
    }

    return instancia;
}

void Medidor::slot_timeout() {
    qDebug()<< "Timeout";
    fin = true;
}

void Medidor::slot_repetir() {
    qDebug() << "Repeticion";
    hayConexion();
}

bool Medidor::isOk() {
   if(ok == false) {
       return false;
   }
   else {
       return true;
   }
}

void Medidor::hayConexion() {
    timer->start(4000);

    QUrl url("http://autogestion.metrotel.com.ar/speedtest/archivo10MB.zip");
    QNetworkRequest req(url);
    QNetworkReply *reply = manager->get(req);
    QEventLoop loop;

    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));

    loop.exec();

    if(fin == false) {
        timer->stop();

        if(reply->bytesAvailable()) {
            ok = true;
        }
        else {
            ok = false;
        }
    }
    else {
        timer->stop();
        fin = false;
        ok = false;
    }
}

void Medidor::iniciar() {
    qDebug() << "Empieza a ejecutarse el hilo";
    hayConexion();
}



