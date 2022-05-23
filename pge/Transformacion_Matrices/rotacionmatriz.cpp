#include "rotacionmatriz.h"
#include "ui_rotacionmatriz.h"
#include "calculadormatrices.h"
#include <QMessageBox>
#include <QDebug>
#include <QtMath>

RotacionMatriz::RotacionMatriz(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RotacionMatriz)
{
    ui->setupUi(this);
}

RotacionMatriz::~RotacionMatriz()
{
    delete ui;
}

void RotacionMatriz::slot_calcularMatrices()
{
    if ( ui->leKp0a->text().isEmpty() ||
         ui->leKp0b->text().isEmpty() ||
         ui->leKp0c->text().isEmpty() ||
         ui->leKp5a->text().isEmpty() ||
         ui->leKp5b->text().isEmpty() ||
         ui->leKp5c->text().isEmpty() ){
        QMessageBox::critical( nullptr, "ERROR", "Complete los campos numéricos");
    }
    else {
        QVector< QVector< float > > matriz;
        QVector< float > vector1, vector2;
        vector1.append( ui->leKp0a->text().toFloat() );
        vector1.append( ui->leKp0b->text().toFloat() );
        vector1.append( ui->leKp0c->text().toFloat() );
        vector2.append( ui->leKp5a->text().toFloat() );
        vector2.append( ui->leKp5b->text().toFloat() );
        vector2.append( ui->leKp5c->text().toFloat() );

        matriz.clear();
        //Cargamos la matriz de rotación en el eje Z////////////////////////////////////////////////////////////////
        matriz = CalculadorMatrices::getInstancia()->obtenerMatrizT( vector1, vector2, CalculadorMatrices::RotacionZ );

        ui->lMZa->setText( QString::number( matriz.at( 0 ).at( 0 ), 'f', 2 ) );
        ui->lMZb->setText( QString::number( matriz.at( 0 ).at( 1 ), 'f', 2 ) );
        ui->lMZc->setText( QString::number( matriz.at( 0 ).at( 2 ), 'f', 2 ) );
        ui->lMZd->setText( QString::number( matriz.at( 0 ).at( 3 ), 'f', 2 ) );
        ui->lMZe->setText( QString::number( matriz.at( 1 ).at( 0 ), 'f', 2 ) );
        ui->lMZf->setText( QString::number( matriz.at( 1 ).at( 1 ), 'f', 2 ) );
        ui->lMZg->setText( QString::number( matriz.at( 1 ).at( 2 ), 'f', 2 ) );
        ui->lMZh->setText( QString::number( matriz.at( 1 ).at( 3 ), 'f', 2 ) );
        ui->lMZi->setText( QString::number( matriz.at( 2 ).at( 0 ), 'f', 2 ) );
        ui->lMZj->setText( QString::number( matriz.at( 2 ).at( 1 ), 'f', 2 ) );
        ui->lMZk->setText( QString::number( matriz.at( 2 ).at( 2 ), 'f', 2 ) );
        ui->lMZl->setText( QString::number( matriz.at( 2 ).at( 3 ), 'f', 2 ) );
        ui->lMZm->setText( QString::number( matriz.at( 3 ).at( 0 ), 'f', 2 ) );
        ui->lMZn->setText( QString::number( matriz.at( 3 ).at( 1 ), 'f', 2 ) );
        ui->lMZo->setText( QString::number( matriz.at( 3 ).at( 2 ), 'f', 2 ) );
        ui->lMZp->setText( QString::number( matriz.at( 3 ).at( 3 ), 'f', 2 ) );

        matriz.clear();
        //Cargamos la matriz de rotación en el eje Y////////////////////////////////////////////////////////////////
        matriz = CalculadorMatrices::getInstancia()->obtenerMatrizT( vector1, vector2, CalculadorMatrices::RotacionY );

        ui->lMYa->setText( QString::number( matriz.at( 0 ).at( 0 ), 'f', 2 ) );
        ui->lMYb->setText( QString::number( matriz.at( 0 ).at( 1 ), 'f', 2 ) );
        ui->lMYc->setText( QString::number( matriz.at( 0 ).at( 2 ), 'f', 2 ) );
        ui->lMYd->setText( QString::number( matriz.at( 0 ).at( 3 ), 'f', 2 ) );
        ui->lMYe->setText( QString::number( matriz.at( 1 ).at( 0 ), 'f', 2 ) );
        ui->lMYf->setText( QString::number( matriz.at( 1 ).at( 1 ), 'f', 2 ) );
        ui->lMYg->setText( QString::number( matriz.at( 1 ).at( 2 ), 'f', 2 ) );
        ui->lMYh->setText( QString::number( matriz.at( 1 ).at( 3 ), 'f', 2 ) );
        ui->lMYi->setText( QString::number( matriz.at( 2 ).at( 0 ), 'f', 2 ) );
        ui->lMYj->setText( QString::number( matriz.at( 2 ).at( 1 ), 'f', 2 ) );
        ui->lMYk->setText( QString::number( matriz.at( 2 ).at( 2 ), 'f', 2 ) );
        ui->lMYl->setText( QString::number( matriz.at( 2 ).at( 3 ), 'f', 2 ) );
        ui->lMYm->setText( QString::number( matriz.at( 3 ).at( 0 ), 'f', 2 ) );
        ui->lMYn->setText( QString::number( matriz.at( 3 ).at( 1 ), 'f', 2 ) );
        ui->lMYo->setText( QString::number( matriz.at( 3 ).at( 2 ), 'f', 2 ) );
        ui->lMYp->setText( QString::number( matriz.at( 3 ).at( 3 ), 'f', 2 ) );

        matriz.clear();
        //Cargamos la matriz de rotación en el eje X////////////////////////////////////////////////////////////////
        matriz = CalculadorMatrices::getInstancia()->obtenerMatrizT( vector1, vector2, CalculadorMatrices::RotacionX );

        ui->lMXa->setText( QString::number( matriz.at( 0 ).at( 0 ), 'f', 2 ) );
        ui->lMXb->setText( QString::number( matriz.at( 0 ).at( 1 ), 'f', 2 ) );
        ui->lMXc->setText( QString::number( matriz.at( 0 ).at( 2 ), 'f', 2 ) );
        ui->lMXd->setText( QString::number( matriz.at( 0 ).at( 3 ), 'f', 2 ) );
        ui->lMXe->setText( QString::number( matriz.at( 1 ).at( 0 ), 'f', 2 ) );
        ui->lMXf->setText( QString::number( matriz.at( 1 ).at( 1 ), 'f', 2 ) );
        ui->lMXg->setText( QString::number( matriz.at( 1 ).at( 2 ), 'f', 2 ) );
        ui->lMXh->setText( QString::number( matriz.at( 1 ).at( 3 ), 'f', 2 ) );
        ui->lMXi->setText( QString::number( matriz.at( 2 ).at( 0 ), 'f', 2 ) );
        ui->lMXj->setText( QString::number( matriz.at( 2 ).at( 1 ), 'f', 2 ) );
        ui->lMXk->setText( QString::number( matriz.at( 2 ).at( 2 ), 'f', 2 ) );
        ui->lMXl->setText( QString::number( matriz.at( 2 ).at( 3 ), 'f', 2 ) );
        ui->lMXm->setText( QString::number( matriz.at( 3 ).at( 0 ), 'f', 2 ) );
        ui->lMXn->setText( QString::number( matriz.at( 3 ).at( 1 ), 'f', 2 ) );
        ui->lMXo->setText( QString::number( matriz.at( 3 ).at( 2 ), 'f', 2 ) );
        ui->lMXp->setText( QString::number( matriz.at( 3 ).at( 3 ), 'f', 2 ) );

        matriz.clear();
        //Cargamos la matriz de traslación///////////////////////////////////////////////////////////////////////////
        matriz = CalculadorMatrices::getInstancia()->obtenerMatrizT( vector1, vector2, CalculadorMatrices::Traslacion );

        ui->lTa->setText( QString::number( matriz.at( 0 ).at( 0 ), 'f', 2 ) );
        ui->lTb->setText( QString::number( matriz.at( 0 ).at( 1 ), 'f', 2 ) );
        ui->lTc->setText( QString::number( matriz.at( 0 ).at( 2 ), 'f', 2 ) );
        ui->lTd->setText( QString::number( matriz.at( 0 ).at( 3 ), 'f', 2 ) );
        ui->lTe->setText( QString::number( matriz.at( 1 ).at( 0 ), 'f', 2 ) );
        ui->lTf->setText( QString::number( matriz.at( 1 ).at( 1 ), 'f', 2 ) );
        ui->lTg->setText( QString::number( matriz.at( 1 ).at( 2 ), 'f', 2 ) );
        ui->lTh->setText( QString::number( matriz.at( 1 ).at( 3 ), 'f', 2 ) );
        ui->lTi->setText( QString::number( matriz.at( 2 ).at( 0 ), 'f', 2 ) );
        ui->lTj->setText( QString::number( matriz.at( 2 ).at( 1 ), 'f', 2 ) );
        ui->lTk->setText( QString::number( matriz.at( 2 ).at( 2 ), 'f', 2 ) );
        ui->lTl->setText( QString::number( matriz.at( 2 ).at( 3 ), 'f', 2 ) );
        ui->lTm->setText( QString::number( matriz.at( 3 ).at( 0 ), 'f', 2 ) );
        ui->lTn->setText( QString::number( matriz.at( 3 ).at( 1 ), 'f', 2 ) );
        ui->lTo->setText( QString::number( matriz.at( 3 ).at( 2 ), 'f', 2 ) );
        ui->lTp->setText( QString::number( matriz.at( 3 ).at( 3 ), 'f', 2 ) );
        //-//////////////////////////////////////////////////////////////////////////////////////////////////////////
    }

}

void RotacionMatriz::slot_limpiar()
{
    ui->leKp0a->clear();
    ui->leKp0b->clear();
    ui->leKp0c->clear();
    ui->leKp5a->clear();
    ui->leKp5b->clear();
    ui->leKp5c->clear();
    ui->lTa->clear();
    ui->lTb->clear();
    ui->lTc->clear();
    ui->lTd->clear();
    ui->lTe->clear();
    ui->lTf->clear();
    ui->lTg->clear();
    ui->lTh->clear();
    ui->lTi->clear();
    ui->lTj->clear();
    ui->lTk->clear();
    ui->lTl->clear();
    ui->lTm->clear();
    ui->lTn->clear();
    ui->lTo->clear();
    ui->lTp->clear();
    ui->lMXa->clear();
    ui->lMXb->clear();
    ui->lMXc->clear();
    ui->lMXd->clear();
    ui->lMXe->clear();
    ui->lMXf->clear();
    ui->lMXg->clear();
    ui->lMXh->clear();
    ui->lMXi->clear();
    ui->lMXj->clear();
    ui->lMXk->clear();
    ui->lMXl->clear();
    ui->lMXm->clear();
    ui->lMXn->clear();
    ui->lMXo->clear();
    ui->lMXp->clear();
    ui->lMYa->clear();
    ui->lMYb->clear();
    ui->lMYc->clear();
    ui->lMYd->clear();
    ui->lMYe->clear();
    ui->lMYf->clear();
    ui->lMYg->clear();
    ui->lMYh->clear();
    ui->lMYi->clear();
    ui->lMYj->clear();
    ui->lMYk->clear();
    ui->lMYl->clear();
    ui->lMYm->clear();
    ui->lMYn->clear();
    ui->lMYo->clear();
    ui->lMYp->clear();
    ui->lMZa->clear();
    ui->lMZb->clear();
    ui->lMZc->clear();
    ui->lMZd->clear();
    ui->lMZe->clear();
    ui->lMZf->clear();
    ui->lMZg->clear();
    ui->lMZh->clear();
    ui->lMZi->clear();
    ui->lMZj->clear();
    ui->lMZk->clear();
    ui->lMZl->clear();
    ui->lMZm->clear();
    ui->lMZn->clear();
    ui->lMZo->clear();
    ui->lMZp->clear();
}

void RotacionMatriz::slot_Transformar()
{
    // 1 radian * 180 / pi = 57.2958 grados
    if ( ui->pbTransformar->text() == "Grados" )
    {
        ui->pbTransformar->setText( "Radianes" );
        ui->lMXf->setText( QString::number( ui->lMXf->text().toFloat() * 180 / M_PI, 'f', 2 ) );
        ui->lMXg->setText( QString::number( ui->lMXg->text().toFloat() * 180 / M_PI, 'f', 2 ) );
        ui->lMXj->setText( QString::number( ui->lMXj->text().toFloat() * 180 / M_PI, 'f', 2 ) );
        ui->lMXk->setText( QString::number( ui->lMXk->text().toFloat() * 180 / M_PI, 'f', 2 ) );

        ui->lMYa->setText( QString::number( ui->lMYa->text().toFloat() * 180 / M_PI, 'f', 2 ) );
        ui->lMYc->setText( QString::number( ui->lMYc->text().toFloat() * 180 / M_PI, 'f', 2 ) );
        ui->lMYi->setText( QString::number( ui->lMYi->text().toFloat() * 180 / M_PI, 'f', 2 ) );
        ui->lMYk->setText( QString::number( ui->lMYk->text().toFloat() * 180 / M_PI, 'f', 2 ) );

        ui->lMZa->setText( QString::number( ui->lMZa->text().toFloat() * 180 / M_PI, 'f', 2 ) );
        ui->lMZb->setText( QString::number( ui->lMZb->text().toFloat() * 180 / M_PI, 'f', 2 ) );
        ui->lMZe->setText( QString::number( ui->lMZe->text().toFloat() * 180 / M_PI, 'f', 2 ) );
        ui->lMZf->setText( QString::number( ui->lMZf->text().toFloat() * 180 / M_PI, 'f', 2 ) );
    }
    else
    {
        ui->pbTransformar->setText( "Grados" );
        ui->lMXf->setText( QString::number( ui->lMXf->text().toFloat() / 180 * M_PI, 'f', 2 ) );
        ui->lMXg->setText( QString::number( ui->lMXg->text().toFloat() / 180 * M_PI, 'f', 2 ) );
        ui->lMXj->setText( QString::number( ui->lMXj->text().toFloat() / 180 * M_PI, 'f', 2 ) );
        ui->lMXk->setText( QString::number( ui->lMXk->text().toFloat() / 180 * M_PI, 'f', 2 ) );

        ui->lMYa->setText( QString::number( ui->lMYa->text().toFloat() / 180 * M_PI, 'f', 2 ) );
        ui->lMYc->setText( QString::number( ui->lMYc->text().toFloat() / 180 * M_PI, 'f', 2 ) );
        ui->lMYi->setText( QString::number( ui->lMYi->text().toFloat() / 180 * M_PI, 'f', 2 ) );
        ui->lMYk->setText( QString::number( ui->lMYk->text().toFloat() / 180 * M_PI, 'f', 2 ) );

        ui->lMZa->setText( QString::number( ui->lMZa->text().toFloat() / 180 * M_PI, 'f', 2 ) );
        ui->lMZb->setText( QString::number( ui->lMZb->text().toFloat() / 180 * M_PI, 'f', 2 ) );
        ui->lMZe->setText( QString::number( ui->lMZe->text().toFloat() / 180 * M_PI, 'f', 2 ) );
        ui->lMZf->setText( QString::number( ui->lMZf->text().toFloat() / 180 * M_PI, 'f', 2 ) );
    }
}

void RotacionMatriz::on_pbCalcula_clicked()
{
    slot_calcularMatrices();
}

void RotacionMatriz::on_pbTransformar_clicked()
{
    slot_Transformar();
}

void RotacionMatriz::on_pbLimpia_clicked()
{
    slot_limpiar();
}
