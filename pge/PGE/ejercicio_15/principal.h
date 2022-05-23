#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QCameraInfo>
#include <QCamera>
#include <QImage>

namespace Ui {
class Principal;
}

class QTimer;

class Principal : public QWidget {
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);
    ~Principal();

private:
    Ui::Principal *ui;
    QTimer *timer, *timer2;
    QCamera *camera;
    QList<QCameraInfo> camerasList;
    QImage im;

private slots:
    void slot_iniciarCamara();
    void slot_guardarImagen();
    void slot_setIntervalo(int value);
    void slot_timeOut();
};

#endif // PRINCIPAL_H
