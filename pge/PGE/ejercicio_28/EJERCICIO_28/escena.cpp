#include "escena.h"

Escena::Escena( QWidget *parent ):QGLWidget( parent ){
    rotX=0;
    rotY=0;
    rotZ=0;
}

void Escena::initializeGL(){
    glClearColor( 0, 0, 0, 0 ); //alfa (R,G,B,alfa)para transparencia
}

void Escena::resizeGL( int w, int h ){
    // Porción de ventana donde puede dibujar.
    glViewport( 0, 0, w, h ); //cuanto de ventana voy a usar para escena

    // Especifica la matriz actual: matriz de proyección (GL_PROJECTION), matriz de modelo
    // (GL_MODELVIEW) y matriz de textura (GL_TEXTURE).
    glMatrixMode( GL_PROJECTION );

    // Con esto cargamos en el "tipo" de matriz actual (matriz identidad - como resetear).
    // Es una matriz 4x4 llena de ceros salvo la diagonal que contiene unos.
    glLoadIdentity();

    // Para delimitar la zona de trabajo en una caja.(izq,der,abajo,arriba,adelante,atras)
    glOrtho( -10, 10, -10, 10, -10, 60 );
}


void Escena::paintGL(){
    // Borra un buffer.
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Se vuelve a este tipo de matrices, que afecta a las primitivas geométricas.
    glMatrixMode( GL_MODELVIEW );

    // Carga la matriz identidad.
    glLoadIdentity();

    gluLookAt( -1, 8, 2, 0, 0, -10, 0, 1, 0 );

    glEnable( GL_DEPTH_TEST );

    glRotatef( rotX, 1, 0, 0 );
    glRotatef( rotY, 0, 1, 0 );//va a rotar "tanto" sobre el eje Y
    glRotatef( rotZ, 0, 0, 1 );

    dibujar();

    // Volcamos en pantalla lo que se creó en memoria.
    glFlush();
}


void Escena::keyPressEvent( QKeyEvent*event ){
    switch( event->key() ){
        case Qt::Key::Key_A:
                rotX++;
            updateGL();
            break;

        case Qt::Key::Key_D:
                rotX--;
            updateGL();
            break;

        case Qt::Key::Key_W:
                rotY++;
            updateGL();
            break;

        case Qt::Key::Key_S:
                rotY--;
            updateGL();
            break;

        case Qt::Key::Key_E:
                rotZ++;
            updateGL();
            break;

        case Qt::Key::Key_Q:
                rotZ--;
            updateGL();
            break;

     default:;
    }
    updateGL();
}

void Escena::dibujar(){

    glBegin( GL_QUADS );

    glColor3f(1, 0, 0);//rojo - cara posterior
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(7.0f, 0.0f, 0.0f);
    glVertex3f(7.0f, 5.0f, 0.0f);
    glVertex3f(1.0f, 3.0f, 0.0f);

    glColor3f(0, 0.8f, 0);//verde - lateral derecho
    glVertex3f(5.0f, 1.0f, 6.0f);
    glVertex3f(7.0f, 0.0f, 0.0f);
    glVertex3f(7.0f, 5.0f, 0.0f);
    glVertex3f(5.0f, 3.0f, 6.0f);

    glColor3f(0, 0, 0.6f);//azul - cara frontal
    glVertex3f(0.0f, 0.0f, 5.0f);
    glVertex3f(5.0f, 1.0f, 6.0f);
    glVertex3f(5.0f, 3.0f, 6.0f);
    glVertex3f(0.0f, 5.0f, 5.0f);

    glColor3f(0, 1, 1);//turquesa - lateral izquierdo
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 3.0f, 0.0f);
    glVertex3f(0.0f, 5.0f, 5.0f);
    glVertex3f(0.0f, 0.0f, 5.0f);

    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 5.0f);
    glVertex3f(5.0f, 1.0f, 6.0f);
    glVertex3f(7.0f, 0.0f, 0.0f);

    glEnd();
}











//------------------otra caja------------------------
/*
    glColor3f(1, 0, 0);//rojo
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 4.0f);
    glVertex3f(0.0f, 2.0f, 4.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);

    glColor3f(0, 0.8, 0);//verde
    glVertex3f(0.0f, 0.0f, 4.0f);
    glVertex3f(3.0f, 0.0f, 4.0f);
    glVertex3f(3.0f, 5.0f, 4.0f);
    glVertex3f(0.0f, 2.0f, 4.0f);

    glColor3f(0, 0, 0.6);//azul
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(3.0f, 0.0f, 0.0f);
    glVertex3f(3.0f, 5.0f, 0.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);

    glColor3f(0, 1, 1);//turquesa
    glVertex3f(3.0f, 0.0f, 0.0f);
    glVertex3f(3.0f, 0.0f, 4.0f);
    glVertex3f(3.0f, 5.0f, 4.0f);
    glVertex3f(3.0f, 5.0f, 0.0f);

    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(3.0f, 0.0f, 0.0f);
    glVertex3f(3.0f, 0.0f, 4.0f);
    glVertex3f(0.0f, 0.0f, 4.0f);
*/


