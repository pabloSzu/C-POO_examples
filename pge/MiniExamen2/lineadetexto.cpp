#include "lineadetexto.h"
#include "ui_lineadetexto.h"
#include <QHeaderView>
#include <QKeyEvent>
#include <QStringList>
#include <QDebug>

LineaDeTexto::LineaDeTexto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LineaDeTexto),
    timer (new QTimer(this))
{
    ui->setupUi(this);

    /*QStringList dato1;
    dato1 << "cosimani" << "123456";
    QStringList dato2;
    dato2 << "cduarte" << "carlitos123";*/

    Cliente c1("Carlos", "Ponce", "Santander");
    Cliente c2("Miguel", "Abuelo", "Santander");
    Cliente c3("Jose", "Feliciano", "SmartCampus");
    Cliente c4("Raul", "Carnota", "SmartCampus");
    Cliente c5("Jorge", "Fandermole", "SmartCampus");
    Cliente c6("Carlos", "Guastavino", "Despegar");
    Cliente c7("Franco", "Barrionuevo", "Despegar");
    Cliente c8("Juan", "Gabriel", "Changos");



    todosLosDatos << c8 << c6 << c7 << c1 << c2 << c3 << c4 << c5;

    timer->setSingleShot(true);
    timer->setInterval(200);

    // Cada 200 mseg busca coincidencias
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_sugerencia()));
    connect(ui->leUsuario, SIGNAL(textEdited(QString)), timer, SLOT(start()));

    //connect(ui->leUsuario, SIGNAL(textEdited(QString)), timer, SLOT(start()));

    this->crearPopup();
}

void LineaDeTexto::crearPopup() {
    popup = new QTreeWidget;
    popup->setColumnCount(3);
    popup->setRootIsDecorated(false); //Se saca la columna de índices.
    popup->header()->hide(); //Se saca la fila de cabecera.
    popup->setWindowFlags(Qt::Popup);  // Para que la ventana sea estilo popup

    popup->installEventFilter(this);

    //La señal puede enviar algo y el slot no recibirlo. No al revés.
    connect(popup, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(slot_completarLineaDeTexto()));



    //Lo hacemos en eventFilter
    //connect(ui->leUsuario, SIGNAL(textEdited(QString)), timer, SLOT(start()));
}

void LineaDeTexto::completarPopup(QVector<QStringList> recomendaciones) {
    popup->clear();

    for (int i = 0; i < recomendaciones.size(); ++i) {
        QTreeWidgetItem * item;
        item = new QTreeWidgetItem(popup);
        item->setText(0, recomendaciones.at(i).at(0));
        item->setText(1, recomendaciones.at(i).at(1));
        item->setText(2, recomendaciones.at(i).at(2));
        //item->setTextAlignment(1, Qt::AlignRight);  // Para alinear contra la derecha
    }

    popup->setCurrentItem(popup->topLevelItem(0));  // Queda seleccionado el primer elemento

    // Este número 5 es la cantidad de líneas que tiene la lista desplegable
    int h = popup->sizeHintForRow(0) * qMin(5, recomendaciones.size()) + 3;

    // El ancho del popup es igual al ancho del QLineEdit
    popup->resize(ui->leUsuario->width(), h);

    // Lo posiciona justo abajo del QLineEdit
    popup->move(ui->leUsuario->mapToGlobal(QPoint(0, ui->leUsuario->height())));

    popup->setFocus();
    popup->show();
}

void LineaDeTexto::slot_sugerencia() {
    QVector<QStringList> vectorCoincidencias;  // Almacenará las sugerencias
    QString cadena = ui->leUsuario->text();  //Se escribe la empresa.


    // Este for se encarga de encontrar las coincidencias. Se sugieren hasta 6.
    for (int i=0, contador=0 ; i<todosLosDatos.size() && contador<6 ; i++) {

        //QString string = todosLosDatos.at(i).at(0);
        QString nombres = todosLosDatos.at(i).getNombre();
        QString apellidos = todosLosDatos.at(i).getApellido();
        QString empresas = todosLosDatos.at(i).getEmpresa();

        if (empresas.contains(cadena)) {
            QStringList sugerencia;
            //QString asteriscos = todosLosDatos.at(i).at(1);

            sugerencia << nombres << apellidos << empresas;

            //asteriscos.fill('*');


            //sugerencia << string << asteriscos;
           // qDebug( ) << sugerencia;
            vectorCoincidencias << sugerencia;
            //qDebug() << vectorCoincidencias;
            contador++;
        }


        /*else {
            QStringList sugerencia;





            sugerencia << nombres << apellidos << empresas ;
            sugerencia.sort();

            qDebug() << sugerencia;

        }*/
    }

    // Si no existe lo que se busca se limpia el QLineEdit.
    if (vectorCoincidencias.size() == 0) {
        ui->leUsuario->clear();
        for (int i=0, contador=0 ; i<todosLosDatos.size() && contador<5 ; i++) {
            QString nombres = todosLosDatos.at(i).getNombre();
            QString apellidos = todosLosDatos.at(i).getApellido();
            QString empresas = todosLosDatos.at(i).getEmpresa();

            QStringList sugerencia;
            sugerencia << nombres << apellidos << empresas;
            //qDebug() << sugerencia;

            vectorCoincidencias << sugerencia;
        }
        //return;
    }

    // Completa el popup con las sugerencias
    this->completarPopup(vectorCoincidencias);
}

bool LineaDeTexto::eventFilter(QObject *o, QEvent *e) {
    if (o == popup) {
        if (e->type() == QEvent::MouseButtonPress) {
            popup->hide();
            ui->leUsuario->setFocus();
            return true;
        }

        if (e->type() == QEvent::KeyPress) {
            bool reconocido = false;
            int key = static_cast<QKeyEvent*>(e)->key(); //Casting

            switch (key) {

            case Qt::Key_Enter:
            case Qt::Key_Tab:
            case Qt::Key_Return:
                this->slot_completarLineaDeTexto();
                reconocido = true;
                break;

            case Qt::Key_Escape:
                ui->leUsuario->setFocus();
                // Si se presiona escape entonces limpiamos.
                ui->leUsuario->clear();
                popup->hide();
                reconocido = true;

            case Qt::Key_Up:
            case Qt::Key_Down:
            case Qt::Key_Home:
            case Qt::Key_End:
            case Qt::Key_PageUp:
            case Qt::Key_PageDown:
                break;

            default:
                // Hace que permanezca el cursor en el QLineEdit para seguir escribiendo
                ui->leUsuario->event(e);
                popup->hide();
                break;
            }
            return reconocido;
        }
    }
    return false;
}

void LineaDeTexto::slot_completarLineaDeTexto() {
    timer->stop();
    popup->hide();
    ui->leUsuario->setFocus();

    QTreeWidgetItem *item = popup->currentItem();

    if (item)  {
        // Seteamos el QLineEdit con el texto del nombre del producto elegido.
        ui->leUsuario->setText(item->text(0) + " " + item->text(1) + " " + "(" + item->text(2) + ")");
    }
}

LineaDeTexto::~LineaDeTexto()
{
    delete ui;
}
