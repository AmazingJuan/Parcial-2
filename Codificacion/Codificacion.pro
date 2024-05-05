TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Sources/estacion.cpp \
        Sources/linea.cpp \
        Sources/menus.cpp \
        Sources/red.cpp \
        Sources/utilidades.cpp \
        Sources/validacion.cpp \
        main.cpp

HEADERS += \
    Headers/estacion.h \
    Headers/importaciones.h \
    Headers/linea.h \
    Headers/lista.h \
    Headers/menus.h \
    Headers/nodo.h \
    Headers/red.h \
    Headers/utilidades.h \
    Headers/validacion.h
