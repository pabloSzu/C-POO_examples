#ifndef NUMEROS_H
#define NUMEROS_H

#include <QLineEdit>

class Numeros : public QLineEdit
{
    Q_OBJECT
public:
    Numeros( QWidget * parent = nullptr );

private slots:
    void slot_soloNum( const QString );
};

#endif // NUMEROS_H
