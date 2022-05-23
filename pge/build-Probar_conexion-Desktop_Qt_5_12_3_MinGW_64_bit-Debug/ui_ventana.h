/********************************************************************************
** Form generated from reading UI file 'ventana.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANA_H
#define UI_VENTANA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ventana
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbConexion;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Ventana)
    {
        if (Ventana->objectName().isEmpty())
            Ventana->setObjectName(QString::fromUtf8("Ventana"));
        Ventana->resize(400, 86);
        Ventana->setStyleSheet(QString::fromUtf8("text-decoration: none;\n"
"    padding: 3px;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    font-family: helvetica;\n"
"    font-weight: 300;\n"
"    font-size: 25px;\n"
"    font-style: italic;\n"
"    color: #006505;\n"
"    background-color: #FFF0AF;\n"
"    border-radius: 15px;\n"
"    border: 3px double #006505;"));
        gridLayout = new QGridLayout(Ventana);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        pbConexion = new QPushButton(Ventana);
        pbConexion->setObjectName(QString::fromUtf8("pbConexion"));
        pbConexion->setStyleSheet(QString::fromUtf8("text-decoration: none;\n"
"    padding: 3px;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    font-family: helvetica;\n"
"    font-weight: 300;\n"
"    font-size: 25px;\n"
"    color: #006505;\n"
"    background-color: #82b085;\n"
"    border-radius: 15px;\n"
"    border: 3px double #006505;"));

        gridLayout->addWidget(pbConexion, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);


        retranslateUi(Ventana);

        QMetaObject::connectSlotsByName(Ventana);
    } // setupUi

    void retranslateUi(QWidget *Ventana)
    {
        Ventana->setWindowTitle(QApplication::translate("Ventana", "Form", nullptr));
        pbConexion->setText(QApplication::translate("Ventana", "Probar Conexi\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ventana: public Ui_Ventana {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA_H
