#ifndef BOTON_H
#define BOTON_H

#include <QWidget>
#include <QString>
#include <QPaintEvent>
#include <QMouseEvent>

namespace Ui {
class Boton;
}

class Boton : public QWidget {
    Q_OBJECT

public:
    explicit Boton(QWidget *parent = 0);
    enum Color{ROJO, CELESTE, AZULADO};
    void setAspecto(QString texto, Color color);
    void setTexto(QString texto);
    ~Boton();

private:
    Ui::Boton *ui;
    QString texto;
    Color color;

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent * e);

signals:
    void signal_clic();
};

#endif // BOTON_H
