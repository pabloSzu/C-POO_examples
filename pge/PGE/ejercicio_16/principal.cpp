#include "principal.h"
#include "ui_principal.h"
#include <QDir>
#include <QDebug>
#include <QTimer>
#include <QDateTime>

Principal::Principal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Principal), timer(new QTimer(this)), timerfotos(new QTimer(this)), camera(new QCamera(this))
{
   ui->setupUi(this);

   galeria.show();
   galeria.move(0, 0);

   ui->hsGuardar->setMinimum(500);
   ui->hsGuardar->setMaximum(5000);

   camerasList = QCameraInfo::availableCameras();
   for (int i=0 ; i<camerasList.size() ; i++)
       ui->cbSeleccionarCamara->addItem(camerasList.at(i).description());

   connect(ui->pbIniciarCamara, SIGNAL(clicked()), this, SLOT(slot_iniciarCamara()));

   connect(timer, SIGNAL(timeout()), this, SLOT(slot_guardarImagen()));

   connect(timerfotos, SIGNAL(timeout()), this, SLOT(Galeria::slot_mostrarImagen()));

}

Principal::~Principal() {
    delete ui;
}

void Principal::slot_iniciarCamara() {
    QCameraInfo cameraInfo = camerasList.at(ui->cbSeleccionarCamara->currentIndex());

    delete camera;
    camera = new QCamera(cameraInfo, this);

    camera->setViewfinder(ui->visor);
    camera->start();
    timer->start(ui->hsGuardar->value());

}

void Principal::slot_guardarImagen() {
    QPixmap pixMap = ui->visor->grab();
    im = pixMap.toImage();

    QString nombre = QDateTime::currentDateTime().toString();
    im.save("../../../../ejercicio_15/imagenes/" + nombre + ".png");
}
