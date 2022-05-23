#include <QApplication>
#include <QDebug>

void funcion(std::type_info info) {
    qDebug() << info.name();
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    qDebug() << typeid(int).name();

    int x = 10;

    qDebug() << typeid(x).name();

    const std::type_info & ref = typeid(int);

    qDebug() << ref.name();

    funcion(ref);   //el constructor copia es privado y por eso el programa no compila

    return a.exec();
}

