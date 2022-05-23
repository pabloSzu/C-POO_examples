#include "ventana.h"
#include "ui_ventana.h"
#include <QPushButton>


Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
    ui->pb_aceptar->configurarAspectoAc("Aceptar", 0xFFFFFF00, 0xFFFF0000);
    ui->pb_opciones->configurarAspectoOp("Opciones", 0xFFFF0000, 0xFFFFFF00);

    connect(ui->pb_aceptar, SIGNAL(signal_click()), this, SLOT(slot_Mensaje()));
    connect(ui->pb_opciones, SIGNAL(signal_click()), this, SLOT(slot_Opciones()));
}

Ventana::~Ventana() {
    delete ui;
}

void Ventana::dimensionarWidgetBoton() {
    int borde = this->height()/30;
    int posBotonAceptarX = borde;
    int posBotonAceptarY = this->height()/20 * 15;
    int botonAceptarW = this->width()/3 - 2 * borde;
    int botonAceptarH = this->height()/9;

    ui->pb_aceptar->resize(botonAceptarW, botonAceptarH);
    ui->pb_aceptar->move(posBotonAceptarX, posBotonAceptarY);
}

void Ventana::dimensionarWidgetBotonDeslizante() {
    int borde = this->height()/30;
    int posBotonOpcionesX = borde;
    int posBotonOpcionesY = this->height()/50;
    int botonOpcionesW = this->width() / 3 - 2*borde;
    int botonOpcionesH = this->height()/9;

    ui->pb_opciones->resize(botonOpcionesW, botonOpcionesH);
    ui->pb_opciones->move(posBotonOpcionesX, posBotonOpcionesY);
}

void Ventana::slot_Mensaje() {
    QMessageBox::critical(this, "ERROR", "EXIT");
}

void Ventana::slot_Opciones() {

       boton1 = new QPushButton(this);
       boton1->resize(0, 0);
       boton1->setText("Ocultar");
       boton1->show();
       boton2 = new QPushButton(this);
       boton2->resize(0, 0);
       boton2->setText("Mostar");
       boton2->show();


       int borde = this->height()/30;
       int posBotonOpcionesX = borde;
       int posBotonOpcionesY = this->height()/50;
       int botonOpcionesH = this->height()/9;

       QEventLoop loop;
       for(int i = 0; i < 100; i++){
           QTimer::singleShot(50, &loop, SLOT(quit()));
           loop.exec();
           boton1->resize(i, botonOpcionesH/1.5);
           boton1->move(posBotonOpcionesX+110, posBotonOpcionesY);
           boton2->resize(i, botonOpcionesH/1.5);
           boton2->move(posBotonOpcionesX+110, posBotonOpcionesY+20);
           this->repaint();
        }
    connect(boton1, SIGNAL(pressed()), this, SLOT(slot_Opcion1()));
    connect(boton2, SIGNAL(pressed()), this, SLOT(slot_Opcion2()));
}

void Ventana::slot_Opcion1() {

   ui->pb_opciones->hide();
   ui->pb_aceptar->hide();
}

void Ventana::slot_Opcion2() {

    ui->pb_opciones->show();
    ui->pb_aceptar->show();
}


void Ventana::paintEvent(QPaintEvent *) {
    QPainter painter(this);


}

