#ifndef LINEADETEXTO_H
#define LINEADETEXTO_H

#include <QLineEdit>
#include <QVector>

class QTreeWidget;
class QTimer;

class LineaDeTexto : public QLineEdit {
    Q_OBJECT

public:
    LineaDeTexto(QWidget * parent = 0);

    void completarBase(QStringList lista);

    int getMaxSugerencias() const;
    void setMaxSugerencias(int value);

    int getTiempoDeEspera() const;
    void setTiempoDeEspera(int value);

private:

    QTreeWidget* popup;
    QTimer* timer;

    QVector<QStringList> lista;  // La base de datos

    int maxSugerencias;
    int tiempoDeEspera;

    void crearPopup();
    bool eventFilter(QObject *obj, QEvent *ev);
    void completarPopup(QVector<QStringList> vector);

private slots:
    void slot_sugerencia();
    void slot_completarLineEdit();
};

#endif // LINEADETEXTO_H
