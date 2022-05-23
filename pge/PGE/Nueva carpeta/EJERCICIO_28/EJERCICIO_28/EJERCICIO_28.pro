QT += widgets opengl

win32:LIBS += -lopengl32
win32:LIBS += -lglu32

HEADERS += \
    escena.h

SOURCES += \
    escena.cpp \
    main.cpp
