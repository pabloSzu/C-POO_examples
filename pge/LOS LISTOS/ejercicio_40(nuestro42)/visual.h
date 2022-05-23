#ifndef VISUAL_H
#define VISUAL_H

#include "ogl.h"
#include <math.h>
#include <QVector>
#include <QTimer>

#include <QGLWidget>
#include <GL/glu.h>

class Visual : public Ogl  {
    Q_OBJECT

public:
    Visual();

protected:
    void initializeGL();
    void resizeGL(int ancho, int alto);
    void paintGL();
    void timeout();

    void keyPressEvent(QKeyEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

private:
    void cargarTexturas();
    unsigned char *textura[5];
    GLuint idTexturas[5];

    void dibujarPlanoHorizontal(float x, float y, float z, float ancho, float profundidad, int idTexturas,
                                int repeticionX = 1, int repeticionY = 1);
    void dibujarPlanoVertical(float x, float y, float z, float ancho, float alto, int idTexturas,
                              int repeticionX = 1, int repeticionY = 1);

    float x, y, z;
    float rotacion_hacia_laterales, rotacion_arriba_abajo, rotacionVentilador;
    int mouse_x, mouse_y;
    float gravedad, velocidad;
    float angulo;
    bool salto;

    void moverAtras();
    void moverAdelante();
    void moverIzquierda();
    void moverDerecha();
    void saltar();

    void configurarTextura(int idTextura, QString pathTextura, unsigned char* textura);

private slots:
    void slot_actualizar();
};

#endif // VISUAL_H
