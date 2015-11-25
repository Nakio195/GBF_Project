#-------------------------------------------------
#
# Project created by QtCreator 2015-09-30T22:23:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetGBF
TEMPLATE = app


SOURCES += main.cpp \
    IHM\GBF_IHM.cpp \
    Signaux\GBF_Signal.cpp \
    Signaux/GBF_SquareWave.cpp \
    Signaux/GBF_TriangleWave.cpp \
    Generator/GBF_Generator.cpp \
    Signaux/GBF_CosinusWave.cpp \
    Signaux/GBF_SinusWave.cpp \
    IHM/GBF_IHM_Export.cpp

HEADERS  += \
    IHM\GBF_IHM.h \
    Signaux\GBF_Signal.h \
    Signaux/GBF_SquareWave.h \
    Signaux/GBF_TriangleWave.h \
    Generator/GBF_Generator.h \
    Signaux/GBF_CosinusWave.h \
    Signaux/GBF_SinusWave.h \
    IHM/GBF_IHM_Export.h

FORMS    += \
    IHM\GBF_IHM.ui \
    IHM/GBF_IHM_Export.ui
