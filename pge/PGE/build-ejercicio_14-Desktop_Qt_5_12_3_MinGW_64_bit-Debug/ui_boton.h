/********************************************************************************
** Form generated from reading UI file 'boton.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOTON_H
#define UI_BOTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Boton
{
public:

    void setupUi(QWidget *Boton)
    {
        if (Boton->objectName().isEmpty())
            Boton->setObjectName(QString::fromUtf8("Boton"));
        Boton->resize(400, 300);

        retranslateUi(Boton);

        QMetaObject::connectSlotsByName(Boton);
    } // setupUi

    void retranslateUi(QWidget *Boton)
    {
        Boton->setWindowTitle(QApplication::translate("Boton", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Boton: public Ui_Boton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOTON_H
