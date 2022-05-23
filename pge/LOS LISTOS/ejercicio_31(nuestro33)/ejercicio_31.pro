QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ejercicio_31
TEMPLATE = app

SOURCES += main.cpp\
    medidor.cpp \
    ventana.cpp

HEADERS  += medidor.h \
    ventana.h

FORMS    += ventana.ui
