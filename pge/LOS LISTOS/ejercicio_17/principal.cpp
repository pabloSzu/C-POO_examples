#include "principal.h"
#include "ui_principal.h"
#include <QDir>
#include <QDebug>

Principal::Principal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Principal), camera(new QCamera(this))
{
    ui->setupUi(this);

   camerasList = QCameraInfo::availableCameras();
   for (int i=0 ; i<camerasList.size() ; i++)
       ui->cbSeleccionarCamara->addItem(camerasList.at(i).description());

   connect(ui->pbIniciarCamara, SIGNAL(clicked()), this, SLOT(slot_iniciarCamara()));
   connect(ui->pbCapturar, SIGNAL(clicked()), this, SLOT(slot_guardarImagen()));
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
}

void Principal::slot_guardarImagen() {
    QPixmap pixMap = ui->visor->grab();
    im = pixMap.toImage();
    int r, g, b;
    QRgb nuevoRgb;

    for (int x = 0; x < im.width(); x++)  {
        for (int y = 0; y < im.height(); y++)  {
            QRgb rgb = im.pixel(x, y);  // typedef unsigned int QRgb;

            //Guarda la imagen con los colores invertidos
            r = qBlue(rgb);
            g = qGreen(rgb);
            b = qRed(rgb);
            nuevoRgb = qRgb(r, g, b);

            //Guarda la imagen en escala de grises
//            r = qRed(rgb)/3 + qGreen(rgb)/3 + qBlue(rgb)/3;
//            nuevoRgb = qRgb(r, r, r);

            //Guarda la imagen en negativo
//            r = ~qRed(rgb);
//            g = ~qGreen(rgb);
//            b = ~qBlue(rgb);
//            nuevoRgb = qRgb(r, g, b);


            im.setPixel(x, y, nuevoRgb);
        }
    }

    im.save("../../../../ejercicio_17/imagen.png");
}
