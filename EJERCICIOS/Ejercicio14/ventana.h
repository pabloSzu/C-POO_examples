#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPainter>
#include <QRectF>
#include <QBoxLayout>

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = 0);
    ~Ventana();

    void dimensionarWidgetBoton();
    void dimensionarWidgetBotonDeslizante();
    void paintEvent(QPaintEvent *);

private:
    Ui::Ventana *ui;
     QBoxLayout *layout;
     QPushButton *boton1, *boton2;

private slots:
    void slot_Mensaje();
    void slot_Opciones();
    void slot_Opcion1();
    void slot_Opcion2();
};

#endif // VENTANA_H
