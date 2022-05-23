#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMouseEvent>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseDoubleCLickEvent(QMouseEvent *event){
     ui->spinBox->setValue(event->x());
     QWidget::mouseDoubleClickEvent(event);

}
