#ifndef LINEADETEXTO_H
#define LINEADETEXTO_H

#include <QWidget>
#include <QTreeWidget>
#include <QTimer>
#include <QVector>
#include <cliente.h>

namespace Ui {
class LineaDeTexto;
}

class LineaDeTexto : public QWidget
{
    Q_OBJECT

public:
    explicit LineaDeTexto(QWidget *parent = 0);
    ~LineaDeTexto();

private:
    Ui::LineaDeTexto *ui;
    QTreeWidget * popup;
    QTimer * timer;
    //QStringList fila;
    //QVector<QStringList> todosLosDatos;
    QVector<Cliente> todosLosDatos;
    void crearPopup();
    void completarPopup(QVector<QStringList> recomendaciones); //Clientes??

private slots:
    void slot_sugerencia(); //Mientras escribimos, detectamos (EventFilter).
    void slot_completarLineaDeTexto(); //Cuando recorremos las sugerencias, se completa el texto.

protected:
    bool eventFilter(QObject * o, QEvent * e);
};

#endif // LINEADETEXTO_H
