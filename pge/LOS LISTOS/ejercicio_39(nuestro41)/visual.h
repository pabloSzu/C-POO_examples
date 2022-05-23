#ifndef VISUAL_H
#define VISUAL_H

#include "ogl.h"
#include <math.h>
#include <QVector>

class Visual : public Ogl  {
    Q_OBJECT

public:
    Visual();

protected:
    void initializeGL();
    void resizeGL(int ancho, int alto);
    void paintGL();

    void keyPressEvent(QKeyEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

private:
    void cargarTexturas();
    unsigned char *textura[4];
    GLuint idTexturas[4];

    QPoint lastPos;

    void dibujarPlanoHorizontal(float x, float y, float z, float ancho, float profundidad, int idTexturas,
                                int repeticionX = 1, int repeticionY = 1);
    void dibujarPlanoVertical(float x, float y, float z, float ancho, float alto, int idTexturas,
                              int repeticionX = 1, int repeticionY = 1);

    float x, y, z;
    float rotacion_hacia_laterales, rotacion_arriba_abajo;
    float horizontal_aux, vertical_aux;
    float horizontal_sens, vertical_sens;
    int mouse_x, mouse_y;

    void moverAtras();
    void moverAdelante();
    void moverIzquierda();
    void moverDerecha();

    void configurarTextura(int idTextura, QString pathTextura, unsigned char* textura);
};

#endif // VISUAL_H
