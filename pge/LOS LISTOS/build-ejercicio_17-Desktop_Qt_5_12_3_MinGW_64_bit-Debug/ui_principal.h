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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "visor.h"

QT_BEGIN_NAMESPACE

class Ui_Principal
{
public:
    QGridLayout *gridLayout;
    Visor *visor;
    QPushButton *pbIniciarCamara;
    QComboBox *cbSeleccionarCamara;
    QPushButton *pbCapturar;

    void setupUi(QWidget *Principal)
    {
        if (Principal->objectName().isEmpty())
            Principal->setObjectName(QString::fromUtf8("Principal"));
        Principal->resize(679, 397);
        gridLayout = new QGridLayout(Principal);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        visor = new Visor(Principal);
        visor->setObjectName(QString::fromUtf8("visor"));

        gridLayout->addWidget(visor, 1, 0, 1, 2);

        pbIniciarCamara = new QPushButton(Principal);
        pbIniciarCamara->setObjectName(QString::fromUtf8("pbIniciarCamara"));

        gridLayout->addWidget(pbIniciarCamara, 0, 1, 1, 1);

        cbSeleccionarCamara = new QComboBox(Principal);
        cbSeleccionarCamara->setObjectName(QString::fromUtf8("cbSeleccionarCamara"));

        gridLayout->addWidget(cbSeleccionarCamara, 0, 0, 1, 1);

        pbCapturar = new QPushButton(Principal);
        pbCapturar->setObjectName(QString::fromUtf8("pbCapturar"));

        gridLayout->addWidget(pbCapturar, 2, 1, 1, 1);


        retranslateUi(Principal);

        QMetaObject::connectSlotsByName(Principal);
    } // setupUi

    void retranslateUi(QWidget *Principal)
    {
        Principal->setWindowTitle(QApplication::translate("Principal", "Principal", nullptr));
        pbIniciarCamara->setText(QApplication::translate("Principal", "Iniciar c\303\241mara", nullptr));
        pbCapturar->setText(QApplication::translate("Principal", "Capturar Imagen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Principal: public Ui_Principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPAL_H
