#include "lineadetexto.h"

LineaDeTexto::LineaDeTexto(QWidget *parent) : QLineEdit(parent) {

}

LineaDeTexto LineaDeTexto::operator+(LineaDeTexto lineaDeTexto) {
    LineaDeTexto aux;
    aux.setText(this->text() + " " + lineaDeTexto.text());
    return aux;
}

LineaDeTexto::LineaDeTexto(const LineaDeTexto &lineaDeTexto) { //el constructor copia no devuelve nada
    this->setText(lineaDeTexto.text());
}

LineaDeTexto& LineaDeTexto::operator=(const LineaDeTexto &lineaDeTexto) {
    this->setText(lineaDeTexto.text());
    return *this;
}
