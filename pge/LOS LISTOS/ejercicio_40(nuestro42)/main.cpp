#include <QApplication>
#include "visual.h"

int main(int argc, char *argv[])  {
    QApplication app(argc, argv);

    // Para ocultar el cursor
    QCursor cursor(Qt::BlankCursor);
    app.setOverrideCursor(cursor);
    app.changeOverrideCursor(cursor);

    Visual visual;
    visual.showMaximized();

    return app.exec();
}


