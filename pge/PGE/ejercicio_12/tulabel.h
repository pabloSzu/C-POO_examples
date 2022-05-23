#ifndef TULABEL_H
#define TULABEL_H

#include<QLabel>

class TuLabel : public QLabel {
public:
    TuLabel(QWidget *parent = 0);
    void cambiarTexto(QString nuevoTexto);
};

#endif // TULABEL_H
