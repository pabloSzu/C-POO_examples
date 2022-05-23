#include "principal.h"
#include "ui_principal.h"
#include "typeinfo"
#include <QDebug>
#include <QMessageBox>

Principal::Principal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Principal) {
    ui->setupUi(this);


    connect(ui->pbCliente, SIGNAL(pressed()), this, SLOT(slot_agregar()));
    connect(ui->pbEmpleado, SIGNAL(pressed()), this, SLOT(slot_agregar()));
}

Principal::~Principal() {
    delete ui;
}


void Principal::slot_agregar()  {

    if (this->sender() == ui->pbCliente)  {
        if (vector.isEmpty())  {
            vector.push_back(new Cliente);
            qDebug() << "Se agrega como primer elemento un Cliente";
        }
        else  {
            Cliente * pd = dynamic_cast<Cliente*>(vector.at(0));

            if (typeid(pd) == typeid(Cliente*) && pd != NULL)  {
                vector.push_back(new Cliente);
                qDebug() << "Se agrega otro Cliente. El Cliente numero" << vector.size();
            }
            else  {
                QMessageBox::information(this, "Mensaje", "Este QVector no contiene Clientes. No se agrega nada.");
            }
        }
    }
    else  {
        if (vector.isEmpty())  {
            vector.push_back(new Empleado);
            qDebug() << "Se agrega como primer elemento un Empleado";
        }
        else  {
            Empleado * pd = dynamic_cast<Empleado*>(vector.at(0));

            if (typeid(pd) == typeid(Empleado*) && pd != NULL)  {
                vector.push_back(new Empleado);
                qDebug() << "Se agrega otro Cliente. El Empleado numero" << vector.size();
            }
            else  {
                QMessageBox::information(this, "Mensaje", "Este QVector no contiene Empleados. No se agrega nada.");
            }
        }
    }
}
