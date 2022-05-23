#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>

namespace Ui {
class formulario;
}

class formulario : public QWidget
{
    Q_OBJECT

public:
    explicit formulario(QWidget *parent = 0);
    ~formulario();

private:
    Ui::formulario *ui;

private slots:
    void slot_textoCambiado( );


};

#endif // FORMULARIO_H
