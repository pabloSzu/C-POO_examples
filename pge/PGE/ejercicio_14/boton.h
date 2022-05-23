#ifndef BOTON_H
#define BOTON_H

#include <QWidget>
#include <QMouseEvent>
#include <QString>
#include <QPaintEvent>

namespace Ui {
class Boton;
}

class Boton : public QWidget {
    Q_OBJECT

public:
    explicit Boton(QWidget *parent = 0);
    ~Boton();
    void configurarAspecto(QString texto, unsigned int colorTexto = 0xFF000000, unsigned int colorFondo = 0xFFFFFFFF);

private:
    Ui::Boton *ui;
    QString texto;
    unsigned int colorTexto, colorFondo;

protected:
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);

signals:
    void signal_clic();

};

#endif // BOTON_H
