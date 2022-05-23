#include "principal.h"
#include "ui_principal.h"
#include <QDir>
#include <QTimer>
#include <QDate>
#include <QTime>
#include <QDebug>

Principal::Principal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Principal), timer(new QTimer(this)), timer2(new QTimer(this)), camera(new QCamera(this))
{
   ui->setupUi(this);

   ui->hsGuardar->setMinimum(1);
   ui->hsGuardar->setMaximum(10);

   ui->lSlider->setText(QString::number(ui->hsGuardar->value()*500));

   timer->setInterval(ui->hsGuardar->value()*500);
   timer2->setInterval(1500);

   camerasList = QCameraInfo::availableCameras();
   for (int i = 0; i < camerasList.size(); i++)
       ui->cbSeleccionarCamara->addItem(camerasList.at(i).description());

   connect(ui->pbIniciarCamara, SIGNAL(clicked()), this, SLOT(slot_iniciarCamara()));

   connect(ui->hsGuardar, SIGNAL(valueChanged(int)), this, SLOT(slot_setIntervalo(int)));

   connect(timer, SIGNAL(timeout()), this, SLOT(slot_guardarImagen()));

   connect(timer2, SIGNAL(timeout()), this, SLOT(slot_timeOut()));

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

    timer2->start();
}

void Principal::slot_setIntervalo(int value) {
    timer->setInterval(value*500);
    qDebug() << timer->interval();
    ui->lSlider->setText(QString::number(ui->hsGuardar->value()*500));
}

void Principal::slot_timeOut() {
    timer2->stop();

    if(camera->status() == QCamera::ActiveStatus) {
        timer->start();
    }
}

void Principal::slot_guardarImagen() {
    QPixmap pixMap = ui->visor->grab();
    im = pixMap.toImage();

    QDate fecha = QDate::currentDate();
    QTime hora = QTime::currentTime();

    QString nombre = QString::number(fecha.day()) + "-" + QString::number(fecha.month())
            + "-" + QString::number(fecha.year()) + " " + QString::number(hora.hour()) +
            "h-" + QString::number(hora.minute()) + "m-" + QString::number(hora.second()) + "s";

    im.save("../../../../ejercicio_15/imagenes/" + nombre + ".png");
}
