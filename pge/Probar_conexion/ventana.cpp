#include "ventana.h"
#include "ui_ventana.h"
#include <QNetworkRequest>
#include <QMessageBox>

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana), manager(new QNetworkAccessManager(this)) {

    ui->setupUi(this);

    connect(ui->pbConexion, SIGNAL(pressed()), this, SLOT(SLOT_CONEXION_OK()));

    this->setWindowTitle("Bienvenido!");

}

Ventana::~Ventana() {
    delete ui;
}
/*
void Ventana::SLOT_CONEXION_OK() {
if(Medidor::getInstancia()->isOk()) {

Buscar para obtener url --- no funciona 

*/



void Ventana::SLOT_CONEXION_OK() {
if(Medidor::getInstancia()->isOk()) {
manager->get(QNetworkRequest(QUrl("http://mi.ubp.edu.ar")));
qDebug() << "Conexion estable";
    }
else {
        QMessageBox::critical(this,"Internet","Conexión muy lenta");
    }
}
