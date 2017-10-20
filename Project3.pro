TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vec3.cpp \
    system.cpp \
    particle.cpp \
    examples.cpp \
    potential.cpp \
    newtoniangravity.cpp \
    velocityverlet.cpp \
    eulercromer.cpp \
    integrator.cpp \
    initialcondition.cpp \
    twobody.cpp \
    threebody.cpp \
    tenbody.cpp \
    perihelion.cpp

HEADERS += \
    vec3.h \
    system.h \
    particle.h \
    examples.h \
    potential.h \
    newtoniangravity.h \
    velocityverlet.h \
    eulercromer.h \
    integrator.h \
    initialcondition.h \
    twobody.h \
    threebody.h \
    tenbody.h \
    perihelion.h

SUBDIRS += \
    solar-system-fys3150.pro
