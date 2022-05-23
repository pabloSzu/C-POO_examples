#include "widget.h"
#include "ui_widget.h"
#include<QMouseEvent>
#include <qpainter.h>
#include <QPaintEvent>
#include <QDebug>
#include<QFileDialog>
#include<QDebug>
#include<QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->x_valor->setValue(cursor().pos().x());
    ui->y_valor->setValue(cursor().pos().y());
    ui->x_valor->setMinimum( -INT_MAX);
    ui->x_valor->setMaximum(+INT_MAX);
    ui->y_valor->setMinimum( -INT_MAX);
    ui->y_valor->setMaximum(+INT_MAX);
    ui->pushButton->hide();
    connect(ui->pushButton_2, SIGNAL(pressed()), this, SLOT(slotGuardar()));

}


int x[5];
int y[5];


Widget::~Widget()
{
    delete ui;
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);

    if(  (event->x()-60) > 0  and (event->x()-60) < 500 ){
                ui->x_valor->setValue(event->x()-60);
                ui->x_cartel->setText("");}
    else {ui->x_cartel->setText("Valor de X fuera de rango");}

    if(  ((event->y()-400)*(-1)) > 0  and ((event->y()-400)*(-1)) < 270 ){
                ui->y_valor->setValue((event->y()-400)*(-1));
                ui->y_cartel->setText("");}
     else {ui->y_cartel->setText("Valor de Y fuera de rango");}




    if(  (event->x()-60) > 0  and (event->x()-60) < 500 and ((event->y()-400)*(-1)) > 0  and ((event->y()-400)*(-1)) < 270){

        ui->pushButton->show();
        connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(slotAdd(
                                                                  x.add((event->x()-60));
                                                                  y.add(((event->y()-400)*(-1)));
                                                                  )
                                                              ));

    };

}

void Widget::slotGuardar()
{
    QFile arch;
    QTextStream io;
    QString nombreArch;
    nombreArch = QFileDialog::getSaveFileName(this,"Guardar");
    if(nombreArch.isEmpty())
        return;

    arch.setFileName(nombreArch);
    arch.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!arch.isOpen()){
        QMessageBox::critical(this,"Error", arch.errorString());
        return;
    }

    io.setDevice(&arch);
    io << "valor_en_x";   //deberia ir el vector x
    io << "valor_en_y";   //deberia ir el vector y
    arch.flush();
    arch.close();
}


//void Widget::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);
//    painter.drawLine(ui->x_valor->value(),ui->y_valor->value(),5,5);
//}
