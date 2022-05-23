#ifndef ESCENA_H
#define ESCENA_H

#include <QWidget>
#include <QGLWidget>
#include <GL/glu.h>
#include <QKeyEvent>

class Escena : public QGLWidget{
    Q_OBJECT
public:
    Escena( QWidget *parent=0 );
    void Dibujar();

protected:
    void initializeGL(); //caracteristicas por defecto ej color de fondo
    void resizeGL( int w , int h ); //se invoca solo cuando cambia el tamaño ventana
    void paintGL(); //invocar cuando queremos refrescar la escena
    float x,y,z =0;
    void keyPressEvent( QKeyEvent* );
};

#endif // ESCENA_H
