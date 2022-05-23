#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "boton.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Boton b;
    b.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
