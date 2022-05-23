/********************************************************************************
** Form generated from reading UI file 'principal.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINCIPAL_H
#define UI_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "visor.h"

QT_BEGIN_NAMESPACE

class Ui_Principal
{
public:
    QGridLayout *gridLayout;
    QPushButton *pbIniciarCamara;
    QSlider *hsGuardar;
    QComboBox *cbSeleccionarCamara;
    Visor *visor;
    QLabel *lSlider;

    void setupUi(QWidget *Principal)
    {
        if (Principal->objectName().isEmpty())
            Principal->setObjectName(QString::fromUtf8("Principal"));
        Principal->resize(679, 397);
        gridLayout = new QGridLayout(Principal);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pbIniciarCamara = new QPushButton(Principal);
        pbIniciarCamara->setObjectName(QString::fromUtf8("pbIniciarCamara"));

        gridLayout->addWidget(pbIniciarCamara, 0, 2, 1, 1);

        hsGuardar = new QSlider(Principal);
        hsGuardar->setObjectName(QString::fromUtf8("hsGuardar"));
        hsGuardar->setMinimum(1);
        hsGuardar->setMaximum(10);
        hsGuardar->setSingleStep(1);
        hsGuardar->setPageStep(10);
        hsGuardar->setValue(1);
        hsGuardar->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hsGuardar, 2, 1, 1, 1);

        cbSeleccionarCamara = new QComboBox(Principal);
        cbSeleccionarCamara->setObjectName(QString::fromUtf8("cbSeleccionarCamara"));

        gridLayout->addWidget(cbSeleccionarCamara, 0, 0, 1, 2);

        visor = new Visor(Principal);
        visor->setObjectName(QString::fromUtf8("visor"));

        gridLayout->addWidget(visor, 1, 0, 1, 4);

        lSlider = new QLabel(Principal);
        lSlider->setObjectName(QString::fromUtf8("lSlider"));

        gridLayout->addWidget(lSlider, 2, 2, 1, 2);


        retranslateUi(Principal);

        QMetaObject::connectSlotsByName(Principal);
    } // setupUi

    void retranslateUi(QWidget *Principal)
    {
        Principal->setWindowTitle(QApplication::translate("Principal", "Principal", nullptr));
        pbIniciarCamara->setText(QApplication::translate("Principal", "Iniciar c\303\241mara", nullptr));
        lSlider->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Principal: public Ui_Principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPAL_H
