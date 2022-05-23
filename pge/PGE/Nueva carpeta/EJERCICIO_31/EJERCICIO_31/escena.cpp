#include "escena.h"

Escena::Escena( QWidget *parent ):QGLWidget( parent ){
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
    gluPerspective(45,(GLfloat)(w/h), 0.01f, 120.0f);  //(ang de vision respecto de y,aspecto de vision en x, que tan cerca, que tan lejos)
    // Para delimitar la zona de trabajo en una caja.(izq,der,abajo,arriba,adelante,atras)
    glOrtho( -10, 10, -10, 10, -10, 120 );
}


void Escena::paintGL(){
    // Borra un buffer.
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Se vuelve a este tipo de matrices, que afecta a las primitivas geométricas.
    glMatrixMode( GL_MODELVIEW );

    // Carga la matriz identidad.
    glLoadIdentity();

    glEnable( GL_DEPTH_TEST );

    gluLookAt(x, y, z, 0, 0, -100, 0, 1, 0);

    glTranslatef(0, 0, -2);

    Dibujar();

    // Volcamos en pantalla lo que se creó en memoria.
    glFlush();
}


void Escena::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
        case Qt::Key_A:
            x -= 1.0f;
            break;

        case Qt::Key_D:
            x += 1.0f;
            break;

        case Qt::Key_W:
            y += 1.0f;
            break;

        case Qt::Key_S:
            y -= 1.0f;
            break;

        case Qt::Key_Minus:
            z += 1.0f;
            break;

        case Qt::Key_Plus:
            z -= 1.0f;
            break;
        default:;
    }
    updateGL();
}

void Escena::Dibujar(){
    glBegin( GL_QUADS );
            glVertex3f( 0, 0, 0 );
            glVertex3f( 2, 0, 0 );
            glVertex3f( 2, 2, 0 );
            glVertex3f( 0, 2, 0 );
            glColor3f( 0, 0.3f, 0.7f );
    glEnd();
}
