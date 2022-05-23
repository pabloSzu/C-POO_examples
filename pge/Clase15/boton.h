#ifndef BOTON_H
#define BOTON_H

#include <QWidget>

namespace Ui {
    class Boton;
}

class Boton : public QWidget
{
    Q_OBJECT
public:
    enum Red { Facebook, Twitter, Google, LinkedIn, Instagram, Otra };

    explicit Boton( Red red = Otra, QWidget *parent = nullptr );
    ~Boton();
    void setRed( Red red );
    Red getRed();
    void setTexto( QString texto );
    QString texto();


private:
    Ui::Boton *ui;
    Red red;

    void paintEvent( QPaintEvent *event );
    void mousePressEvent(QMouseEvent *event);

signals:
    void signal_click( Red );

public slots:
    void click();

};

#endif // BOTON_H
