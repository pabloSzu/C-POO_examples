#ifndef BOTON_H
#define BOTON_H

#include <QWidget>

class Boton : public QWidget
{
    Q_OBJECT
public:
    explicit Boton(QWidget *parent = 0);
    enum Color {ROJO, CELESTE,AZUL};
    void setAspecto(QString texto, Color color);
    void setTexto(QString texto);
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
private:
    QString texto;
    Color color;

signals:
    void signal_click();

public slots:
};

#endif // BOTON_H
