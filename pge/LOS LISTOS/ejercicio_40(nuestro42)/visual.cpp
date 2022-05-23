#include "visual.h"
#include <GL/glu.h>
//#include <glu.h>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>

Visual::Visual() : Ogl(), x(0), y(0), z(0), rotacion_hacia_laterales(0), rotacion_arriba_abajo(0), rotacionVentilador(0), angulo(0),
                   mouse_x(0), mouse_y(0), salto(false) {
    setMouseTracking(true);

    this->setTimer(10);

}

void Visual::keyPressEvent(QKeyEvent *e)  {
    switch (e->key()) {
        case Qt::Key_Escape:
            close();
            break;
        case Qt::Key_W:
            moverAdelante();
            break;
        case Qt::Key_S:
            moverAtras();
            break;
        case Qt::Key_D:
            moverDerecha();
            break;
        case Qt::Key_A:
            moverIzquierda();
            break;
        case Qt::Key_Space:
            saltar();
            break;
        default:;
    }
}

void Visual::mouseMoveEvent(QMouseEvent *e)  {
   if((e->x() - mouse_x) < 0)  // Detecta si el mouse se desplazo a la izquierda
       rotacion_hacia_laterales -= 1;  // Giramos a la izquierda
   else if((e->x() - mouse_x) > 0)  // Detecta si el mouse se desplazo a la derecha
       rotacion_hacia_laterales += 1;  // Giramos a la derecha

   if((e->y() - mouse_y) < 0)  // Detecta si el mouse se desplazo hacia abajo
       rotacion_arriba_abajo -= 1;
   else if((e->y() - mouse_y) > 0) // Detecta si el mouse se desplazo hacia arriba
       rotacion_arriba_abajo += 1;

   if(abs(rotacion_hacia_laterales) == 360)
       rotacion_hacia_laterales = 0;
   if(rotacion_arriba_abajo > 40)
       rotacion_arriba_abajo = 40;
   else if(rotacion_arriba_abajo < -40)
       rotacion_arriba_abajo = -40;

   // Aqui almacenamos la posicion del mouse para controlar
   // para donde se desplaza, si a la derecha o a la izquierda.
   mouse_x = e->x();
   mouse_y = e->y();

   if( e->x() > (this->width()/2)+150 || e->x() < (this->width()/2)-150 ||
       e->y() > (this->height()/2)+150 || e->y() < (this->height()/2)-150)
        QCursor::setPos(this->width()/2,this->height()/2);  // Mantenemos el mouse en el centro

}

// Calculamos con seno y coseno que desplazamientos corresponde segun la rotacion
void Visual::moverAtras()  {
    float radianes = 2*M_PI*rotacion_hacia_laterales/360;
    x += sin(radianes);
    z -= cos(radianes);
}

// Calculamos con seno y coseno que desplazamientos corresponde segun la rotacion
void Visual::moverAdelante()  {
    float radianes = 2*M_PI*rotacion_hacia_laterales/360;
    x -= sin(radianes);
    z += cos(radianes);
}

// Calculamos con seno y coseno que desplazamientos corresponde segun la rotacion
void Visual::moverIzquierda()  {
    float radianes = 2*M_PI*rotacion_hacia_laterales/360;
    x += cos(radianes);
    z += sin(radianes);
}

// Calculamos con seno y coseno que desplazamientos corresponde segun la rotacion
void Visual::moverDerecha()  {
    float radianes = 2*M_PI*rotacion_hacia_laterales/360;
    x -= cos(radianes);
    z -= sin(radianes);
}

void Visual::saltar()  {
    salto = true;
}

void Visual::slot_actualizar() {
    if (salto) {
        y = -10*sin(angulo);

        angulo += 0.07;

        if(angulo >= 3.14) {
            y = 0;
            angulo = 0;
            salto = false;
        }
    }
}

void Visual::timeout() {
    slot_actualizar();
    this->updateGL();
}

void Visual::initializeGL()  {
    this->cargarTexturas();
    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);
}

void Visual::resizeGL(int ancho, int alto)  {
    glViewport( 0, 0, ancho, alto );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)ancho/(GLfloat)alto, 1, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
}

void Visual::paintGL()  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glRotatef(rotacion_arriba_abajo, 1, 0, 0);
    glRotatef(rotacion_hacia_laterales, 0, 1, 0);
    glTranslatef(x, y, z);
    glTranslatef(-50, -5, 5);

    this->dibujarPlanoHorizontal(-100,0,100, 400,400, idTexturas[2], 20,20);
    this->dibujarPlanoHorizontal(0,20,0, 100,100, idTexturas[0], 5,5);
    this->dibujarPlanoVertical(0,0,0, 100,20, idTexturas[1], 5,1);
    this->dibujarPlanoVertical(0,0,-100, 100,20, idTexturas[1], 5,1);

    glRotatef(90, 0,1,0);

    this->dibujarPlanoVertical(0,0,0, 100,20, idTexturas[1], 5,1);
    this->dibujarPlanoVertical(0,0,100, 100,20, idTexturas[1], 5,1);

    glFlush();
}

void Visual::cargarTexturas()   {
    glGenTextures(4, idTexturas);

    configurarTextura(idTexturas[0], "../../../../ejercicio_37/Texturas/techo.jpg", textura[0]);
    configurarTextura(idTexturas[1], "../../../../ejercicio_37/Texturas/pared.png", textura[2]);
    configurarTextura(idTexturas[2], "../../../../ejercicio_37/Texturas/piso.jpg", textura[2]);
    configurarTextura(idTexturas[3], "../../../../ejercicio_37/Texturas/rojo.png", textura[3]);
    configurarTextura(idTexturas[4], "../../../../ejercicio_37/Texturas/verde.png", textura[4]);
}

void Visual::configurarTextura(int idTextura, QString pathTextura, unsigned char* textura)  {
    glEnable(GL_TEXTURE_2D);	// Activamos la texturizacion

    QImage im;
    if (!im.load(pathTextura))  {
        QMessageBox::critical(this, "Recurso no disponible", "La imagen no pudo ser cargada.");
        return;
    }

    im = QGLWidget::convertToGLFormat( im );
    textura = im.bits();

    glBindTexture(GL_TEXTURE_2D, idTextura);  // Activamos idTextura.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // GL_LINEAR - Interpolacion
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // GL_NEAREST - Sin

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);  // GL_CLAMP -
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);  // GL_REPEAT - Permite repetir

    glTexImage2D(GL_TEXTURE_2D, 0, 3, im.width(), im.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, textura);

    glDisable(GL_TEXTURE_2D);	// Desactivamos la texturizacion
}


void Visual::dibujarPlanoHorizontal(float x, float y, float z, float ancho, float profundidad, int idTextura,
                                    int repeticionX, int repeticionY)  {
    glEnable(GL_TEXTURE_2D);	// Activamos la texturizacion
    glBindTexture(GL_TEXTURE_2D, idTextura);	// Activamos la textura con idTextura

    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  glVertex3f(x, y, z);
        glTexCoord2f(repeticionX, 0);  glVertex3f(x+ancho, y, z);
        glTexCoord2f(repeticionX, repeticionY);  glVertex3f(x+ancho, y, z-profundidad);
        glTexCoord2f(0, repeticionY);  glVertex3f(x, y, z-profundidad);
    glEnd();

    glDisable(GL_TEXTURE_2D);	// Desactivamos la texturizacion
}

void Visual::dibujarPlanoVertical(float x, float y, float z, float ancho, float alto, int idTextura,
                                  int repeticionX, int repeticionY)  {
    glEnable(GL_TEXTURE_2D);	// Activamos la texturizacion
    glBindTexture(GL_TEXTURE_2D, idTextura);	// Activamos la textura con idTextura

    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  glVertex3f(x, y, z);
        glTexCoord2f(repeticionX, 0);  glVertex3f(x+ancho, y, z);
        glTexCoord2f(repeticionX, repeticionY);  glVertex3f(x+ancho, y+alto, z);
        glTexCoord2f(0, repeticionY);  glVertex3f(x, y+alto, z);
    glEnd();

    glDisable(GL_TEXTURE_2D);	// Desactivamos la texturizacion
}



