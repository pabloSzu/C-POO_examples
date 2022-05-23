#ifndef BOTON_H
#define BOTON_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

namespace Ui {
class Boton;
}

class Boton : public QWidget
{
    Q_OBJECT

public:
    explicit Boton(QWidget *parent = 0);
    ~Boton();

    configurarAspectoAc(QString texto, unsigned int colorTexto, unsigned int colorFondo);

protected:
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);

private:
    Ui::Boton *ui;
    QString texto;
    unsigned int colorFondo, colorTexto;

signals:
    void signal_click();
};

#endif // BOTON_H
