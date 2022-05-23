#ifndef CAPTURADOR_H
#define CAPTURADOR_H

#include <QAbstractVideoSurface>
#include <QVideoFrame>

class Capturador: public QAbstractVideoSurface
{
    Q_OBJECT

private:
    QVideoFrame frameActual;

public:
    Capturador( QObject * parent = 0 );

    bool present( const QVideoFrame & frame );
    QVideoFrame getFrameActual();
    QList<QVideoFrame::PixelFormat>supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const;
};

#endif // CAPTURADOR_H
