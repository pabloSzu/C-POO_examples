#include "ventana.h"
#include "ui_ventana.h"
#include <QNetworkRequest>
#include <QMessageBox>

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana), manager(new QNetworkAccessManager(this)) {

    ui->setupUi(this);

    connect(ui->pbConexion, SIGNAL(pressed()), this, SLOT(slot_pruebaConexion()));
}

Ventana::~Ventana() {
    delete ui;
}

void Ventana::slot_pruebaConexion() {
    if(Medidor::getInstancia()->isOk()) {
        manager->get(QNetworkRequest(QUrl("http://mi.ubp.edu.ar")));
        qDebug() << "Conexion estable";
    }
    else {
        QMessageBox::critical(this,"Internet","Conexión muy lenta");
    }
}
