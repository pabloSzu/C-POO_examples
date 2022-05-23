#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QCameraInfo>
#include <QCamera>
#include <QTimer>
#include <QPainter>
#include "capturador.h"
#include "frame.h"

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = 0);
    ~Ventana();

private:
    Ui::Ventana *ui;
    QCamera *camera;
    Capturador *capturador;
    QTimer *timer;

    QList<QCameraInfo> camerasList;
    QImage im;

    Frame *widget;

private slots:
    void slot_iniciarCamara();
    void slot_timeout();
};

#endif // VENTANA_H
