#ifndef GALERIA_H
#define GALERIA_H

#include <QWidget>
#include <QPaintEvent>

namespace Ui {
class Galeria;
}

class Galeria : public QWidget {
    Q_OBJECT

public:
    explicit Galeria(QWidget *parent = 0);
    ~Galeria();

private:
    Ui::Galeria *ui;
    QImage im;
    int indice;

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void slot_mostrarImagen();
};

#endif // GALERIA_H
