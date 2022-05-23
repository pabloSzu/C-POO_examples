#include "calculadormatrices.h"
#include <QtMath>

CalculadorMatrices * CalculadorMatrices::instancia = nullptr;

CalculadorMatrices * CalculadorMatrices::getInstancia()
{
    if ( instancia == nullptr )
    {
        instancia = new CalculadorMatrices;
    }
    return instancia;
}

float CalculadorMatrices::calcularAnguloEV(QVector<float> vector1, QVector<float> vector2)
{
    float prodPunto = vector1.at( 0 ) * vector2.at( 0 ) + vector1.at( 1 ) * vector2.at( 1 ) + vector1.at( 2 ) * vector2.at( 2 );
    float modulo1 = sqrtf( pow( vector1.at( 0 ), 2 ) + pow( vector1.at( 1 ), 2 ) + pow( vector1.at( 2 ), 2 ) );
    float modulo2 = sqrtf( pow( vector2.at( 0 ), 2 ) + pow( vector2.at( 1 ), 2 ) + pow( vector2.at( 2 ), 2 ) );
    if ( modulo1 * modulo2 == 0 )
    {
        return ( (float)0 );
    }
    return ( qAcos( ( prodPunto / ( modulo1 * modulo2 ) ) ) );
}

float CalculadorMatrices::cosAngulo( float angulo )
{
    return ( qCos( angulo ) );
}

float CalculadorMatrices::senAngulo( float angulo )
{
    return ( qSin( angulo ) );
}

QVector<QVector< float > > CalculadorMatrices::obtenerMatrizT(  QVector< float > vector1, QVector<float> vector2, CalculadorMatrices::Matriz matriz )
{
    QVector< QVector< float > > res;
    QVector< float > aux;
    QVector< float > ejex;
    QVector< float > ejey;
    QVector< float > ejez;

    ejex << 1 << 0 << 0; //Versor unitario eje x
    ejey << 0 << 1 << 0; //Versor unitario eje y
    ejez << 0 << 0 << 1; //Versor unitario eje z

    float angulo;

    QVector< float > vector5T;
    vector5T.append( vector2.at( 0 ) );
    vector5T.append( vector2.at( 1 ) );
    vector5T.append( vector2.at( 2 ) );
    vector5T.append( 1 );

    switch ( matriz )
    {
        case RotacionX:
            vector5T = prodVecMxV( obtenerMatrizT( vector1, vector2, CalculadorMatrices::Traslacion ), vector5T );
            //Quitamos último elemento del vector para el cálculo del ángulo
            vector5T.pop_back();
            vector5T.replace( 0, 0 );

            angulo = calcularAnguloEV( ejey, vector5T );

            aux << 1 << 0 << 0 << 0;
            res.append( aux );
            aux.clear();

            aux << 0 << ( cosAngulo( angulo ) ) << ( -1 * ( senAngulo( angulo ) ) ) << 0;
            res.append( aux );
            aux.clear();

            aux << 0 << ( senAngulo( angulo ) ) << ( cosAngulo( angulo ) ) << 0;
            res.append( aux );
            aux.clear();

            break;
        case RotacionY:
            vector5T = prodVecMxV( obtenerMatrizT( vector1, vector2, CalculadorMatrices::RotacionX), prodVecMxV( obtenerMatrizT( vector1, vector2, CalculadorMatrices::Traslacion ), vector5T ) );
            vector5T.pop_back();

            vector5T.replace( 1, 0 );

            angulo = calcularAnguloEV( ejex, vector5T );

            aux << ( cosAngulo( angulo ) ) << 0 << ( senAngulo( angulo ) ) << 0;
            res.append( aux );
            aux.clear();

            aux << 0 << 1 << 0 << 0;
            res.append( aux );
            aux.clear();

            aux << ( -1 * ( senAngulo( angulo ) ) ) << 0 << ( cosAngulo( angulo ) ) << 0;
            res.append( aux );
            aux.clear();

            break;
        case RotacionZ:
            vector5T = prodVecMxV( obtenerMatrizT( vector1, vector2, CalculadorMatrices::RotacionY),
                                   prodVecMxV( obtenerMatrizT( vector1, vector2, CalculadorMatrices::RotacionX),
                                   prodVecMxV( obtenerMatrizT( vector1, vector2, CalculadorMatrices::Traslacion ), vector5T ) ) );
            vector5T.pop_back();

            vector5T.replace( 2, 0 );

            angulo = calcularAnguloEV( ejey, vector5T );

            aux << ( cosAngulo( angulo ) ) << ( -1 * ( senAngulo( angulo ) ) ) << 0 << 0;
            res.append( aux );
            aux.clear();

            aux << ( senAngulo( angulo ) ) << ( cosAngulo( angulo ) ) << 0 << 0;
            res.append( aux );
            aux.clear();

            aux << 0 << 0 << 1 << 0;
            res.append( aux );
            aux.clear();

            break;
            break;

    case Traslacion:

        aux << 1 << 0 << 0 << ( -1 * ( vector1.at( 0 ) ) ); // 1 0 0 -a
        res.append( aux );
        aux.clear();

        aux << 0 << 1 << 0 << ( -1 * ( vector1.at( 1 ) ) ); // 0 1 0 -b
        res.append( aux );
        aux.clear();

        aux << 0 << 0 << 1 << ( -1 * ( vector1.at( 2 ) ) ); // 0 0 1 -c
        res.append( aux );
        aux.clear();
        break;
    }

    aux << 0 << 0 << 0 << 1;
    res.append( aux );

    return res;
}

QVector< float > CalculadorMatrices::prodVecMxV(QVector< QVector< float > > matriz , QVector< float > vector )
{
    QVector< float > res;
    if ( matriz.size() == vector.size() )
    {
        for ( int i = 0; i < matriz.size(); i++ )
        {
            float sum = 0;
            for ( int j = 0; j < matriz.at( 0 ).size(); j++ )
            {
                sum = sum + ( matriz.at( i ).at( j ) * vector.at( j ) );
            }
            res.append( sum );
        }
    }

    return res;
}

CalculadorMatrices::CalculadorMatrices()
{
}
