#ifndef VISTA_H
#define VISTA_H

#include <QWidget>

class QTimer;
class QTreeWidget;

namespace Ui {
class Vista;
}

class Vista : public QWidget
{
    Q_OBJECT

public:
    explicit Vista(QWidget *parent = 0);
    ~Vista();

private:
    Ui::Vista *ui;

    QTreeWidget* popup;
    QTimer* timer;
    QStringList lista;  // La base de datos

    //Cantidad máxima de sugerencias que se muestran en el popup
    int maxSugerencias;

    void crearPopup();
    bool eventFilter( QObject *obj, QEvent *ev );  // Método virtual de QObject
    void completarPopup( QVector<QStringList> vector );

private slots:
    void slot_sugerencia();
    void slot_completarLineEdit();
    void slot_darDeAlta();
    void slot_agregarSugerencia();
};

#endif // VISTA_H
