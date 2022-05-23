#include "ventana.h"
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>
#include <QApplication>

Ventana::Ventana(QWidget *parent) : QWidget(parent), timer(new QTimer(this)),
    rotacion(0), transX(0), transY(0) {
    this->installEventFilter(this);
    im.load("../../../../ejercicio_06/im.jpg");



    connect(timer, SIGNAL(timeout()), this, SLOT(slot_timeout()));
    timer->start(50);
}

void Ventana::slot_timeout() {
    this->repaint();
}

void Ventana::paintEvent(QPaintEvent *) {
    QPainter pincel(this);
    pincel.translate(this->width()/2 + transX, this->height()/2 + transY);
    pincel.rotate(10 * ++rotacion);

    pincel.drawImage(-im.width()/2, -im.height()/2, im);

    if (rotacion>=360)
        rotacion = 0;
}

bool Ventana::eventFilter(QObject *obj, QEvent *e) {
    if (obj == this) {
        if(e->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(e);
            int key = keyEvent->key();

            switch (key) {
            case Qt::Key_Up:
                transY -= 10;
                break;
            case Qt::Key_Down:
                transY += 10;
                break;
            case Qt::Key_Left:
                transX -= 10;
                break;
            case Qt::Key_Right:
                transX += 10;
                break;
            default:
                break;
            }
            return true;
        }

        if(e->type() == QEvent::Move) {
            desktop = QApplication::desktop();
            pantalla = desktop->screenGeometry();

            posX = (pantalla.width()/2) - (this->width()/2);
            posY = (pantalla.height()/2) - (this->height()/2);
            this->move(QPoint(posX, posY));
        }
    }
    return QWidget::eventFilter(obj, e);
}
