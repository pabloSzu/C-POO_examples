#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget) {

    ui->setupUi(this);

    bool open = Archivador::abrir("../../../../ejercicio_30/archivo.txt");
    if(!open) {
        qDebug() << "No se pudo abrir el archivo...";
    }

    //Codigo que escribe palabras en el archivo y la ventana no se muestra hasta que termina
//   QString pal("pepepeeppe");
//    for(int i = 0; i < 100; ++i)
//    {
//        ui->listWidget->addItem(pal);
//        pal.append("ja");
//        Archivador::almacenar(pal + "\n");
//    }

    mh = new MiHilo(this);
    mh->start(QThread::HighestPriority);

    connect(mh, &MiHilo::EscribirPalabra, [&] (QString pal)
    {
        ui->listWidget->addItem(pal);
        Archivador::almacenar(pal + "\n");
    });
}

Widget::~Widget() {
    delete ui;
}
