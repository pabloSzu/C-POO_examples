TEMPLATE = app

QT += multimedia widgets opengl

#unix:LIBS += -lGLU

#win32:LIBS += -lopengl32
#win32:LIBS += -lglu32

HEADERS += \
    ogl.h \
    visual.h

SOURCES += \
    main.cpp \
    ogl.cpp \
    visual.cpp
