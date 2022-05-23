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
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Boton
{
public:
    QLabel *lTexto;

    void setupUi(QWidget *Boton)
    {
        if (Boton->objectName().isEmpty())
            Boton->setObjectName(QString::fromUtf8("Boton"));
        Boton->resize(869, 659);
        Boton->setStyleSheet(QString::fromUtf8(" background-image: url(:/Imagenes/img.png);"));
        lTexto = new QLabel(Boton);
        lTexto->setObjectName(QString::fromUtf8("lTexto"));
        lTexto->setGeometry(QRect(0, 0, 231, 61));
        lTexto->setAlignment(Qt::AlignCenter);

        retranslateUi(Boton);

        QMetaObject::connectSlotsByName(Boton);
    } // setupUi

    void retranslateUi(QWidget *Boton)
    {
        Boton->setWindowTitle(QApplication::translate("Boton", "Form", nullptr));
        lTexto->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Boton: public Ui_Boton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOTON_H
