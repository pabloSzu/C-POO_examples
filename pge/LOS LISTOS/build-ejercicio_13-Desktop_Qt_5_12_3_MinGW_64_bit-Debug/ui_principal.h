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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_principal
{
public:
    QAction *actionNuevo;
    QAction *actionAbrir;
    QAction *actionGuardar;
    QAction *actionSalir;
    QAction *actionBuscar;
    QAction *actionOpciones;
    QAction *actionAcerca_de;
    QAction *actionAyuda;
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuEdici_n;
    QMenu *menuHerramientas;
    QMenu *menuAyuda;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *principal)
    {
        if (principal->objectName().isEmpty())
            principal->setObjectName(QString::fromUtf8("principal"));
        principal->resize(393, 300);
        actionNuevo = new QAction(principal);
        actionNuevo->setObjectName(QString::fromUtf8("actionNuevo"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNuevo->setIcon(icon);
        actionAbrir = new QAction(principal);
        actionAbrir->setObjectName(QString::fromUtf8("actionAbrir"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagenes/opened.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbrir->setIcon(icon1);
        actionGuardar = new QAction(principal);
        actionGuardar->setObjectName(QString::fromUtf8("actionGuardar"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagenes/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGuardar->setIcon(icon2);
        actionSalir = new QAction(principal);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagenes/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSalir->setIcon(icon3);
        actionBuscar = new QAction(principal);
        actionBuscar->setObjectName(QString::fromUtf8("actionBuscar"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imagenes/folder_search.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBuscar->setIcon(icon4);
        actionOpciones = new QAction(principal);
        actionOpciones->setObjectName(QString::fromUtf8("actionOpciones"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/imagenes/option.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpciones->setIcon(icon5);
        actionAcerca_de = new QAction(principal);
        actionAcerca_de->setObjectName(QString::fromUtf8("actionAcerca_de"));
        actionAcerca_de->setIcon(icon5);
        actionAyuda = new QAction(principal);
        actionAyuda->setObjectName(QString::fromUtf8("actionAyuda"));
        actionAyuda->setIcon(icon5);
        centralWidget = new QWidget(principal);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(13, 8, 370, 200));
        principal->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(principal);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 393, 22));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuEdici_n = new QMenu(menuBar);
        menuEdici_n->setObjectName(QString::fromUtf8("menuEdici_n"));
        menuHerramientas = new QMenu(menuBar);
        menuHerramientas->setObjectName(QString::fromUtf8("menuHerramientas"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QString::fromUtf8("menuAyuda"));
        principal->setMenuBar(menuBar);
        mainToolBar = new QToolBar(principal);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        principal->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(principal);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        principal->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuEdici_n->menuAction());
        menuBar->addAction(menuHerramientas->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuArchivo->addAction(actionNuevo);
        menuArchivo->addAction(actionAbrir);
        menuArchivo->addAction(actionGuardar);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSalir);
        menuEdici_n->addAction(actionBuscar);
        menuHerramientas->addAction(actionOpciones);
        menuAyuda->addAction(actionAcerca_de);
        menuAyuda->addAction(actionAyuda);
        mainToolBar->addAction(actionGuardar);
        mainToolBar->addAction(actionSalir);

        retranslateUi(principal);

        QMetaObject::connectSlotsByName(principal);
    } // setupUi

    void retranslateUi(QMainWindow *principal)
    {
        principal->setWindowTitle(QApplication::translate("principal", "principal", nullptr));
        actionNuevo->setText(QApplication::translate("principal", "Nuevo", nullptr));
        actionAbrir->setText(QApplication::translate("principal", "Abrir", nullptr));
        actionGuardar->setText(QApplication::translate("principal", "Guardar", nullptr));
        actionSalir->setText(QApplication::translate("principal", "Salir", nullptr));
        actionBuscar->setText(QApplication::translate("principal", "Buscar", nullptr));
        actionOpciones->setText(QApplication::translate("principal", "Opciones", nullptr));
        actionAcerca_de->setText(QApplication::translate("principal", "Acerca de...", nullptr));
        actionAyuda->setText(QApplication::translate("principal", "Ayuda", nullptr));
        menuArchivo->setTitle(QApplication::translate("principal", "Archivo", nullptr));
        menuEdici_n->setTitle(QApplication::translate("principal", "Edici\303\263n", nullptr));
        menuHerramientas->setTitle(QApplication::translate("principal", "Herramientas", nullptr));
        menuAyuda->setTitle(QApplication::translate("principal", "Ayuda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class principal: public Ui_principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPAL_H
