#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QPaintEvent>

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = 0);
    ~Ventana();

private:
    Ui::Ventana *ui;
    QImage im;

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void slot_convertirImagen();
};

#endif // VENTANA_H
