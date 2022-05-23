#include "medidor.h"

Medidor *Medidor::instancia = NULL;

Medidor::Medidor(QObject *parent) : QThread(parent), manager(new QNetworkAccessManager(this)),
    timer(new QTimer(this)), repeticion(new QTimer(this)),
    fin(false), ok(false) {


    repeticion->start(40000);
    connect(timer, SIGNAL(timeout()), this, SLOT(SLOT_TIME_OUT()));
    connect(repeticion, SIGNAL(timeout()), this, SLOT(SLOT_REPETIR()));
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

void Medidor::SLOT_TIME_OUT() {
    qDebug()<< "time out";
    fin = true;
}

void Medidor::SLOT_REPETIR() {
    qDebug() << "repeticion";
    conexion_existe();
}

bool Medidor::isOk() {
   if(ok == false) {
       return false;
   }
   else {
       return true;
   }
}

void Medidor::conexion_existe() {
    timer->start(4000);
// ayuda de juan para probar
    //obtener link de desacrga directa
//========================================================================================
    QUrl url("https://drive.google.com/uc?id=1GjRyEe0sDbDgXo7Dk_ArEGFyYq3JF-3v&export=download");
    QNetworkRequest req(url);
    QNetworkReply *reply = manager->get(req);
    QEventLoop loop;

    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));

    loop.exec();
//========================================================================================
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

void Medidor::f_go() {
    qDebug() << "Empieza a ejecutarse el hilo";
    conexion_existe();
}



