#ifndef LINEADETEXTO_H
#define LINEADETEXTO_H

#include <QLineEdit>

class LineaDeTexto : public QLineEdit {
    Q_OBJECT
public:
    explicit LineaDeTexto(QWidget *parent = 0);
    LineaDeTexto operator+(LineaDeTexto lineaDeTexto);
    LineaDeTexto(const LineaDeTexto &lineaDeTexto);
    LineaDeTexto& operator=(const LineaDeTexto &lineaDeTexto);

};

#endif // LINEADETEXTO_H
