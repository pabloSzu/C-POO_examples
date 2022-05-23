#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


private slots:
void slot_abrir_archivo();
void slot_nuevo();
void slot_copiar();
void slot_cortar();
void slot_pegar();
void slot_seleccionar();
void slot_acerca_de();
void slot_guardar_como();


};

#endif // MAINWINDOW_H
