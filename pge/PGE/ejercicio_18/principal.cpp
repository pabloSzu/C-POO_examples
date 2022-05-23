#include "principal.h"
#include "ui_principal.h"

#include <QPainter>

Principal::Principal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Principal), camera(new QCamera(this))
{
    ui->setupUi(this);

    capturador = new Capturador( this );

    camerasList = QCameraInfo::availableCameras();
    for (int i=0 ; i<camerasList.size() ; i++)
        ui->cbSeleccionarCamara->addItem( camerasList.at(i).description() );

    timer = new QTimer(this);
    connect ( timer, SIGNAL( timeout() ), this, SLOT( slot_timeout() ) );

    timer->start( 10 );


    connect( ui->pbIniciarCamara, SIGNAL( clicked() ), this, SLOT( slot_iniciarCamara() ) );
}

Principal::~Principal() {
    delete ui;
}

void Principal::paintEvent(QPaintEvent *) {
    QPainter painter( this );
    painter.drawImage( 0, 0, im );
}

void Principal::slot_iniciarCamara() {
    QCameraInfo cameraInfo = camerasList.at( ui->cbSeleccionarCamara->currentIndex() );

    camera = new QCamera( cameraInfo, this );

    camera->setViewfinder( capturador );
    camera->start();
}

void Principal::slot_timeout() {
    QVideoFrame videoFrame = capturador->getFrameActual();

    QImage::Format imageFormat = QVideoFrame::imageFormatFromPixelFormat( videoFrame.pixelFormat() );

    QImage img( videoFrame.bits(),
                videoFrame.width(),
                videoFrame.height(),
                videoFrame.bytesPerLine(),
                imageFormat );

    im = img.scaled( this->width(), this->height() );

    for (int x = 0; x < im.width(); x++)  {
        for (int y = 0; y < im.height(); y++)  {
            QRgb rgb = im.pixel(x, y);  // typedef unsigned int QRgb;
            int r = qRed(rgb)/3 + qGreen(rgb)/3 + qBlue(rgb)/3;
            QRgb nuevoRgb = qRgb(r, r, r);
            im.setPixel(x, y, nuevoRgb);
        }
    }

    this->repaint();
}

