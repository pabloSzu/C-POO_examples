#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QCameraInfo>
#include <QCamera>
#include <QTimer>
#include <QPainter>
#include "capturador.h"

namespace Ui {
class Principal;
}

class Principal : public QWidget
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);
    ~Principal();

private:
    Ui::Principal *ui;
    QCamera *camera;
    Capturador * capturador;
    QTimer * timer;

    QList<QCameraInfo> camerasList;
    QImage im;


protected:
    void paintEvent( QPaintEvent * );

private slots:
    void slot_iniciarCamara();
    void slot_timeout();
};

#endif // PRINCIPAL_H
