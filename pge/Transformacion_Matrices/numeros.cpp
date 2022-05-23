#include "numeros.h"


Numeros::Numeros( QWidget * parent ): QLineEdit( parent )
{
    connect( this, SIGNAL( textEdited( const QString ) ), this, SLOT( slot_soloNum( const QString ) ) );
}

void Numeros::slot_soloNum( const QString string )
{
    QString newtext = string;
    for ( int i = 0; i < newtext.size(); i++ )
    {
        if ( !newtext.at( i ).isDigit() && newtext.at( i ) != '-' && newtext.at( i ) != '.' )
        {
            newtext.remove( i, 1 );
        }
    }

    this->setText( newtext );
}
