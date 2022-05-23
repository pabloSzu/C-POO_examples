#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QDebug>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionAbrir, SIGNAL(triggered(bool)), this, SLOT(slot_abrir_archivo()) );

    connect(ui->actionNuevo, SIGNAL(triggered(bool)), this, SLOT(slot_nuevo()) );

    connect(ui->actionCopiar, SIGNAL(triggered(bool)), this, SLOT(slot_copiar()) );

    connect(ui->actionPegar, SIGNAL(triggered(bool)), this, SLOT(slot_pegar()) );

    connect(ui->actionCortar, SIGNAL(triggered(bool)), this, SLOT(slot_cortar()) );

    connect(ui->actionSeleccionar_todo, SIGNAL(triggered(bool)), this, SLOT(slot_seleccionar()) );

    connect(ui->actionAcerca_de, SIGNAL(triggered(bool)), this, SLOT(slot_acerca_de()) );

    connect(ui->actionGuardar_como, SIGNAL(triggered(bool)), this, SLOT(slot_guardar_como()) );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_abrir_archivo()
{
  /* QString archivoElegido =  QFileDialog::getOpenFileName( this, "Abrir archivos", "../");

   qDebug() << archivoElegido;*/

    QFile arch;
    QTextStream io;
    QString nombreArch;
    nombreArch = QFileDialog::getOpenFileName(this,"Abrir");
    if(nombreArch.isEmpty()) return;
    arch.setFileName(nombreArch);
    arch.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!arch.isOpen()){
        QMessageBox::critical(this,"Error", arch.errorString());
        return;
    }
    io.setDevice(&arch);
    ui->plainTextEdit->setPlainText(io.readAll());
    arch.flush();
    arch.close();
}

void MainWindow::slot_nuevo()
{
    ui->plainTextEdit->clear();
}

void MainWindow::slot_copiar()
{
    ui->plainTextEdit->copy();
}
void MainWindow::slot_pegar()
{
    ui->plainTextEdit->paste();
}
void MainWindow::slot_cortar()
{
    ui->plainTextEdit->cut();
}
void MainWindow::slot_seleccionar()
{
    ui->plainTextEdit->selectAll();
}
void MainWindow::slot_acerca_de()
{
     QMessageBox::about(this,"Notepad", "Hola! Bienvenido a mi editor de texto :)");
}
void MainWindow::slot_guardar_como()
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
    io << ui->plainTextEdit->toPlainText();
    arch.flush();
    arch.close();
}
