
#ifndef CALCULADORMATRICES_H
#define CALCULADORMATRICES_H


#include <QVector>

class CalculadorMatrices
{
public:    
    static CalculadorMatrices * getInstancia();

    float calcularAnguloEV( QVector< float > vector1, QVector< float > vector2 );
    float cosAngulo( float angulo );
    float senAngulo( float angulo );

    enum Matriz
    {
        RotacionX,
        RotacionY,
        RotacionZ,
        Traslacion
    };

    QVector< float > prodVecMxV ( QVector< QVector< float > > matriz, QVector< float > vector );
    QVector< QVector< float > > obtenerMatrizT ( QVector< float > vector1, QVector< float > vector2, Matriz matriz );

private:
    static CalculadorMatrices * instancia;
    CalculadorMatrices();
};

#endif // CALCULADORMATRICES_H
