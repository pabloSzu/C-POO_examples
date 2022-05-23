#include "lineadetexto.h"
#include <QTreeWidget>
#include <QTimer>
#include <QHeaderView>
#include <QKeyEvent>

LineaDeTexto::LineaDeTexto(QWidget * parent) : QLineEdit(parent), maxSugerencias(5),
                                                                  tiempoDeEspera(200) {

    this->crearPopup();
}

void LineaDeTexto::completarBase(QStringList lista) {
    this->lista.append(lista);
}

int LineaDeTexto::getMaxSugerencias() const {
    return maxSugerencias;
}

void LineaDeTexto::setMaxSugerencias(int value) {
    maxSugerencias = value;
}

int LineaDeTexto::getTiempoDeEspera() const {
    return tiempoDeEspera;
}

void LineaDeTexto::setTiempoDeEspera(int value) {
    tiempoDeEspera = value;

    timer->setInterval(tiempoDeEspera);
}

void LineaDeTexto::crearPopup()  {
    popup = new QTreeWidget;
    popup->setColumnCount(2);

    popup->setRootIsDecorated(false);  // Elimina el lugar del ícono de la izquierda.
    popup->header()->hide();  // Oculta la cabecera

    //Habilita a que eventFilter capture todos los eventos que sucedan en popup
    popup->installEventFilter(this);

    //Detecta el click del mouse sobre un item de los recomendados
    connect(popup, SIGNAL(itemClicked(QTreeWidgetItem*, int)), SLOT(slot_completarLineEdit()));

    popup->setWindowFlags(Qt::Popup);  // Para que la ventana sea estilo popup

    timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(tiempoDeEspera);

    // Cada 200 mseg busca coincidencias
    connect(timer, SIGNAL(timeout()), SLOT(slot_sugerencia()));
    connect(this, SIGNAL(textEdited(QString)), timer, SLOT(start()));
}

/**
  * Cuando se pulsa enter o se hace clic sobre uno de los ítems sugeridos se llama a este método
  * para desglosar el resultado y completar el QLineEdit.
  */
void LineaDeTexto::slot_completarLineEdit()  {
    timer->stop();
    popup->hide();

    //Pone el cursor sobre este QLineEdit
    this->setFocus();

    QTreeWidgetItem *item = popup->currentItem();

    if (item)  {
        // Seteamos el QLineEdit con el texto de la primer columna.
        this->setText(item->text(0));
    }
}

/**
  * Método para sugerir los clientes según lo que se vaya ingresando en el QLineEdit.
  * Para hacer esto se consulta a la base de datos devolviendo un QVector<QStringList>.
  */
void LineaDeTexto::slot_sugerencia()   {
    QVector<QStringList> vectorCoincidencias;  // Almacenará las sugerencias
    QString cadena = this->text();

    // Este for se encarga de encontrar las coincidencias. Se sugieren hasta 5.
    for (int i = 0, contador = 0;  i<lista.size() && contador< maxSugerencias; i++)  {

        QString primerColumna = lista.at(i).at(0);
        QString segundaColumna = lista.at(i).at(1);

        if (primerColumna.contains(cadena, Qt::CaseInsensitive))  {
            QStringList sugerencia;
            sugerencia << primerColumna << segundaColumna;
            vectorCoincidencias.push_back(sugerencia);
            contador++;
        }
    }

    // Si no existe lo que se busca se limpia el QLineEdit.
    if (vectorCoincidencias.size() == 0)  {
        //ui->leBuscar->clear();
        return;
    }

    // Completa el popup con las sugerencias
    this->completarPopup(vectorCoincidencias);
}

/**
  * Completa el QTreeWidget con el resultado de la consulta a la base de datos y lo visualiza.
  */
void LineaDeTexto::completarPopup(QVector<QStringList> vector)  {
    popup->clear();

    for (int i = 0; i < vector.size(); ++i) {
        QTreeWidgetItem * item;
        item = new QTreeWidgetItem(popup);
        item->setText(0, vector.at(i).at(0));
        item->setText(1, vector.at(i).at(1));
        item->setTextAlignment(1, Qt::AlignRight);  // Para alinear contra la derecha
    }

    popup->setCurrentItem(popup->topLevelItem(0));  // Queda seleccionado el primer elemento

    //La cantidad de líneas que tiene la lista desplegable
    int h = popup->sizeHintForRow(0) * qMin(maxSugerencias, vector.size()) + 3; //+3 evita que se cree el scroll

    // El ancho del popup es igual al ancho del QLineEdit
    popup->resize(this->width(), h);

    // Lo posiciona justo abajo del QLineEdit
    popup->move(this->mapToGlobal(QPoint(0, this->height())));

    popup->setFocus();
    popup->show();
}

/**
  * Método virtual de QObject para capturar eventos de teclado y de mouse. Se lo instala
  * llamando al método installEventFilter(). Si este método devuelve true entonces ninguna
  * otra implementación de este método en clases derivadas capturará este evento.
  */
bool LineaDeTexto::eventFilter(QObject *obj, QEvent *ev)  {
    if (obj == popup)  {
        if (ev->type() == QEvent::MouseButtonPress) {
            popup->hide();
            this->setFocus();

            return true;
        }

        if (ev->type() == QEvent::KeyPress) {
            bool reconocido = false;
            int key = static_cast<QKeyEvent*>(ev)->key();

            switch (key) {

            case Qt::Key_Enter:
            case Qt::Key_Tab:
            case Qt::Key_Return:
                this->slot_completarLineEdit();
                reconocido = true;
                break;

            case Qt::Key_Escape:
                this->setFocus();
                // Si se presiona escape entonces limpiamos.
                this->clear();
                popup->hide();
                reconocido = true;
                break;

            case Qt::Key_Up:
            case Qt::Key_Down:
            case Qt::Key_Home:
            case Qt::Key_End:
            case Qt::Key_PageUp:
            case Qt::Key_PageDown:
                break;

            default:
                // Hace que permanezca el cursor en el QLineEdit para seguir escribiendo
                this->event(ev);
                popup->hide();
                break;
            }
            return reconocido;
        }
    }
    return false;
}
