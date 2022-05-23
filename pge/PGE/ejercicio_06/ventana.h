#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QImage>
#include <QDesktopWidget>

class QTimer;

class Ventana : public QWidget {
    Q_OBJECT

private:
    QTimer *timer;
    QImage im; //este objeto ya está creado y por eso no se crea en el cpp
    int rotacion, transX, transY, posX, posY;
    QDesktopWidget *desktop;
    QRect pantalla;

public:
    Ventana(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *obj, QEvent *e);

private slots:
    void slot_timeout();
};

#endif // VENTANA_H
