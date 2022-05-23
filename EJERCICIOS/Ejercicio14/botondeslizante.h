#ifndef BOTONDESLIZANTE_H
#define BOTONDESLIZANTE_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

namespace Ui {
class BotonDeslizante;
}

class BotonDeslizante : public QWidget
{
    Q_OBJECT

public:
    explicit BotonDeslizante(QWidget *parent = 0);
    ~BotonDeslizante();

    configurarAspectoOp(QString texto, unsigned int colorTexto, unsigned int colorFondo);

protected:
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);

private:
    Ui::BotonDeslizante *ui;
    QString texto;
    unsigned int colorFondo, colorTexto;


signals:
    void signal_click();
};

#endif // BOTONDESLIZANTE_H
