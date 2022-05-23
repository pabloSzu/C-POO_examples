#ifndef TRANSFORMACIONMATRIZ_H
#define TRANSFORMACIONMATRIZ_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class RotacionMatriz; }
QT_END_NAMESPACE

class RotacionMatriz : public QWidget
{
    Q_OBJECT

public:
    RotacionMatriz(QWidget *parent = nullptr);
    ~RotacionMatriz();

private:
    Ui::RotacionMatriz *ui;

private slots:
    void slot_calcularMatrices();
    void slot_limpiar();
    void slot_Transformar();
    void on_pbCalcula_clicked();
    void on_pbTransformar_clicked();
    void on_pbLimpia_clicked();
};
#endif // TRANSFORMACIONMATRIZ_H
