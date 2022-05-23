#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana) {

    ui->setupUi(this);
    capturador = new Capturador(this);

    widget = ui->frame;

    camerasList = QCameraInfo::availableCameras();
    for (int i=0; i<camerasList.size(); i++)
        ui->cbSeleccionarCamara->addItem(camerasList.at(i).description());

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_timeout()));

    timer->start(10);

    connect(ui->pbIniciarCamara, SIGNAL(clicked()), this, SLOT(slot_iniciarCamara()));
}

Ventana::~Ventana() {
    delete ui;
}

void Ventana::slot_iniciarCamara() {
    QCameraInfo cameraInfo = camerasList.at( ui->cbSeleccionarCamara->currentIndex() );

    camera = new QCamera( cameraInfo, this );

    camera->setViewfinder( capturador );
    camera->start();
}

void Ventana::slot_timeout() {
    QVideoFrame videoFrame = capturador->getFrameActual();

    QImage::Format imageFormat = QVideoFrame::imageFormatFromPixelFormat(videoFrame.pixelFormat());

    QImage img( videoFrame.bits(),
                videoFrame.width(),
                videoFrame.height(),
                videoFrame.bytesPerLine(),
                imageFormat );

    im = img.scaled(this->width(), this->height());

    widget->setFrame(im);
}
