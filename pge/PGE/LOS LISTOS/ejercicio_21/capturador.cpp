#include "capturador.h"

Capturador::Capturador( QObject * parent ) : QAbstractVideoSurface( parent ) {

}

bool Capturador::present( const QVideoFrame & frame ) {
    frameActual = frame;  //porque es const
    frameActual.map( QAbstractVideoBuffer::ReadOnly );

    return true;
}

QVideoFrame Capturador::getFrameActual()  {
    return frameActual;
}

QList<QVideoFrame::PixelFormat> Capturador::supportedPixelFormats(
        QAbstractVideoBuffer::HandleType handleType ) const
{
        if ( handleType == QAbstractVideoBuffer::NoHandle )  {
            return QList<QVideoFrame::PixelFormat>() << QVideoFrame::Format_RGB32
                                                     << QVideoFrame::Format_ARGB32;
        }
        else  {
            return QList<QVideoFrame::PixelFormat>();
        }
}
