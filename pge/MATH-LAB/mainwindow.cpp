#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->widget, SIGNAL(click), ui->x_valor, SLOT(click_lugar()));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow :: MousePressEvent(QMouseEvent * event){
 //   QWidget::mousePressEvent(event);
    ui->x_valor->setNum(event->x());
    ui->y_valor->setNum(event->y());
}

void MainWindow :: click_lugar(){
    QPoint punto = QCursor::pos();

    ui->x_valor->setNum(punto.x());
    ui->x_valor->setText("Hola");
}
