#ifndef VISUAL_H
#define VISUAL_H

#include "ogl.h"
#include <math.h>
#include <QVector>
#include <QCamera>
#include <QCameraInfo>
#include <QList>
#include "capturador.h"

class Visual : public Ogl  {
    Q_OBJECT

public:
    Visual();
    void iniciarCamara();

protected:
    void initializeGL();
    void resizeGL(int ancho, int alto);
    void paintGL();

    void keyPressEvent(QKeyEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

private:
    Capturador * capturador;
    QCamera * camera;

    void cargarTexturas();
    unsigned char *textura[4];
    GLuint idTexturas[4];

    void cargarTexturaCamara();

    unsigned char *texturaCamara;
    GLuint idTexturaCamara[1];

    void timeout();

    void dibujarPlanoHorizontal(float x, float y, float z, float ancho, float profundidad, int idTexturas,
                                int repeticionX = 1, int repeticionY = 1);
    void dibujarPlanoVertical(float x, float y, float z, float ancho, float alto, int idTexturas,
                              int repeticionX = 1, int repeticionY = 1);

    float x, y, z;
    float rotacion_hacia_laterales, rotacion_arriba_abajo;
    int mouse_x, mouse_y;

    void moverAtras();
    void moverAdelante();
    void moverIzquierda();
    void moverDerecha();

    void configurarTextura(int idTextura, QString pathTextura, unsigned char* textura);
};

#endif // VISUAL_H
